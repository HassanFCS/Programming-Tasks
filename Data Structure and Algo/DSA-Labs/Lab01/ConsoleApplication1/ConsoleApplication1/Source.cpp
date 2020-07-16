//#include "iostream"
//#include "ctime"
//using namespace std;
//
//void initArray(int *Ar, const int Size){
//	int i;
//	for (i = 0; i < Size; i++)
//		Ar[i] = rand() % 1000;
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
//	const int Size=1000;
//	int *A;
//	A = new int [Size];
//	time(&t1);
//	initArray(A, Size);
//	PrintArray(A, Size);
//	time(&t2);
//	cout << "Time Required to Execute that Code : " << t2 - t2 << '\n';
//	system("PAUSE");
//	return 0;
//}