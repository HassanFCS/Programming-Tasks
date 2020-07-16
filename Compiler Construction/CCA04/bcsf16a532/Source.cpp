#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;

class LexicalAnalyzer{
	string Str;
	char SS;
	string WA;
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
	}
public:

	LexicalAnalyzer(string String){
		this->SS = 'S';
		this->Str = String;
		this->WA = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm0123456789._";
		this->TT['S'] = vector<char>({ 'A', 'T', 'C' });
		this->TT['A'] = vector<char>({ 'A', 'E', 'B' });
		this->TT['B'] = vector<char>({ 'B', 'E', 'T' });
		this->TT['C'] = vector<char>({ 'D', 'T', 'T' });
		this->TT['D'] = vector<char>({ 'D', 'E', 'T' });
		this->TT['E'] = vector<char>({ 'F', 'T', 'T' });
		this->TT['F'] = vector<char>({ 'F', 'T', 'T' });
		this->TT['T'] = vector<char>({ 'T', 'T', 'T' });
	}

	void PrintResult(){
		int Start = 0, End;
		int i = 0;
		while (i < Str.length()){
			End = Start;
			if (IsExist(Str[End])){
				if (IsAlpha(Str[End])){
					while ((IsAlpha(Str[End]) || IsNumber(Str[End])) && Str[End]!='.'){
						End++;
					}
					End--;//As Identifier end before value of End at this time
					cout << "<Identifier , ";
					Print(Start, End);
					cout << " >\n";
				}
				else if (IsNumber(Str[End])){
					SS = 'S';
					for (; SS != 'T'; End++){
						SS = TT[SS][RetCol(Str[End])];
						if (!IsNumber(Str[End])){
							SS = 'T';
							if (Str[End - 1] == 'e' || Str[End - 1] == 'E')
								End--;
						}
					}
					End -= 2;//As Number end before value of End at this time
					cout << "<Number , ";
					Print(Start, End);
					cout << " >\n";
				}
			}
			else{
				cout << "<Error , ";
				Print(Start, End);
				cout << " >\n";
			}
			i = End + 1;
			Start = i; //Now String must be Start after End
		}
	}
};



int main(){
	string N;
	cin >> N;
	LexicalAnalyzer Str(N);
	Str.PrintResult();
	system("PAUSE");
	return 0;
}