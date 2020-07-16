#include "iostream"
using namespace std;

/*void SafeInsert(int *A, int key, int Size){
	while (Size >= 0 && A[Size] == key){ //A[Size] > key 
		A[Size + 1] = A[Size];			//If Key is greater then its a desresing Sequence Bady sy Chota
		Size--;							//else Choty sy bada
	}
	A[Size + 1] = key;
}

void InsertionSort(int *A, int Size){
	for (int i = 1; i < Size; i++)
		SafeInsert(A, A[i], i - 1);
}


/*int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	InsertionSort(A, 10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << ' ';
	system("PAUSE");
	return 0;
}*/

/*void SumArray(int *A, int Size1, int *B, int Size2, int *Res, int Size3){
	int Carry=0;
	int Sum = 0;
	int *SubRes;
	SubRes = new int[5];
	for (int i = 4; i >= 0; i--){
		Sum = A[i] + B[i];
		Carry = Sum % 2;
		if (Carry = 1 && Sum > 1){
			A[i - 1]++;
			SubRes[i] = Sum % 2;
		}
		else
			SubRes[i] = Sum % 2;
	}
	if (Carry == 1)
		Res[0] = 1;
	for (int i = 1; i < 6; i++)
		Res[i] = SubRes[i - 1];
}

int main(){
	int *A;
	A = new int[5];
	int *B;
	B = new int[5];
	int *Res;
	Res = new int[6];
	for (int i = 0; i < 5; i++)
		A[i] = B[i] = 0;
	for (int i = 0; i < 6; i++)
		Res[i] = 0;
	for (int i = 0; i < 5; i++)
		cin >> A[i];
	for (int i = 0; i < 5; i++)
		cin >> B[i];
	SumArray(A, 5, B, 5, Res, 6);
	for (int i = 0; i < 6; i++)
		cout << Res[i] << ' ';
	system("PAUSE");
	return 0;
}
*/

/*int* Merge(int *A, int Start, int Mid, int End){
	int M = Mid - Start;
	int N = End - Mid;
	int *C;
	C = new int[M + N];
	int i, j, k;
	i = j = 0;
	k = Mid;
	int Val = 0;
	while (i <= M + N){
		if ((A[j] < A[k]) && j<M){
			C[i] = A[j];
			j++;
		}
		else{
			C[i] = A[k];
			k++;
		}
		i++;
	}
	return C;
}

void MergeSort(int *A, int Start, int End){
	if (Start < End){
		int Mid = (Start + (End - 1)) / 2;
		MergeSort(A, Start, Mid);
		MergeSort(A, Mid + 1, End);
		A = Merge(A, Start, Mid, End);
	}
}

						//Wrong
int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	MergeSort(A, 0, 10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << ' ';
	system("PAUSE");
	return 0;
}*/

/*int FindPeak(int *A, int Start, int End){
	if (Start < End){
		int M = (Start + End) / 2;
		if (A[M - 1]<A[M] && A[M]>A[M + 1])
			return M;
		else if (A[M - 1] < A[M] && A[M] < A[M + 1])
			return FindPeak(A, M + 1, End);
		else
			return FindPeak(A, Start, M - 1);
	}
	else
		return -1;
}

						//Wrong
int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	cout << FindPeak(A, 0, 9);
	system("PAUSE");
	return 0;
}
*/

/*int Partition(int *A, int Start, int End){
	int Val = A[End];
	int i = Start - 1;
	for (int j = Start; j < End; j++){
		if (A[j] <= Val){
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[End]);
	return (i + 1);
}

void QuickSort(int *A, int Start, int End){
	if (Start < End){
		int TS = Partition(A, Start, End);
		QuickSort(A, Start, TS - 1);
		QuickSort(A, TS + 1, End);
	}
}

int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	QuickSort(A, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << A[i] << ' ';
	system("PAUSE");
	return 0;
}*/

/*void Heapify(int arr[], int n, int i)
{
	int largest = i;	// Initialize largest as root 
	int l = 2 * i + 1;	// left = 2*i + 1 
	int r = 2 * i + 2;	// right = 2*i + 2 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}


void HeapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];
	HeapSort(A, 10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << ' ';
	system("PAUSE");
	return 0;
}*/

/*int* CountingSort(int *A, int k, int Size){
	int *C;
	C = new int[k];
	for (int i = 0; i < k; i++)
		C[i] = 0;
	for (int j = 0; j < Size; j++)
		C[A[j]]++;
	for (int l = 1; l < k; l++)
		C[l] = C[l] + C[l - 1];
	int *B;
	B = new int[Size];
	for (int m = Size-1; m >= 0; m--){
		B[C[A[m]]] = A[m];
		C[A[m]]--;
	}
	return B;
}

int main(){
	int *A;
	A = new int[10];
	for (int i = 0; i < 10; i++)
		cin >> A[i];

	A=CountingSort(A,10 ,10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << ' ';
	system("PAUSE");
	return 0;
}*/


/*
// C++ program to search an element in row-wise 
// and column-wise sorted matrix 

int search(int mat[4][4], int n, int x)
{
	int i = 0, j = n - 1; //set indexes for top right element 
	while (i < n && j >= 0)
	{
		if (mat[i][j] == x)
		{
			cout << "n Found at "
				<< i << ", " << j;
			return 1;
		}
		if (mat[i][j] > x)
			j--;
		else
			i++;
	}

	cout << "n Element not found";
	return 0; // if ( i==n || j== -1 ) 
}

// Driver code 
int main()
{
	int mat[4][4] = { { 1, 2, 3, 4 },
	{ 15, 25, 35, 45 },
	{ 27, 29, 37, 48 },
	{ 32, 33, 39, 50 } };
	search(mat, 4, 25);
	system("PAUSE");
	return 0;
}*/