#include "iostream"
#include "string"
using namespace std;


class LexicalAnalyzer{
	string Str;

	bool IsAlpha(char Test){
		if ((Test >= 65 && Test <= 90) || (Test >= 97 && Test <= 122) || Test=='_')
			return true;
		return false;
	}

	bool IsNumber(char Test){
		if (Test >= 48 && Test <= 57)
			return true;
		return false;
	}

	void Print(int Start, int End){
		for (Start; Start <= End; Start++)
			cout << Str[Start];
	}



public:

	LexicalAnalyzer(string String){
		this->Str = String;
	}

	void PrintResult(){
		int Start = 0, End;
		int i = 0;
		while (i < Str.length()){
			End = Start;
			if (IsAlpha(Str[End])){
				while (IsAlpha(Str[End]) || IsNumber(Str[End])){
					End++;
				}
				End--;//As Identifier end before value of End at this time
				cout << "<Identifier , ";
				Print(Start, End);
				cout << " >\n";
			}
			else if(IsNumber(Str[End])){
				while (IsNumber(Str[End])){
					End++;
				}
				End--;//As Number end before value of End at this time
				cout << "<Number , ";
				Print(Start, End);
				cout << " >\n";
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


//				true		false
//
//IsAlpha	  IsAlpha	   Judge(IsNumber or Error)
//
//IsNumber	  IsNumber	   Judge(IsAlpha or Error)
//
//Error		  Error		   Judge(IsNumber or IsAlpha)


int main(){
	string String;
	cout << "Enter String : ";
	getline(cin, String);
	LexicalAnalyzer Str(String);
	Str.PrintResult();
	system("PAUSE");
	return 0;
}