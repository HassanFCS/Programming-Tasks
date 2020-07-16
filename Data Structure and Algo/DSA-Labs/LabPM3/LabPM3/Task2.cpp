//#include "iostream"
//
//using namespace std;
//
//int RightSubTree(int A[], int Size, int Start);
//int LeftSubTree(int A[], int Size, int Start) {
//	int Res = 0;
//	if (Size < Start || A[Start] == -1)
//		return 0;
//	int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
//	int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
//	if (Res1 < Res2)
//		return Res2;
//	else
//		return Res1;
//}
//
//int RightSubTree(int A[], int Size, int Start) {
//	if (Size < Start || A[Start] == -1)
//		return 0;
//	int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
//	int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
//	if (Res1 < Res2)
//		return Res2;
//	else
//		return Res1;
//}
//
//int HeightofTree(int A[], int Size,int Start) {
//	if (A[Start] == -1)
//		return 0;
//	int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
//	int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
//	if (Res1 < Res2)
//		return Res2;
//	else
//		return Res1;
//}
//
//int HeightofTree(int A[], int Size) {
//	return HeightofTree(A, 15, 0);
//}
//
//int main() {
//	int A[15] = { 1,2,3,4,5,-1,8,-1,-1,-1,-1,-1,13,-1,-1};
//	cout << HeightofTree(A, 15);
//	system("PAUSE");
//	return 0;
//}