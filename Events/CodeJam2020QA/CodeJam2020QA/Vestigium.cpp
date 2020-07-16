//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int CTrace(vector<vector <int>> &Vs){
//	int res = 0;
//	for (int i = 0; i < Vs.size(); i++){
//		res += Vs[i][i];
//	}
//	return res;
//}
//
//void ComputeChanges(vector<vector <int>> &Vs, int &r, int &c){
//	for (int i = 0; i < Vs.size(); i++){
//		vector <bool> Flag(Vs.size(), false);
//		for (int j = 0; j < Vs.size(); j++){
//			if (Flag[Vs[i][j] - 1]){
//				r++;
//				break;
//			}
//			Flag[Vs[i][j] - 1] = true;
//		}
//	}
//	for (int i = 0; i < Vs.size(); i++){
//		vector <bool> Flag(Vs.size(), false);
//		for (int j = 0; j < Vs.size(); j++){
//			if (Flag[Vs[j][i] - 1]){
//				c++;
//				break;
//			}
//			Flag[Vs[j][i] - 1] = true;
//		}
//	}
//}
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 0;
//	while (TC--){
//		CN++;
//		int size;
//		cin >> size;
//		vector<vector<int>> MVs;
//		for (int i = 0; i < size; i++){
//			vector <int> Vs(size);
//			for (int j = 0; j < size; j++)
//				cin >> Vs[j];
//			MVs.push_back(Vs);
//		}
//		int k = CTrace(MVs);
//		int r = 0, c = 0;
//		ComputeChanges(MVs, r, c);
//		cout << "Case #" << CN << ": " << k << " " << r << " " << c << '\n';
//	}
//	system("PAUSE");
//	return 0;
//}
