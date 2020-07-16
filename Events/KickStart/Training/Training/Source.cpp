#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


using namespace std;

int main(){
	int TC;
	int i = 1;
	cin >> TC;
	while (TC--){
		int N, P;
		vector <int> Vs;
		cin >> N >> P;
		for (int i = 0; i < N; i++){
			int no;
			cin >> no;
			Vs.push_back(no);
		}
		/*vector <int> Maxs;
		for (int i = 0; i < Vs.size() - (P - 1); i++){
			int max = -99999;
			for (int j = i; j < i + P; j++){
				if (max < Vs[j])
					max = Vs[j];
			}
			Maxs.push_back(max);
		}
		int min = INT_MAX;
		for (int i = 0; i < Maxs.size(); i++){
			int Train = 0;
			for (int j = i; j < i + P; j++){
				Train += Maxs[i] - Vs[j];
			}
			if (min>Train)
				min = Train;
		}
		cout << "Case #" << i << ": " << min << '\n';
		*/

		sort(Vs.begin(), Vs.end(), greater<int>());
		
		int sum = 0;
		for (int i = 1; i < P; i++)
			sum += (Vs[0] - Vs[i]);
		int sol = sum;
		for (int i = 1; i < N - P + 1; i++){
			sum -= (Vs[i - 1] - Vs[i]) * (P - 1);
			sum += Vs[i] - Vs[P + i - 1];
			if (sum < sol)
				sol = sum;
		}
		cout << "Case #" << i << ": " << sol << '\n';
		i++;

	}
	system("PAUSE");
	return 0;
}