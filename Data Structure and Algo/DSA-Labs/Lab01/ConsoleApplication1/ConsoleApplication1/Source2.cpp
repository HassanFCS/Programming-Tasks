#include "iostream"
#include "ctime"
using namespace std;

void bubbleSort(int *Ar, int Size){
	for (int i = 0; i < Size; i++){
		for (int j = 0; j < Size - 1; j++){
			if (Ar[j]>Ar[j + 1]){
				int temp = Ar[j];
				Ar[j] = Ar[j + 1];
				Ar[j + 1] = temp;
			}
		}
	}
}

void SelectionSort(int *Ar, int Size){
	for (int i = 0; i < Size; i++){
		for (int j = i; j < Size; j++){
			if (Ar[i]>Ar[j]){
				int temp = Ar[j];
				Ar[j] = Ar[i];
				Ar[i] = temp;
			}
		}
	}
}

void InsertionSort(int *Ar, int Size){
	for (int i = 1; i < Size; i++){
		int temp = Ar[i];
		int j = i - 1;
		while (j >= 0 && Ar[j] > temp){
			Ar[j+1] = Ar[j];
			j--;
		}
		Ar[j + 1] = temp;
	}
}

void initArray(int *Ar, const int Size){
	int i;
	for (i = 0; i < Size; i++)
		Ar[i] = rand() % 100;
}

void PrintArray(int *Ar, const int Size){
	int i;
	for (i = 0; i < Size; i++)
		cout << Ar[i] << ' ';
	cout << '\n';
}

void Copy(int *A, int Size, int *B){
	for (int i = 0; i < Size; i++)
		B[i] = A[i];
}

int main(){
	time_t t1, t2;
	srand(time(0));
	int *A,*B,*C;
	int Size = 30000;
	A = new int[Size];
	B = new int[Size];
	C = new int[Size];
	initArray(A, Size);
	Copy(A, Size, B);
	Copy(A, Size, C);
	for (int i = 0; i < 5; i++){
		time(&t1);
		bubbleSort(A, Size);
		bubbleSort(B, Size);
		bubbleSort(C, Size);
		time(&t2);
		cout << "Time Taken by Bubble Sort : " << t2 - t1 << '\n';
		time(&t1);
		SelectionSort(A, Size);
		SelectionSort(B, Size);
		SelectionSort(C, Size);
		time(&t2);
		cout << "Time Taken by Selection Sort : " << t2 - t1 << '\n';
		time(&t1);
		InsertionSort(A, Size);
		InsertionSort(B, Size);
		InsertionSort(C, Size);
		time(&t2);
		cout << "Time Taken by Insertion Sort : " << t2 - t1 << '\n';
	}
	system("PAUSE");
	return 0;
}