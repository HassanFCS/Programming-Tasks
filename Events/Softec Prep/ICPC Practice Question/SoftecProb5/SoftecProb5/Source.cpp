#include "iostream"
#include "vector"

using namespace std;

void PerfectNumber(vector <int> &Vec , int N){
	int sum = 0;
	for (int i = 0; i < Vec.size(); i++)
		sum = sum + Vec[i];
	if (sum != N)
		cout << N << " is NOT perfect.\n";
	else{
		if (sum == N){
			cout << sum << '=';
			for (int i = 0; i < Vec.size(); i++)
				cout << Vec[i] << '+';
			cout << "\b \n";
		}
	}
}

int main(){
	vector <int> V;
	int N;
	cin >> N;
	for (int i = 1; i <= N / 2; i++){
		if (N%i == 0)
			V.push_back(i);
	}
	PerfectNumber(V, N);
	system("PAUSE");
	return 0;
}