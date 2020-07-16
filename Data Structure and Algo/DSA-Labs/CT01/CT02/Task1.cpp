#include "iostream"
#include "ctime"
#include "cstdlib"
using namespace std;

int main(){
	int A[5];
	int Size = 5;
	srand((unsigned)time(0));
	for (int i = 0; i < 5; i++)
		A[i] = rand() % 10;
	for (int i = 0; i < 5; i++)
		cout << A[i] << '\t';
	cout << '\n' << '\n';
	int sum = 0;
	for (int i = 0; i < Size; i++){
		sum = A[i];
		cout << sum << '\t';
		for (int j = i+1; j < Size; j++){
			sum = sum + A[j];
			cout << sum << '\t';
		}
		sum = 0;
		cout << '\n';
	}
	return 0;
}