#include "iostream"
#include "string"
#include "conio.h"
#include "map"
#include "vector"
using namespace std;

bool IsAccept(char LS){
	if (LS == 'A' || LS == 'B' || LS == 'E' || LS == 'D' || LS == 'G')
		return true;
	else
		return false;
}



int main(){
	map<char, vector<char> > TT;
	TT['A'] = vector<char>({ 'B', 'E' });
	TT['B'] = vector<char>({ 'B', 'C' });
	TT['C'] = vector<char>({ 'D', 'C' });
	TT['D'] = vector<char>({ 'D', 'C' });
	TT['E'] = vector<char>({ 'F', 'E' });
	TT['F'] = vector<char>({ 'F', 'G' });
	TT['G'] = vector<char>({ 'F', 'G' });
	char SS = 'A';
	string Input;
	Input = _getch();
	cout << Input;
	if (Input == "\r"){
		cout << "\n\n\n" << SS << "\n\nAccepted\n\n";
	}
	else{
		char ch = _getch();
		while (ch != '\r'){
			cout << ch;
			Input += ch;
			ch = _getch();
			if(ch!='0' && ch!='1'){
				cout << ch << "\nInvalid String";
				system("PAUSE");
				exit(0);
			}
		}
		cout << "\n\n\n";
		int i = 0;
		while (i < Input.length()){
			cout << SS << ' ';
			char SI = Input[i];
			int ind = (SI == '0' ? 0 : 1);
			SS = TT[SS][ind];
			i++;
		}
		cout << SS << ' ';
		if (IsAccept(SS))
			cout << "\n\nAccepted\n\n";
		else
			cout << "\n\nRejected\n\n";
	}
	system("PAUSE");


	return 0;
}