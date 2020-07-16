//#include "iostream"
//#include "cstdlib"
//#include "ctime"
//
//using namespace std;
//
//void PrintCSum(int A[], int Size, int N){
//	for (int i = 0; i <= Size - N; i++){
//		int Sum = 0;
//		for (int j = i; j < i + N; j++){
//			Sum = Sum + A[j];
//		}
//		cout << Sum << '\t';
//	}
//	cout << '\n';
//}
//
//int main(){
//	int A[10];
//	int Size = 10;
//	srand((unsigned)time(0));
//	for (int i = 0; i < Size; i++)
//		A[i] = rand() % 5;
//	for (int i = 0; i < Size; i++)
//		cout << A[i] << '\t';
//	cout << '\n' << '\n';
//	for (int i = 0; i < Size-1; i++){
//		PrintCSum(A, Size, i + 1);
//	}
//	int Sum = 0;
//	for (int i = 0; i < Size; i++)
//		Sum = Sum + A[i];
//	cout << Sum << '\n';
//	return 0;
//}