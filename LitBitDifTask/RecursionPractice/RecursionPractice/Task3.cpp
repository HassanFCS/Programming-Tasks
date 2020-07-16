//#include "iostream"
//#include "string"
//#include "string.h"
//using namespace std;
//
//int ReturnNo(char C) {
//	switch (C) {
//	case '0' :
//		return 0;
//	case '1':
//		return 1;
//	case '2':
//		return 2;
//	case '3':
//		return 3;
//	case '4':
//		return 4;
//	case '5':
//		return 5;
//	case '6':
//		return 6;
//	case '7':
//		return 7;
//	case '8':
//		return 8;
//	case '9':
//		return 9;
//	}
//}
//
//int Power(int N, int P) {
//	int Res = 1;
//	if (P == 0)
//		return 1;
//	return Res = N*Power(N, P - 1);
//}
//
////Using Loop
//int StoI(string S, int Size) {
//	int FValue = 0;
//	for (int i = 0; i < Size; i++) {
//		int Val = ReturnNo(S[i]);
//		Val *= Power(10, Size - 1 - i);
//		FValue += Val;
//	}
//	return FValue;
//}
////Using Recrsion
//int StrToInt(string S, int Size,int OSize) {
//	if (Size == 0)
//		return 0;
//	int Val = ReturnNo(S[OSize - Size]);
//	Val *= Power(10, Size-1);
//	return Val += StrToInt(S, Size - 1, OSize);
//}
//
//int main() {
//	string S,S1;
//	cin >> S;
//	cin >> S1;
//	cout << StrToInt(S, S.length(), S.length()) + StrToInt(S1, S1.length(), S1.length()) << '\n';//Using Recursion
//	cout << StoI(S, S.length()) + StoI(S1, S1.length()) << '\n';//Using Loop
//	return 0;
//}