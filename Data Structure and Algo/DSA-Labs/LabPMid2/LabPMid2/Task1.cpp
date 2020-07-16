#include "iostream"

using namespace std;

//void MRight(int A[], int Size) {
//	int temp = A[0];
//	for (int i = 0; i < Size - 1; i++) {
//		A[i] = A[i + 1];
//	}
//	A[Size - 1] = temp;
//}

void PrintArray(int A[], int Size) {
	for (int i = 0; i < Size; i++)
		cout << A[i] << ' ';
	cout << '\n';
}

void ArrayPer(int A[], int Size, int Start) {
	if (Start == Size)
		PrintArray(A, Size);
	for (int i = Start; i < Size; i++) {
		swap(A[i], Start);
		ArrayPer(A, Size, Start++);
		swap(A[i], Start);
	}
}

bool EqualSum(int A[], int B[], int Size1, int Size2) {
	int Sum1 = 0, Sum2 = 0;
	for (int i = 0; i < Size1; i++)
		Sum1 += A[i];
	for (int i = 0; i < Size2; i++)
		Sum2 += B[i];
	if (Sum1 == Sum2)
		return true;
	return false;
}

void Copy(int A[], int B[], int C[], int Size, int Ind) {
	for (int i = 0; i < Ind; i++)
		B[i] = A[i];
	for (int j = 0, k = Ind; j < Size; j++, k++)
		C[j] = A[k];
}

//bool ESubA(int A[], int Size,int *B,int *C,int Indexs,int Move) {
//	if (Move > Size)
//		return false;
//	Copy(A, B, C, Size, Indexs);
//	if (EqualSum(B, C, Size - Indexs, Indexs))
//		return true;
//	if (Size == Indexs) {
//		Indexs = -1;
//		Move++;
//		MRight(A, Size);
//	}
//	if (Indexs < Size) {
//		Indexs++;
//		ESubA(A, Size, B, C, Indexs, Move);
//	}
//
//}

int main() {
	int A[5] = { 1,2,3,4,6 };
	int Size = 5;
	ArrayPer(A, Size, 0);
	/*int Sum = 0;
	int *B,*C,I=1,M=0;
	B = new int[0];
	C = new int[0];
	for (int i = 0; i < Size; i++) {
		Sum += A[i];
	}
	if (Sum % 2 == 0) 
		ESubA(A, Size, B, C, I, M);
	else
		cout << "Can not be divisible\n";*/
	return 0;
}