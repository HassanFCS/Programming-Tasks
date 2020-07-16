//#include "iostream"
//#include "cstdlib"
//#include "ctime"
//using namespace std;
//
//int MinVal(int A[],int &SMIN, int Size, int &NoMin) {
//	int Res = 123456;
//	SMIN = 12345;
//	for (int i = 0; i < Size; i++){
//		if (A[i] >= 0){
//			if (Res == A[i])
//				NoMin++;
//			if (Res>A[i]){
//				SMIN = Res;
//				Res = A[i];
//				NoMin = 0;
//			}
//		}
//	}
//	return Res;
//}
//
//int MaxVal(int A[],int SMAX, int Size, int &NoMax) {
//	int Res=-12345;
//	SMAX = -123456;
//	for (int i = 0; i < Size; i++){
//		if (A[i]>=0){
//			if (Res == A[i])
//				NoMax++;
//			if (Res<A[i]){
//				SMAX = Res;
//				Res = A[i];
//				NoMax = 0;
//			}
//		}
//	}
//	return Res;
//}
//
//int RemoveElement(int A[], int Size,int Key){
//	int Count = 0;
//	for (int i = 0; i < Size; i++){
//		if (A[i] == Key){
//			A[i] = -1;
//			Count++;
//		}
//	}
//	return Count;
//}
//
//int main(){
//	srand((unsigned)time(0));
//	int *A;
//	int K;
//	int Size;
//	cin >> Size;
//	A = new int[Size];
//	for (int i = 0; i < Size; i++){
//		A[i] = rand() % 10 + 1;
//	}
//	for (int i = 0; i < Size; i++)
//		cout << A[i] << ' ';
//	cout << '\n';
//	cin >> K;
//	int Max = -123456;
//	int SMax = -123456;
//	int NoMax = 0;
//	int NoMin = 0;
//	int Min = 123456;
//	int SMin = 123456;
//	bool Flag = true;
//	int Count = 0;
//	Max=MaxVal(A, SMax, Size, NoMax);
//	Min=MinVal(A, SMin, Size, NoMin);
//	while (Max - Min>K && Flag == true){
//		if ((Max - SMin <= K) && (NoMax >= NoMin))
//			Count += RemoveElement(A, Size, Min);
//		else if ((SMax - Min <= K) && (NoMax <= NoMin))
//			Count += RemoveElement(A, Size, Max);
//		else{
//			if (NoMax >= NoMin)
//				Count += RemoveElement(A, Size, Min);
//			else
//				Count += RemoveElement(A, Size, Min);
//		}
//		Max = MaxVal(A, SMax, Size, NoMax);
//		Min = MinVal(A, SMin, Size, NoMin);
//		for (int i = 0; i < Size; i++)
//			cout << A[i] << ' ';
//		cout << '\n';
//		/*if (Min > K)
//			Flag = false;*/
//	}
//	cout << Count << " No of Steps Required.\n";
//	return 0;
//}