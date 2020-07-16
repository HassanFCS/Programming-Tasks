#include <iostream>
#include <vector>
//#include <functional>
#include <algorithm>

using namespace std;

//int max(int a, int b) { return (a > b) ? a : b; }
//
//int knapSack(int W, int wt[], int val[], int n)
//{
//	int i, w;
//	int **K = new int*[n + 1];
//	for (int i = 0; i < n + 1; i++)
//		K[i] = new int[W + 1];
//
//	// Build table K[][] in bottom up manner 
//	for (i = 0; i <= n; i++)
//	{
//		for (w = 0; w <= W; w++)
//		{
//			if (i == 0 || w == 0)
//				K[i][w] = 0;
//			else if (wt[i - 1] <= w)
//				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
//			else
//				K[i][w] = K[i - 1][w];
//		}
//	}
//
//	return K[n][W];
//}

int main(){
	int TC;
	cin >> TC;
	int j = 1;
	while (TC--){
		int N, P;
		cin >> N;
		cin >> P;
		vector <int> Vs;
		for (int i = 0; i < N; i++){
			int val;
			cin >> val;
			Vs.push_back(val);
		}
		sort(Vs.begin(), Vs.end());
		int Count = 0;
		for (int i = 0; i<Vs.size() ; i++){
			if (Vs[i] <= P){
				Count++;
				P = P - Vs[i];
			}
			else
				break;
		}
		cout << "Case #" << j << ": " << Count << '\n';
		j++;
	}
	system("PAUSE");
	return 0;
}