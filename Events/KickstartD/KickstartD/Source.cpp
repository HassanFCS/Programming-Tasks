//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 1;
//	while (TC--){
//		int n;
//		cin >> n;
//		int count = 0;
//		int max = -999;
//		vector <int> Vs(n);
//		for (int i = 0; i < n; i++){
//			cin >> Vs[i];
//		}
//		for (int i = 0; i < n; i++){
//			if (max < Vs[i]){
//				max = Vs[i];
//				if (i<n - 1){
//					if (Vs[i]>Vs[i + 1])
//						count += 1;
//				}
//				else
//					count++;
//			}
//		}
//		cout << "Case #" << CN << ": " << count << '\n';
//		CN++;
//	}
//	system("PAUSE");
//	return 0;
//}