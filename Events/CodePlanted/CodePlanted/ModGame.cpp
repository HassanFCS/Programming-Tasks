//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int GCD(int a, int b){
//	if (b == 0)
//		return a;
//	return GCD(b, a%b);
//}
//
//int AGCD(vector <int> &V){
//	int res = V[0];
//	for (int i = 1; i < V.size(); i++){
//		res = GCD(V[i], res);
//		if (res == 1)
//			return 1;
//	}
//	return res;
//}
//
//int main(){
//	int TC;
//	cin >> TC;
//	while(TC--){
//		int n;
//		cin >> n;
//		vector<int> Vs(n);
//		for (int i = 0; i < n; i++){
//			cin >> Vs[i];
//		}
//		sort(Vs.begin(), Vs.end());
//		if (Vs[0] == Vs[n - 1])
//			cout << -1 << '\n';
//		else{
//			vector<int> Diff(n);
//			Diff[0] = Vs[n - 1] - Vs[0];
//			for (int i = 1; i < n; i++){
//				Diff[i] = Vs[i] - Vs[i - 1];
//			}
//			cout << AGCD(Diff) << '\n';
//		}
//
//	}
//	system("PAUSE");
//	return 0;
//}