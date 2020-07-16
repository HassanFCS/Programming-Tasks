#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

unsigned long long int factorial(unsigned long long int n, unsigned long long int m){
	unsigned long long int res = 1;
	for (int i = 1; i <= n; i++)
		res = (res*i) % m;
	return res;
}

unsigned long long int Power(int a, int exp, int mod){
	unsigned long long int res = 1;
	for (int i = 0; i < exp; i++){
		res = (res*a) % mod;
	}
	return res;
}

int main(){
	int a, n, p;
	cin >> a >> n >> p;
	n=factorial(n, p);
	cout << n << '\n';
	cout << Power(a, n, p) << '\n';
	system("PAUSE");
	return 0;
	
	ifstream cin("A-large-practice.in");
	ofstream cout("A-large-practice.out");
	int TC;
	cin >> TC;

	int i = 1;
	while (TC--){
		unsigned long long int A, N, P;
		cin >> A >> N >> P;
		int exp = factorial(N, P);
		unsigned long long int Sol = Power(A, exp, P);
		cout << "Case #" << i << ": " << Sol << '\n';
		i++;
	}
	system("PAUSE");
	return 0;
}