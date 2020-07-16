#include <iostream>
#include <vector>

using namespace std;

int main(){
	int TC;
	cin >> TC;
	while (TC--){
		int N, K, P;
		cin >> N >> K >> P;
		vector<vector<int>> Vs(N);
		for (int i = 0; i < N; i++){
			vector <int> V;
			for (int j = 0; j < K; j++){
				int val;
				cin >> val;
				V.push_back(val);
			}
			Vs[i] = V;
		}

		vector<int> Maxs;
		vector <int> Indexs;
		for (int i = 0; i < N; i++){
			int sum = 0;
			int j = 0;
			for (; j < K; j++){
				if (j < P){
					sum += Vs[i][j];
				}
				else
					break;
			}
			Indexs.push_back(j);
			Maxs.push_back(sum);
		}
		int TSum = 0;
		for (int i = 0; i < Maxs.size(); i++)
			TSum += Maxs[i];

		
		int sum = 0;
		for (int i = 0; i < Indexs.size(); i++){
			sum += Indexs[i];
		}
		while (sum>P){
			int minval = 999999;
			int minind;
			for (int i = 0; i < N; i++){
				int j = Indexs[i] - 1;
				if (j >= 0){
					if (minval>Vs[i][j]){
						minval = Vs[i][j];
						minind = i;
					}
				}
			}
			Indexs[minind]--;
			TSum -= minval;
			sum--;
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < K; j++){
				cout << Vs[i][j] << " ";
			}
			cout << Maxs[i] << '\t' << TSum;
			cout << '\n';
		}

	}
	system("PAUSE");
	return 0;
}