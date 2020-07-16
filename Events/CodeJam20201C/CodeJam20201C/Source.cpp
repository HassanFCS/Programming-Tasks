#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void finduniques(vector <unsigned long long int> S, int &Max, unsigned long long int &MaxV){
	int count = 1;
	Max = 0;
	for (int i = 0; i < S.size(); i++){
		for (int j = i + 1; j < S.size(); j++){
			if (S[i] == S[j])
				count++;
		}
		if (count>Max){
			Max = count;
			MaxV = S[i];
		}
	}
}

int ComputeCuts(int n, int d, vector <unsigned long long int> S){
	if (n == 1)
		return d - 1;
	else{
		int Max = 0;
		unsigned long long int MaxV;
		finduniques(S, Max, MaxV);
		if (Max >= d){
			return 0;
		}
		d = d - Max;
		int cuts = 0;
		for (int i = 0; i < S.size(); i++){
			for (int j = i + 1; j < S.size(); j++){
				int Val = S[j] - MaxV;
				while (Val >= 0){
					Val = Val - MaxV;
					cuts++;
					d--;
					if (d <= 1)
						return cuts;
				}
				
			}
		}
		return cuts;
	}
}

int main(){
	int TC;
	cin >> TC;
	int CN = 1;
	while (TC--){
		int N, D;
		int res;
		cin >> N >> D;
		vector <unsigned long long int> Slices(N);
		for (int i = 0; i < N; i++)
			cin >> Slices[i];
		sort(Slices.begin(), Slices.end());
		//for (int i = 0; i < N; i++){
		//	cout << Slices[i] << " ";
		//}
		res = ComputeCuts(N, D, Slices);
		cout << "Case #" << CN << ": " << res << '\n';
	}
	system("PAUSE");
	return 0;
}