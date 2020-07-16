//#include "iostream"
//#include "ctime"
//using namespace std;
//
//bool LinearSearch(int E, int *Ar, const int Size){
//	int i;
//	for (i = 0; i < Size; i++){
//		if (Ar[i] == E)
//			return true;
//	}
//	return false;
//}
//
//bool BinSearch(int E, int *Ar, const int Size){
//	int Start = 0, End = Size - 1;
//	int Mid;
//	while (Start <= End){
//		Mid = (Start + End) / 2;
//		if (Ar[Mid] == E)
//			return true;
//		if (Ar[Mid]>E)
//			End = Mid - 1;
//		else
//			Start = Mid + 1;
//	}
//	return false;
//}
//
//void initArray(int *Ar, const int Size){
//	int i;
//	for (i = 0; i < Size; i++)
//		Ar[i] = rand() % 100000;
//}
//
//void PrintArray(int *Ar, const int Size){
//	int i;
//	for (i = 0; i < Size; i++)
//		cout << Ar[i] << ' ';
//	cout << '\n';
//}
//
//int main(){
//	time_t t1, t2;
//	srand(time(0));
//	const int Size=100000;
//	int *A;
//	A = new int [Size];
//	initArray(A, Size);
//	time(&t1);
//	for (int i = 0; i < Size; i++)
//		LinearSearch(rand()%10000, A, Size);
//	time(&t2);
//	cout << "Time Required to Linear Search : " << t2 - t1 << '\n';
//	time(&t1);
//	for (int i = 0; i < Size; i++)
//		BinSearch(rand() % 10000, A, Size);
//	time(&t2);
//	cout << "Time Required to Binary Search: " << t2 - t1 << '\n';
//	system("PAUSE");
//	return 0;
//}