//#include "iostream"
//#include "ctime"
//#include "cstdlib"
//using namespace std;
//
//void FillArray(int A[][5], int Size) {
//	for (int i = 0; i < Size; i++)
//		for (int j = 0; j < Size; j++)
//			A[i][j] = rand() % 2;
//}
//
//void PrintArray(int A[][5], int Size) {
//	for (int i = 0; i < Size; i++){
//		for (int j = 0; j < Size; j++)
//			cout << A[i][j] << ' ';
//		cout << '\n';
//	}
//}
//
//void PrintAEN(int Size, int A[][5]){
//	int Count0 = 0;
//	int Count1 = 0;
//	for (int i = 0; i < Size - 1; i++){
//		for (int j = 0; j < Size - 1; j++){
//			for (int k = i; k <= i + 1; k++){
//				for (int l = j; l <= j + 1; l++){
//					if (A[k][l] == 0)
//						Count0++;
//					else
//						Count1++;
//				}
//			}
//			if (Count0 == 4)
//				cout << i << ',' << j << " has all Zeros.\n";
//			else if (Count1 == 4)
//				cout << i << ',' << j << " has all One.\n";
//			Count0 = 0;
//			Count1 = 0;
//		}
//	}
//}
//
//int main(){
//	int A[5][5];
//	int Size = 5;
//	srand((unsigned)time(0));
//	FillArray(A, Size);
//	PrintArray(A, Size);
//	cout << "\n\n";
//	PrintAEN(Size, A);
//	cout << "\n\n";
//	return 0;
//}