#include "iostream"
#include "fstream"
using namespace std;

char PrintHexa(int N){
	if (N >= 0 && N < 10)
		return N+48;
	else if (N == 10)
		return 'A';
	else if (N == 11)
		return 'B';
	else if (N == 12)
		return 'C';
	else if (N == 13)
		return 'D';
	else if (N == 14)
		return 'E';
	else if (N == 15)
		return 'F';
}

void Hexa(unsigned int Number){
	if (Number / 16 == 0){
		cout << PrintHexa(Number%16);
		return;
	}
	Hexa(Number / 16);
	cout << PrintHexa(Number % 16);
	return;
}

int main(){
	int N;
	int A;
	ifstream fin("Data.txt");
	fin >> N;
	for (int i = 0; i < N; i++){
		fin >> A;
		Hexa(A);
		cout << '\n';
	}
	system("PAUSE");
	return 0;
}