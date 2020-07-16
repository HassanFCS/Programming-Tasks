#include <iostream>

using namespace std;

//int GCD(int A, int B){
//	if (A%B == 0)
//		return B;
//	return GCD(B, A%B);
//}
//
//int main(){
//	int Mul = 1;
//	int Res;
//	int A,B;
//	cin >> A >> B;
//	Mul = A*B;
//	Res = GCD(A, B);
//	do{
//		Res = GCD(A, Res);
//		cin >> A;
//		if (A!=0)
//			Mul=Mul*A;
//	} while (A != 0);
//	cout << "Result : " << Res << '\n';
//	system("PAUSE");
//	return 0;
//}

int main(){
	int Num = 1;
	int *Ar;
	int N;
	int Count = 0;
	int Size;
	cout << "Number of Test Cases : ";
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> Size;
		Ar = new int[Size];
		for (int j = 0; j < Size; j++)
			cin >> Ar[j];
		while (Count != Size){
			for (int k = 0; k < Size; k++){
				if (Num%Ar[k] == 0)
					Count++;
			}
			Num++;
		}
		cout << "LCM : " << Num--;
	}
}