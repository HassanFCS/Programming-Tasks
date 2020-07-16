#include "iostream"

using namespace std;

int CountAscend(int A[], int Size) {
	int C = 0;
	if (Size == 1)
		return A[0];
	if (CountAscend(A, Size - 1) < A[Size-1])
		return ++C;
}

int main() {
	int A[10] = { 1,2,3,5,4,6,1,4,3,9 };
	cout << CountAscend(A, 9) << '\n';
	return 0;
}