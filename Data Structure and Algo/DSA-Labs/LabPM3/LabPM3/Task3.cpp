//#include "iostream"
//
//using namespace std;
//
//int MaxSubSequence(int A[], int Size, int Start,int &Max) {
//
//	int Count = 0;
//	if (Start > Size/2)//2 1 1 999
//		return -1;
//	for (int j = 2; j < Size; j++) {
//		for (int i = Start; i < Size; i += j)
//			Count += A[i];
//		if (Max < Count) {
//			Max = Count;
//		}
//		Count = 0;
//	}
//	if (MaxSubSequence(A, Size, Start + 1, Max) == -1)
//		return Max;
//}
//int MaxSubSequence(int A[], int Size) {
//	int Max = 0;
//	return MaxSubSequence(A, Size, 0,Max);
//}
//int main() {
//	int A[6] = { 1,2,3,11,15,17 };
//	int B[6] = { 1,999,2,25,1001,1 };
//	int C[8] = { 1,2,3,4,5,6,7,8 };
//	int D[] = { 0,1,0,999};
//	int s = sizeof(D) / sizeof(D[0]);
//	cout << MaxSubSequence(B, 6) << '\n';
//	return 0;
//}