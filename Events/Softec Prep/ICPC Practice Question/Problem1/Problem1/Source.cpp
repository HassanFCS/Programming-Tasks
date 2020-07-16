#include "iostream"
#include "fstream"
using namespace std;

int LCM(int Ar[], int Size){
	int Num = 1;
	int Count = 0;
	while (Count < Size){
		Count = 0;
		for (int k = 0; k < Size; k++){
			if (Num % Ar[k] == 0)
				Count++;
		}
		Num++;
	}
	return Num-1;
}

int main(){
	int *Ar;
	int N;
	int Size;
	ifstream fin("ProA.txt");  
	fin >> N;
	for (int i = 0; i < N; i++){
		fin >> Size;
		Ar = new int[Size];
		for (int j = 0; j < Size; j++)
			fin >> Ar[j];
			cout << LCM(Ar,Size) << '\n';
	}
	system("PAUSE");
	return 0;
}