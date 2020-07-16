//#include<iostream>
//#include<vector>
//#include<string>
//#include<set>
//#include<algorithm>
//#include<time.h>
//
//using namespace std;
//
//int min(int A, int B){
//	return ((A<B) ? A : B);
//}
//
//void GenerateTrace(int N, int K, vector<int> ATrace  , set<vector<int>> &AllTraces){
//	if (ATrace.size() > N   || N - ATrace.size() > K )
//		return;
//
//	if (K == 0){
//		if (ATrace.size() == N){
//			sort(ATrace.begin(), ATrace.end());
//			AllTraces.insert(ATrace);
//			return ;
//		}
//	}
//	for (int i = 1; i <= min(K, N); i++){
//		ATrace.push_back(i);
//		GenerateTrace(N, K - i, ATrace, AllTraces);
//		ATrace.pop_back();
//	}
//}
//
//set<vector<int>> GenerateAllTraces(int N, int K){
//	vector<vector<vector<int>>> Ms(N, vector<vector<int>>(K));
//
//	set<vector<int>> AllTraces;
//	vector<int> ATrace;
//
//	GenerateTrace(N, K, ATrace, AllTraces);
//	return AllTraces;
//}
//ostream& operator<<(ostream &, const vector<int> &V){
//	cout << "{ ";
//	for (int i = 0; i < V.size(); i++)
//	{
//		cout << V[i] << " ";
//	}
//	return cout << "}";
//}
//
//int SetValue(vector <vector<int>> &V, int i, int j){
//	vector <bool> Flag(V.size(), true);
//	for (int k = 0; k < V.size(); k++){
//		if (V[i][k] != 0){
//			Flag[V[i][k] - 1] = false;
//		}
//	}
//	for (int k = 0; k < V.size(); k++){
//		if (V[k][j] != 0){
//			Flag[V[k][j] - 1] = false;
//		}
//	}
//	for (int k = 0; k < V.size(); k++){
//		if (Flag[k])
//			return k + 1;
//	}
//}
//
//void MakeLatin(vector <vector<int>> &V){
//	for (int i = 0; i < V.size(); i++){
//		for (int j = 0; j < V[i].size(); j++){
//			if (i != j){
//				V[i][j] = SetValue(V, i, j);
//			}
//		}
//	}
//}
//
//int main(){
//
//	vector <vector<int>> Vs(5, vector<int>(5, 0));
//	for (int i = 0; i < 5; i++){
//		cin >> Vs[i][i];
//	}
//	MakeLatin(Vs);
//	for (int i = 0; i < Vs.size();i++)
//		cout << Vs[i] << '\n';
//	system("pause");
//	return 0;
//
//	int N = 50, K = 55;
//	time_t t1 = time(0);
//	set<vector<int>> AllTraces = GenerateAllTraces(5, 17);
//
//	for (auto i = AllTraces.begin(); i != AllTraces.end(); i++){
//		cout << (*i) << endl;
//	}
//	time_t t2 = time(0);
//	cout << t2 - t1;
//	system("pause");
//	return 0;
//}