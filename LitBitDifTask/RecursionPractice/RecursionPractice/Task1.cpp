//#include "iostream"
//using namespace std;
//
//int FPower(int N, int P) {
//	int Res = 1;
//	if (P == 0)
//		return 1;
//	Res = FPower(N, P / 2);
//	if (P % 2 == 0)
//		return Res *= Res;
//	else
//		return Res *= N*Res;
//}
//
//int main() {
//	cout << FPower(3, 8) << '\n';
//	return 0;
//}