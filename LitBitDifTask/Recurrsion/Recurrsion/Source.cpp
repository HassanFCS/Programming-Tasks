#include "iostream"

using namespace std;

int BS(int A[], int Start, int End, int Key){
	int M = Start + End;
	M = M / 2;
	if (Start > End)
		return -1;
	else if (A[M] == Key)
		return M;
	else if (A[M] > Key)
		return BS(A, Start, M-1, Key);
	else
		return BS(A, M+1, End, Key);
}

int main(){
	int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int N;
	cin >> N;
	cout << "Index : " << BS(A, 0, 10, N);
}