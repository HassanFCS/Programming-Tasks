#include "iostream"
#include "vector"
#include <fstream>
using namespace std;

void Copy(vector<vector <int>> &m, vector<vector <int>> &M, int ignore){
	int ri=0, ci;
	for (int i = 1; i < M.size(); i++){
		ci = 0; 
		for (int j = 0; j < M[i].size(); j++){
			if (j != ignore){
				m[ri][ci] = M[i][j];
				ci++;
			}
		}
		ri++;
	}
}

void PrintVector(vector <vector <int>> &M){
	for (int i = 0; i < M.size(); i++){
		for (int j = 0; j < M[i].size(); j++){
			cout << M[i][j] << " ";
		}
		cout << "\n";
	}
}

int Det(vector<vector <int>> &M){
	int Res = 0;
	for (int i = 0; i < M.size(); i++){
		vector <vector <int>> m(M.size() - 1);
		Copy(m, M, i);
		return Res += (M[0][i])*(Det(m))*(pow(-1, i));
	}
	return Res;
}

int DetWithCopy(vector<vector <int>> &M){
	if (M.size() == 1)
		return M[0][0];
	int Res = 0;
	for (int i = 0; i < M.size(); i++){
		vector <vector <int>> m(M.size() - 1);
		
		for (int ri = 1; ri < M.size(); ri++)
		{
			vector<int> ARow(M[ri]);
			ARow.erase(ARow.begin() + i);
			m[ri - 1] = ARow;
		}
		PrintVector(m);
		Res += (M[0][i])*(DetWithCopy(m))*(pow(-1, i));
	}
	return Res;
}


int main(){
	ifstream fin("Det.txt");
	int n;
	fin >> n;
	vector<vector<int>> M(n);
	for (int i = 0; i < n; i++)
	{
		vector<int> R(n);
		for (int j = 0; j < n; j++)
			fin >> R[j];
		M[i] = R;
	}
	cout << DetWithCopy(M) << endl;
	system("PAUSE");
	return 0;
}