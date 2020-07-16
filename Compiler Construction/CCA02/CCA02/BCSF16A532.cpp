#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct TT{
	char State;
	vector <set<char>> NState;
	bool IsAccepting;
	TT(){

	}
	TT(int CofCS){
		NState.resize(CofCS);
	}
};

class NFA_Automata{
	vector <TT> TT;
	string WA;
	char SS;
	string SA;
	queue <string> Solution;
public : 
	int WAIndex(char Alpha){
		for (int i = 0; i < WA.length(); i++){
			if (WA[i] == Alpha)
				return i;
		}
		return -1;
	}
	int SIndex(char C){
		return C - 65;
	}
	bool StringAcceptable(string InputString){
		set <char> CS;
		CS.insert(SS);
		string cs = {SS};//&SS;
		Solution.push(cs);
		for (int i = 0; i < InputString.length(); i++){
			set <char> NS;
			int Ind = WAIndex(InputString[i]);
			if (Ind == -1){
				cout << "Invalid String";
				system("PAUSE");
				exit(0);
			}
			else{
				for (auto j = CS.begin(); j != CS.end(); j++){
					if (*j != 'T'){
						string Str = Solution.front();
						Solution.pop();
						set<char> ToInsert = TT[SIndex(*j)].NState[WAIndex(InputString[i])];
						NS.insert(ToInsert.begin(), ToInsert.end());
						for (auto k = ToInsert.begin(); k != ToInsert.end() && *k != 'T'; k++)
							Solution.push(Str + *k);
					}
				}
				CS = NS;
			}
		}
		for (auto j = CS.begin(); j != CS.end(); j++){
			if (*j == 'D')
				return true;
		}
		return false;
	}
	void Read(){
		ifstream fin("Data.txt");
		int NofStates;
		string Str;
		fin >> NofStates;
		TT.resize(NofStates);
		for (int i = 0; i < NofStates; i++){
			fin >> Str;
			SA += Str[0];
		}
		int NoWS;
		fin >> NoWS;
		for (int i = 0; i < NoWS; i++){
			fin >> Str;
			WA += Str[0];
		}
		for (int i = 0; i < TT.size(); i++){
			fin >> Str; // State
			TT[i].State = Str[0];
			TT[i].NState.resize(WA.size());
			for (int k = 0; k < WA.size(); k++)
			{
				fin >> Str;
				for (int j = 0; j < Str.size(); j++){
					TT[i].NState[k].insert(Str[j]);
				}
			}
			fin >> TT[i].IsAccepting;
		}
		fin >> Str;
		SS = Str[0];
	}
	void PrintSolution(){
		while (!Solution.empty()){
			cout << Solution.front() << '\n';
			Solution.pop();
		}
	}
	void Print(){
		cout << "Working States : " << SA.length() << ' ';
		for (int i = 0; i < SA.length(); i++)
			cout << SA[i] << ' ';
		cout << '\n';
		cout << "Working Alphabets : " << WA.length() << ' ';
		for (int i = 0; i < WA.length(); i++)
			cout << WA[i] << ' ';
		cout << '\n';
		for (int i = 0; i < TT.size(); i++){
			cout << TT[i].State << ' ';
			for (int k = 0; k < WA.size(); k++){
				cout << setw(5) << " ";
				copy(TT[i].NState[k].begin(), TT[i].NState[k].end(), std::ostream_iterator<char>(cout, " "));
			}
			cout << "\t" << TT[i].IsAccepting << '\n';
		}
		cout << SS << '\n';
	}
};

int main(){
	NFA_Automata TransitionTable;
	TransitionTable.Read();
	TransitionTable.Print();
	string Str;
	cin >> Str;
	if (TransitionTable.StringAcceptable(Str))
		cout << "String Accepted\n";
	else
		cout << "String Rejected\n";
	TransitionTable.PrintSolution();
	system("PAUSE");
	return 0;
}