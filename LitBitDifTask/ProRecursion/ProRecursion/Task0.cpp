//#include "iostream"
//
//using namespace std;
//
//int Fac(int N) {
//	if (N <= 1)
//		return 1;
//	return N*Fac(N - 1);
//}
//
//int nPr(int N, int R) {
//	return (Fac(N) / Fac(N - R));
//}
//
//int Com(int N, int K) {
//	if (K == 0 || K == N)
//		return 1;
//	return Com(N - 1, K - 1) + Com(N - 1, K);
//}
//
//int main() {
//	cout << nPr(7, 1) << '\n';
//	cout << nPr(0, 0) << '\n';
//	cout << nPr(5, 3) << '\n';
//	cout << Com(5, 3) << '\n';
//	cout << Com(4, 1) << '\n';
//	return 0;
//}