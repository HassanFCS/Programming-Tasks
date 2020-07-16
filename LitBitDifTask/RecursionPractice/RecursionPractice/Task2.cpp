//#include "iostream"
//using namespace std;
//
//int Ackermann(int M, int N) {
//	if (N >= 0 && M == 0)
//		return N + 1;
//	else if (M > 0 && N == 0)
//		return Ackermann(M - 1, 1);
//	else
//		return Ackermann(M - 1, Ackermann(M, N - 1));
//}
//
//int main() {
//	cout << Ackermann(0, 9) << '\n';
//	cout << Ackermann(1, 8) << '\n';
//	cout << Ackermann(2, 2) << '\n';
//	cout << Ackermann(2, 0) << '\n';
//	cout << Ackermann(2, 3) << '\n';
//	cout << Ackermann(3, 2) << '\n';
////	cout << Ackermann(4, 2) << '\n';
////	cout << Ackermann(4, 3) << '\n';
////	cout << Ackermann(5, 1) << '\n';
//	cout << Ackermann(4, 0) << '\n';
//	cout << Ackermann(0, 0) << '\n';
//	return 0;
//}