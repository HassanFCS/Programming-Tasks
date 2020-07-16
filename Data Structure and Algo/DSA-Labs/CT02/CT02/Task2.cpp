//#include "iostream"
//#include "cstdlib"
//#include "ctime"
//using namespace std;
//
//void Init(int A[][10], int Size){
//	for (int i = 0; i < Size; i++)
//		for (int j = 0; j < Size; j++)
//			A[i][j] = rand() % 2 + 1;
//}
//
//void PrintArray(int A[][10], int Size){
//	for (int i = 0; i < Size; i++){
//		for (int j = 0; j < Size; j++)
//			cout << A[i][j] << ' ';
//		cout << '\n';
//	}
//}
//
//void IntersectionSA(int A[], int B[], int Sample[], int Size) {
//	for (int i = 0; i < Size; i++){
//		if (A[i] == B[i]){
//			Sample[i] = A[i];
//		}
//		else
//			Sample[i] = 0;
//	}
//}
//
//void MaxSA(int Sample[], int Size,int Max[]){
//	int Key = 0;
//	for (int i = 0; i < Size; i++){
//		if (Sample[i] != 0){
//			Max[Key] = Sample[i];
//			Key++;
//		}
//		else
//			Key = 0;
//	}
//}
//
//int SizeMax(int Max[], int Size){
//	int Val = 0;
//	for (int i = 0; i < Size; i++){
//		if (Max[i] == 0)
//			return Val;
//		else
//			Val++;
//	}
//}
//
//void SubArray(int A[][10], int Size, int SA[], int Row){
//	for (int i = 0; i < Size; i++)
//		SA[i] = A[Row][i];
//}
//
//int main(){
//	srand((unsigned)time(0));
//	int Size = 10, A[10][10];
//	Init(A, Size);
//	PrintArray(A, Size);
//	cout << '\n';
//	int Row1 = 0;
//	int Row2 = 0;
//	int Max1[10];
//	int Max2[10];
//	int MaxSize1 = 0;
//	int MaxSize2 = 0;
//	int SampleArray1[10];
//	int SampleArray2[10];
//	for (int i = 0; i < Size - 1; i++){
//		SubArray(A, Size, SampleArray1, i);
//		for (int j = i + 1; j < Size; j++){
//			SubArray(A, Size, SampleArray2, j);
//			IntersectionSA(SampleArray1, SampleArray2, Max2, Size);
//			MaxSize2 = SizeMax(Max2, Size);
//			if (MaxSize2 >= MaxSize1){
//				MaxSize1 = MaxSize2;
//				Row1 = i;
//				Row2 = j;
//				for (int i = 0; i < Size; i++)
//					Max1[i] = Max2[i];
//			}
//		}
//	}
//	cout << "\n\n";
//	cout << Row1 << " and " << Row2 << " have Max Size common Sequence ";
//	for (int i = 0; i < MaxSize1; i++)
//		cout << Max1[i] << ' ';
//	cout << "\n\n";
//	return 0;
//}