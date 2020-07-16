#include "iostream"
#include "cstdlib"
#include "ctime"
using namespace std;

void Init(int A[][10], int Size){
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			A[i][j] = rand() % 2;
}

void Print(int A[][10], int Size){
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}

void MaxSubAr(int Ar[][10], int S){
	bool Flag = true;
	bool Check1 = true;
	int Sample;
	int Count = 1;
	int k, l;
	for (int Size = S; Size > 1 && Check1 == true; Size--){
		for (int i = 0; i + Size <= S && Check1 == true; i++){
			for (int j = 0; j + Size <= S && Check1 == true; j++){
				for (k = i; k < i + Size && Check1 == true; k++){
					for (l = j; l < j + Size && Check1 == true; l++){
						if (Flag == true){
							Sample = Ar[k][l];
							Flag = false;
						}
						else{
							if (Sample == Ar[k][l])
								Count++;
						}
					}
				}
				if (Count == (Size)*(Size)){
					cout << Size << " Size's Block Exist of " << Sample << " Starting from " << k - Size << ',' << l - Size << " Ending at " << k - 1 << ',' << l - 1 << '\n';
					Check1 = false;
				}
				Flag = true;
				Count = 1;
			}
		}
	}
}

int main(){
	srand((unsigned)time(0));
	int Ar[10][10];
	int Size = 10;
	Init(Ar, Size);
	Print(Ar, Size);
	cout << '\n';
	MaxSubAr(Ar, Size);
	return 0;
}