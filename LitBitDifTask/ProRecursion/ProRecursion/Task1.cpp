#include "iostream"

using namespace std;

int ASum(int N) {
	if (N == 1)
		return 1;
	return N + ASum(N - 1);
}

int GSum(int N) {
	if (N == 1)
		return 1;
	return N*N + GSum(N - 1);
}

float HSum(float N) {
	if (N == 1)
		return 1;
	return 1 / N + HSum(N - 1);
}

int main() {
	cout << ASum(100) << '\n';
	cout << ASum(5) << '\n';
	cout << ASum(4) << '\n';
	cout << GSum(4) << '\n';
	cout << GSum(3) << '\n';
	cout << GSum(2) << '\n';
	cout << HSum(3) << '\n';
	return 0;
}