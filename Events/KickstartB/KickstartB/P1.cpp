//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(){
//	int cn = 1;
//	int TC;
//	cin >> TC;
//	while (TC--){
//		int n;
//		cin >> n;
//		vector <int> Vs(n);
//		for (int i = 0; i<n; i++){
//			cin >> Vs[i];
//		}
//		int maxi = 0;
//		int max = 0;
//		for (int i = 1; i < n - 1; i++){
//			if (Vs[i]>Vs[i - 1] && Vs[i]>Vs[i + 1]){
//				if (Vs[i] > max){
//					maxi++;
//					max = Vs[i];
//				}
//
//			}
//		}
//		cout << "Case #" << cn << ": " << max << '\n';
//		cn++;
//	}
//	return 0;
//}