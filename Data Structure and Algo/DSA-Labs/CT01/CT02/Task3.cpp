//#include "iostream"
//#include "ctime"
//#include "cstdlib"
//using namespace std;
//
//void FillArray(int A[][10], int Size){
//	for (int i = 0; i < Size; i++)
//		for (int j = 0; j < Size; j++)
//			A[i][j] = rand() % 2;
//}
//
//void PrintArray10(int A[][10], int Size){
//	for (int i = 0; i < Size; i++){
//		for (int j = 0; j < Size; j++)
//			cout << A[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << "\n\n";
//}
//
//int main(){
//	srand((unsigned)time(0));
//	int A[10][10];
//	int Sample[3][3];
//	int Size = 10;
//	int Count = 0;
//	FillArray(A, Size);
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 3; j++)
//			Sample[i][j] = A[i][j];
//	PrintArray10(A, 10);
//	for (int i = 0; i < Size - 1; i++){
//		for (int j = 0; j < Size - 1; j++){
//			if (i != 0 && j != 0){
//				for (int k = i; k <= i + 2; k++){
//					for (int l = j; l <= j + 2; l++){
//						if (Sample[k - i][l - j] == A[k][l])
//							Count++;
//					}
//				}
//			}
//			if (Count == 9)
//				cout << "Block 0,0 and " << i << ',' << j << " have same elements at Corresponding positions.\n";
//			Count = 0;
//		}
//	}
//	return 0;
//}