#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;

class LexicalAnalyzer{
	string Str;
	char LS;
	char SS;
	string WA;
	int AcceptingIndex;
	map<char, vector<char>> TT;
	void Print(int Start, int End){
		for (Start; Start <= End; Start++)
			cout << Str[Start];
	}
	bool IsExist(char ch){
		for (int i = 0; i < WA.length(); i++){
			if (WA[i] == ch)
				return true;
		}
		return false;
	}
	bool IsAlpha(char ch){
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
			return true;
		return false;
	}
	bool IsSpace(char ch){
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\r')
			return true;
		return false;
	}
	bool IsNumber(char ch){
		if ((ch >= 48 && ch <= 57) || ch == '.' || ch == 'e' || ch == 'E')
			return true;
		return false;
	}
	int RetCol(char L){
		if (L == '.')
			return 2;
		if (L == 'e' || L == 'E')
			return 1;
		else if (IsNumber(L))
			return 0;
		if (L == '_')
			return 6;
		else if (IsAlpha(L))
			return 5;
		else if (IsSpace(L))
			return 4;
		else
			return 5;
	}
public:

	LexicalAnalyzer(string String){
		this->AcceptingIndex = 3;
		this->SS = 'S';
		this->LS = 'S';
		this->Str = String;
		this->WA = " QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789._";
		this->TT['S'] = vector<char>({ 'A', 'T', 'C', '0', 'G', 'F', 'F' });
		this->TT['A'] = vector<char>({ 'A', 'D', 'B', 'N', 'T', 'T', 'T' });
		this->TT['B'] = vector<char>({ 'B', 'D', 'T', 'P', 'T', 'T', 'T' });
		this->TT['C'] = vector<char>({ 'B', 'T', 'T', '0', 'T', 'T', 'T' });
		this->TT['D'] = vector<char>({ 'E', 'T', 'T', '0', 'T', 'T', 'T' });
		this->TT['E'] = vector<char>({ 'E', 'T', 'T', 'E', 'T', 'T', 'T' });
		this->TT['F'] = vector<char>({ 'F', 'F', 'T', 'I', 'T', 'F', 'F' });
		this->TT['G'] = vector<char>({ 'T', 'T', 'T', 'S', 'G', 'T', 'T' });
		this->TT['T'] = vector<char>({ 'T', 'T', 'T', 'T', 'T', 'T', 'T' });
	}

	void PrintResult(){
		int Start = 0, End;
		int i = 0;
		while (i < Str.length()) {
			End = Start;
			if (IsExist(Str[End])){
				SS = 'S';
				for (; SS != 'T' && End < Str.length(); End++){
					LS = SS;
					if (RetCol(Str[End]) != 5)
						SS = TT[SS][RetCol(Str[End])];
					else
						SS = 'T';
				}
				if (End<Str.length())
					End -= 2;		//As Number end before value of End at this time
				if (TT[LS][AcceptingIndex] == 'N')
					cout << "<Integer , ";
				else if (TT[LS][AcceptingIndex] == 'P')
					cout << "<Point, ";
				else if (TT[LS][AcceptingIndex] == 'E')
					cout << "<Exponentional Number, ";
				else if (TT[LS][AcceptingIndex] == 'I')
					cout << "<Identifier, ";
				else if (TT[LS][AcceptingIndex] == 'S')
					cout << "<Space, ";
				else
					cout << "<Partial String, ";
				Print(Start, End);
				cout << " >\n";
			}
			else{
				cout << "<Error , ";
				Print(Start, End);
				cout << " >\n";
			}
			i = End + 1;
			Start = i;		//Now String must be Start after End
		}
	}
};



int main(){
	string N;
	getline(cin, N);
	LexicalAnalyzer Str(N);
	Str.PrintResult();
	system("PAUSE");
	return 0;
}