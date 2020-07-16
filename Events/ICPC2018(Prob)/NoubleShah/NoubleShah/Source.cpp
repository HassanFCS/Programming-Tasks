#include<iostream>
#include<vector>
#include<fstream>
#include<stack>
#include<iomanip>
#include<string>
#include<map>
#include <functional>
#include<algorithm>

using namespace std;

void Print(vector<int>& Vs);
bool IsValidSet(vector<int>& Vs, int M, int N)
{
	long long Ans = 0;
	for (int i = 0; i < Vs.size(); i++)
	{
		if (Ans >= pow(2, 31))
			return false;
		Ans += pow(Vs[i], N);
	}
	return Ans == M;
}
void CalculatePowerSet(vector<vector<int>> & PS, vector<int> & S, int si)
{
	if (si == S.size())
		return;
	if (si == 0)
		PS.push_back(vector<int>());

	int Size = PS.size();
	for (int i = 0; i < Size; i++)
	{
		vector<int> V = PS[i];
		V.push_back(S[si]);
		PS.push_back(V);
	}
	CalculatePowerSet(PS, S, si + 1);
}

int main()
{
	vector<int> S = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int T, N, M;
	ifstream fin("in.txt");
	fin >> T;
	vector<vector<int>> PowerSet;
	CalculatePowerSet(PowerSet, S, 0);
	sort(PowerSet.begin(), PowerSet.end());
	for (int t = 1; t <= T; t++)
	{
		fin >> M >> N;
		cout << "Case " << t << ":\n";
		bool SolutionFound = false;
		for (int i = 0; i < PowerSet.size(); i++)
		{
			if (IsValidSet(PowerSet[i], M, N))
			{
				Print(PowerSet[i]);
				cout << endl;
				SolutionFound = true;
			}
		}
		if (!SolutionFound)
		{
			cout << "Not Possible" << endl;
		}
	}
	system("pause");
	return 0;
}