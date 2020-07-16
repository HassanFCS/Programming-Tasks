#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include<conio.h>
#include <string>
#include <stack>
using namespace std;

struct Transition
{
	vector<string> TEs;
};

class Production
{
public :
	string name;

	vector<Transition> Ts;
	set<string> Firsts;
	set<string> Follows;
	Production(string n)
	{
		name = n;
	}
};

class Grammar
{
	string Start;
	vector<Production> Ps;
	map<string, string> Terminals;
	map<string, Production*>nonTerminals;
	string nullterminal = "^";
	map <string, map<string, int>> ParseTable;

	bool IsTerminal(string element)
	{
		return (Terminals.find(element) != Terminals.end());
	}
	bool IsNonTerminal(string element)
	{
		return (nonTerminals.find(element) != nonTerminals.end());
	}
	bool IsNull(string element)
	{
		return element == nullterminal;
	}
	bool ContainsNull(set<string> & S)
	{
		return S.find(nullterminal) != S.end();
	}
	bool UnionSetAndTerminal(set<string> & S, string element)
	{
		if (S.find(element) != S.end())
			return false;
		S.insert(element);
		return true;
	}
	bool UnionSets(set<string> & S1, set<string> & S2)
	{
		set <string> CopyofS1 = S1;
		int S1Size = S1.size();
		S1.insert(S2.begin(), S2.end());
		CopyofS1.insert(nullterminal);
		if (S1 == CopyofS1)
			return false;
		return S1Size != S1.size();
	}
	bool UnionSetsWithoutNULL(set<string> & S1, set<string> & S2)
	{
		int S1Size = S1.size();
		S1.insert(S2.begin(), S2.end());
		if (S1.find(nullterminal)!=S1.end())
			S1.erase(nullterminal);
		return S1Size != S1.size();
	}
	Production* ProductionOf(string element)
	{
		return nonTerminals[element];
	}


public:
	Grammar(string gfname)
	{
		int Size;
		ifstream fin(gfname);
		fin >> Size;
		string aterm;
		for (int i = 0; i < Size; i++)
		{
			fin >> aterm;
			Terminals[aterm] = aterm;
		}
		fin >> Size;

		for (int i = 0; i < Size; i++)
		{
			fin >> aterm;
			Production* aprod = new Production(aterm);
			nonTerminals[aterm] = aprod;
		}
		fin >> Start;
		for (int i = 0; i < nonTerminals.size(); i++)
		{
			fin >> aterm;
			Production* aprod = nonTerminals[aterm];
			fin >> aterm;   // ignore ->

			while (fin.peek() != '\n' && fin.peek() != EOF)
			{
				Transition atrans;
				fin >> aterm;
				while (aterm != "|")
				{
					atrans.TEs.push_back(aterm);

					if (fin.peek() == '\n' || fin.peek() == EOF)
						break;
					fin >> aterm;
				}
				aprod->Ts.push_back(atrans);
			}
		}
	}
	void printGrammer()
	{
		cout << "Grammar\n";
		for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++)
		{
			cout << itr->first << "	->	";
			for (int i = 0; i < itr->second->Ts.size(); i++)
			{
				for (int j = 0; j < itr->second->Ts[i].TEs.size(); j++)
				{
					cout << itr->second->Ts[i].TEs[j] << " ";
				}
				if (i + 1 != itr->second->Ts.size())
					cout << "	|	";
			}
			cout << endl;
		}
	}
	void DisplayFirstSet()
	{
		cout << "First Sets\n";
		for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++){
			cout << itr->first << " : ";
			for (auto Set = itr->second->Firsts.begin(); Set != itr->second->Firsts.end(); Set++){
				cout << *Set << " ";
			}
			cout << '\n';
		}
	}
	void DisplayFollowSet()
	{
		cout << "Follow Sets\n";
		for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++){
			cout << itr->first << " : ";
			for (auto Set = itr->second->Follows.begin(); Set != itr->second->Follows.end(); Set++){
				cout << *Set << " ";
			}
			cout << '\n';
		}
	}

	void DisplayParseTable(){

		cout << "\t\t";
		for (auto t = Terminals.begin(); t != Terminals.end(); t++)
		{
			if (IsNull(t->first))
			{
				continue;	// print nothing...
			}
			cout << t->first << "\t";
		}
		cout << endl;
		for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++)
		{

			cout << itr->first << "\t\t";
			for (auto t = Terminals.begin(); t != Terminals.end(); t++)
			{
				if (IsNull(t->first))
				{
					continue;	// print nothing...
				}

				if (ParseTable[itr->first].find(t->first) != ParseTable[itr->first].end())
				{
					cout << ParseTable[itr->first][t->first]<<"\t";
				}
				else
				{
					cout << "-1\t";
				}
			}
			cout << "\n";
		}
	}

	void ComputeFirstSet()
	{
		bool changehappen = true;
		while (changehappen)
		{
			changehappen = false;
			for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++)
			{
				bool NullMustExist = false;
				for (int i = 0; i < itr->second->Ts.size(); i++)
				{
					Transition& atr = itr->second->Ts[i];
					bool AmIatEnd = false;
					for (int k = 0; k < atr.TEs.size(); k++)
					{
						if (k == atr.TEs.size() - 1){
							AmIatEnd = true;
						}
						string element = atr.TEs[k];
						if (IsTerminal(element))
						{
							if (itr->second->Firsts.find(element) == itr->second->Firsts.end())
							{
								itr->second->Firsts.insert(element);
								changehappen = true;
							}
							else
							{
								changehappen = false;
							}
							break;
						}
						else
						{
							changehappen = UnionSets(itr->second->Firsts, ProductionOf(element)->Firsts) || changehappen;
							if (!ContainsNull(ProductionOf(element)->Firsts))
								break;
						}
						if (!AmIatEnd && !NullMustExist)
						{
							if (itr->second->Firsts.find(nullterminal) != itr->second->Firsts.end())
								itr->second->Firsts.erase(nullterminal);
						}
						if (AmIatEnd){
							if (itr->second->Firsts.find(nullterminal) != itr->second->Firsts.end())
								NullMustExist = true;
						}
					}
				}
			}
		}
	}

	void ComputeFollowSet(){
		auto itr = nonTerminals.find(Start);
		itr->second->Follows.insert("$");
		bool changehappen = true;
		while (changehappen)
		{
			changehappen = false;
			for (auto NT = nonTerminals.begin(); NT != nonTerminals.end(); NT++)	// for each Non terminal production
			{
				Production* prod = NT->second;
				for (auto atrans = prod->Ts.begin(); atrans != prod->Ts.end(); atrans++)
				{
					for (int i = 0; i < atrans->TEs.size(); i++)
					{
						string telement = atrans->TEs[i];
						if (!IsTerminal(telement))
						{
							bool AmIAtEnd = true;
							Production* FSetOfProd = nonTerminals[telement];  // The production in which we have to add follow set
							for (int j = i + 1; j < atrans->TEs.size(); j++)
							{
								telement = atrans->TEs[j];
								if (IsTerminal(telement))
								{
									changehappen = UnionSetAndTerminal(FSetOfProd->Follows, telement) || changehappen;
									AmIAtEnd = false;
									break;
								}
								else
								{
									changehappen = UnionSetsWithoutNULL(FSetOfProd->Follows, nonTerminals[telement]->Firsts) || changehappen;
									if (!ContainsNull(nonTerminals[telement]->Firsts))
									{
										AmIAtEnd = false;
										break;
									}
								}
							}
							if (AmIAtEnd)
							{
								changehappen = UnionSets(FSetOfProd->Follows, prod->Follows) || changehappen;
							}
						}
					}
				}
				
			}
		}
	}

	int TransitionIndexForFirstElement(Production* p, string f)
	{
		for (int i = 0; i < p->Ts.size(); i++)
		{
			for (int te = 0; te < p->Ts[i].TEs.size(); te++)
			{
				if (IsTerminal(p->Ts[i].TEs[te]) && f == p->Ts[i].TEs[te])
				{
					return i;
				}
				else if (IsTerminal(p->Ts[i].TEs[te]) && f != p->Ts[i].TEs[te])
				{
					break;
				}
				// Writing the f to be null before the non -null cases as null element has special way to check
				else if (IsNull(f) && ProductionOf(p->Ts[i].TEs[te])->Firsts.find(f) != ProductionOf(p->Ts[i].TEs[te])->Firsts.end() && te != p->Ts[i].TEs.size() - 1)   // for Non Terminal Case
				{
					continue;   // we have found the ^ in the te->firstSet
				}
				else if (IsNull(f) && ProductionOf(p->Ts[i].TEs[te])->Firsts.find(f) != ProductionOf(p->Ts[i].TEs[te])->Firsts.end() && te == p->Ts[i].TEs.size() - 1)   // for Non Terminal Case
				{
					return i;   // we have found the ^ in the te->firstSet
				}
				else if (IsNull(f) && ProductionOf(p->Ts[i].TEs[te])->Firsts.find(f) == ProductionOf(p->Ts[i].TEs[te])->Firsts.end())   // f not found and first set doesn't contain null... then it can't be the transition
				{
					break;      // 
				}

				else if (ProductionOf(p->Ts[i].TEs[te])->Firsts.find(f) != ProductionOf(p->Ts[i].TEs[te])->Firsts.end())   // for Non Terminal Case
				{
					return i;   // we have found the transition
				}
				else if (!ContainsNull(ProductionOf(p->Ts[i].TEs[te])->Firsts))   // f not found and first set doesn't contain null... then it can't be the transition
				{
					break;
				}
				else
				{
					// Continue for checking the next transition element as the te->firstset contains null
				}
			}
		}

		return -1;	// this will never run, just for removing the stupid warning 
	}

	void InitParseTable(){
		for (auto itr = nonTerminals.begin(); itr != nonTerminals.end(); itr++)
		{
			Production* p = itr->second;
			// for each f in first set	
			for (auto f = p->Firsts.begin(); f != p->Firsts.end(); f++)
			{
					int i = TransitionIndexForFirstElement(p, *f);
					if (IsNull(*f))
					{
						for (auto fl = p->Follows.begin(); fl != p->Follows.end(); fl++)
						{
							ParseTable[itr->first][*fl] = i;
						}
					}
					else
					{
						ParseTable[itr->first][*f] = i;
					}
			}
		}
		
	}

	bool ParseDocument(string path)
	{
		ifstream fin(path);  // This input will be from Lexical Analyzer

		string token;
		stack<string> S;
		S.push("$");
		S.push(Start);	// pushing the start production...!!!
		while (fin >> token)
		{
			do
			{
				string topEntry = S.top(); S.pop();
				if (topEntry == token)
				{
					break;
				}
				else if (IsTerminal(topEntry))
				{
					// Error found...
					cout << "Compilation Error... ! " << endl;
					return false;
				}
				else
				{
					if (ParseTable[topEntry].find(token) == ParseTable[topEntry].end())
					{
						// Error found...
						cout << "Compilation Error... ! " << endl;
						return false;
					}
					else
					{
						vector<string> Transition = ProductionOf(topEntry)->Ts[ParseTable[topEntry][token]].TEs;
						for (int i = Transition.size() - 1; i >= 0; i--)
						{
							if (IsNull(Transition[i]) == false)
								S.push(Transition[i]);
						}
					}
				}
			} 
			while (true);
		}

		cout << "Compilation Successful... !!!";

		return true;
	}

};

int main(){
	Grammar G1("Data10.txt");
	G1.printGrammer();
	cout << "\n";
	G1.ComputeFirstSet();
	G1.DisplayFirstSet();
	cout << "\n";
	G1.ComputeFollowSet();
	G1.DisplayFollowSet();
	cout << "\n";
	G1.InitParseTable();
	G1.DisplayParseTable();
	G1.ParseDocument("TC10F.txt");
	system("PAUSE");
	return 0;
}