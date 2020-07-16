#include "iostream"
#include "string"
#include "string.h"
using namespace std;

void StrPer(string Str,int Start,int End) {
	if (Start > End)
		return;
	if (Start == End-1)
		cout << Str << '\n';
	for (int i = Start; i < End; i++) {
		swap(Str[i], Str[Start]);
		StrPer(Str, Start+1, End);
	}
}

int main() {
	string S = "ABC";
	StrPer(S, 0, S.length());
	return 0;
}