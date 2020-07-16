#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int size;
	cin >> size;
	vector <vector <int>> Vs(size);
	for (int i = 0; i < size; i++){
		vector <int> Vvs(size, 0);
		Vs[i]=Vvs;
	}
	for (int i = 0; i < size; i++){
		for (int j = 0; j < i + 1; j++){
			cout << i-j << " " << j << ", ";
		}
		cout << '\n';
	}
	for (int j = 0; j<size; j++){
		for (int i = size - 1; i > j; i--) {
			cout << i << " " << size-(i-j) << ", ";
		}
		cout << '\n';
	}

	cout << "\n\n\n";

	for (int i = size-1; i >= 0; i--){
		for (int j = 0; j <size-i; j++){
			cout << i+j << " " << j << ", ";
		}
		cout << '\n';
	}
	for (int i = size - 1; i >= 0; i--){
		for (int j = size-i; j < size; j++){
			cout << abs(size-j-i) << " " << j << ", ";
		}
		cout << '\n';
	}

	/*for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++)
			cout << Vs[i][j] << " ";
		cout << '\n';
	}*/

	system("PAUSE");
	return 0;
}