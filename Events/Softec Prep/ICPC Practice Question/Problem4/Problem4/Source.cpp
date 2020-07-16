#include "iostream"
#include "string"
#include "string.h"
using namespace std;

void Print(string Str1, string Str2){
	int i = 0;
	int Count = 0;
	do{
		if (Str1[i] != Str2[0])
			cout << Str1[i];
		else{
			for (int j = 0; j < Str2.length(); i++, j++){
				if (Str1[i] == Str2[j])
					Count++;
			}
			if (Count == Str2.length())
				cout << '\n';
			else{
				i = i - (Str2.length());
				int j = i;
				for (i; i < j + Str2.length(); i++)
					cout << Str1[i];
			}
			Count = 0;
			i--;
		}
		i++;
	} while (Str1[i]!='\0');
}

int main(){
	string S1 = "t";
	string S2 = "This is the sample task which we have to tokenized";
	Print(S2, S1);
	cout << "\n\n";
	S1 = "th";
	S2 = "This is the sample thask which we have tho thokenized";
	Print(S2, S1);
	cout << "\n\n";
	S1 = "abc";
	S2 = "abcd efgh abdef ghk abclmn abopqr abcxyz";
	Print(S2, S1);
	cout << '\n';
	system("PAUSE");
	return 0;
}