#include <iostream>
#include <vector>

using namespace std;

int main(){
	int cn = 1;
	int TC;
	cin >> TC;
	while (TC--){
		long long int n, d;
		cin >> n >> d;
		vector<long long int> Vs(n);
		for (int i = 0; i < n; i++)
			cin >> Vs[i];
		long long int Res=d;
		bool fflag = false;
		for (int i = 0; i<n ;i++){
			while (!fflag){
				if (Res%Vs[0] == 0){
					fflag = true;
					i++;
				}
				else
					Res--;
			}
			if (i >= n)
				break;
			long long int div = Res / Vs[i];
			div++;
			if (Vs[i] * div > d)
			{
				Res = Res - Vs[0];
				i = 0;
			}
		}
		cout << "Case #" << cn << ": " << Res << '\n';
		cn++;
	}
	return 0;
}