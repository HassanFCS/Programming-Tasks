#include "iostream"
#include "vector"

using namespace std;
											//Using Dynamic Programming
													//Fab Number

//int Fab(int N, vector<int> & V){
//	if (V[N] == -1)
//		V[N] = Fab(N - 1, V) + Fab(N - 2, V);
//	return V[N];
//}
//
//int main(){
//	int N;
//	do{
//		cin >> N;
//		vector <int> Vec(N + 1);
//		Vec[0] = 0;
//		Vec[1] = 1;
//		for (int i = 2; i <= N; i++)
//			Vec[i] = -1;
//		cout << Fab(N, Vec) << '\n';
//	} while (N != -1);
//	system("PAUSE");
//	return 0;
//}

//long double TriSum(int N ,vector <long double> &V){
//	if (V[N] == -1)
//		V[N] = TriSum(N - 1, V) + TriSum(N - 2, V) + TriSum(N - 3, V);
//	return V[N];
//}
//
//int main(){
//	int N;
//	do{
//		cin >> N;
//		vector <long double> V(N + 1);
//		if (N>=0)
//			V[0] = 0;
//		if (N>=1)
//			V[1] = 1;
//		if (N >= 2)
//			V[2] = 2;
//		for (int i = 3; i <= N; i++)
//			V[i] = -1;
//		cout << TriSum(N, V) << '\n';
//	} while (N != -1);
//	system("PAUSE");
//	return 0;
//}

//int CatalanNo(int N){
//	int sum = 0;
//	if (N == 0 || N == 1)
//		return 1;
//	for (int i = 0; i < N; i++)
//		sum = sum + (CatalanNo(i) * CatalanNo((N-1) - i));
//	return sum;
//}
//
//long double CNoDP(int N, vector <long double> &V){
//	int sum = 0;
//	if (V[N] == -1){
//		for (int i = 0; i < N; i++){
//			sum = sum + (CNoDP(i, V) * CNoDP((N-1) - i, V));
//		}
//		V[N] = sum;
//	}
//	return V[N];
//}
//
//int main(){
//	int N;
//	/*do{
//		cin >> N;
//		cout << CatalanNo(N) << '\n';
//	} while (N != -1);*/
//	do{
//		cin >> N;
//		vector <long double> Vec(N + 1);
//		Vec[0] = 1;
//		Vec[1] = 1;
//		for (int i = 2; i <= N; i++)
//			Vec[i] = -1;
//		cout << CNoDP(N, Vec) << '\n';
//	} while (N != -1);
//	system("PAUSE");
//	return 0;
//}


								//Using 2 loops
//void MaxSum(vector <int> & Ar, int Size, int &SI, int &EI){
//	int sum1 = 0;
//	int sum2 = 0;
//	for (int i=0; i < Size; i++){
//		for (int j = i; j < Size; j++){
//			sum2 += Ar[j];
//			if (sum1 < sum2){
//				sum1 = sum2;
//				SI = i;
//				EI = j;
//			}
//		}
//		sum2 = 0;
//	}
//}
//
//
//											//Using 1 Loop
//void MaxSum2(vector <int> & Ar, int Size, int &SI, int &EI, int &Max){
//	int Sum = 0, e = 0, s = 0;
//	do{
//		Sum += Ar[e];
//		if (Sum < 0){
//			Sum = 0;
//			s = e+1;
//		}
//		else if (Sum > Max){
//			Max = Sum;
//			SI = s;
//			EI = e;
//		}
//		e = e + 1;
//	} while (e < Ar.size());
//}
//
//int main(){
//	int Si=0, Ei=0;
//	int Sum = -123;
//	vector <int> A(8);
//	A[0] = -1;
//	A[1] = 7;
//	A[2] = -6;
//	A[3] = 5;
//	A[4] = 4;
//	A[5] = -10;
//	A[6] = 20;
//	A[7] = -30;
//	MaxSum2(A, 8, Si, Ei,Sum);
//	cout << "Start : " << Si << ' ' << "End : " << Ei << '\n';
//	for (int i = Si; i <= Ei; i++){
//		cout << A[i] << ' ';
//	}
//	cout << '\n' << "Sum : " << Sum << '\n';
//	system("PAUSE");
//	return 0;
//}



int main(){

	system("PAUSE");
	return 0;
}