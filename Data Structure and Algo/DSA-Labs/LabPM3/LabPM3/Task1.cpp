//#include "iostream"
//
//using namespace std;
//
//int DigestNo(int No) {
//	int Res = 0;
//	if (No == 0)
//		return 0;
//	Res += No % 10 + DigestNo(No / 10);
//	if (Res < 10)
//		return Res;
//	else
//		DigestNo(Res);
//}
//
//int main() {
//	cout << DigestNo(555) << '\n';
//	system("PAUSE");
//	return 0;
//}