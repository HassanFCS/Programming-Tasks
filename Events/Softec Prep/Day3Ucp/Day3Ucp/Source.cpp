#include "iostream"
#include <vector>
#include <fstream>

using namespace std;

int MaxHor(int Ar[20][20], int &A, int &B, int &C, int &D){
	int Max = 0;
	for (int i = 0; i < 20; i++){
		for (int j = 3; j < 20; j++){
			int Res = Ar[i][j - 3] * Ar[i][j - 2] * Ar[i][j - 1] * Ar[i][j];
			if (Max < Res){
				Max = Res;
				A = Ar[i][j - 3];
				B = Ar[i][j - 2];
				C = Ar[i][j - 1];
				D = Ar[i][j];
			}
		}
	}
	return Max;
}

int MaxVer(int Ar[20][20], int &A, int &B, int &C, int &D){
	int Max = 0;
	for (int j = 0; j < 20; j++){
		for (int i = 3; i < 20; i++){
			int Res = Ar[i-3][j] * Ar[i-2][j] * Ar[i-1][j] * Ar[i][j];
			if (Max < Res){
				Max = Res;
				A = Ar[i-3][j];
				B = Ar[i-2][j];
				C = Ar[i-1][j];
				D = Ar[i][j];
			}
		}
	}
	return Max;
}

int maxMainDiagonal(vector <vector<int>> &nums, vector<int> &group){
	int max = 0;
	int product = 1;
	vector<int> temp;
	for (int i = 0; i < 17; ++i){
		for (int j = 0; j < 17; ++j){
			temp.clear();
			product = 1;
			for (int ii = i, jj = j; ii < i + 4; ++ii, ++jj){
				temp.push_back(nums[ii][jj]);
				product *= nums[ii][jj];
			}
			if (max < product){
				group.clear();
				for (int i = 0; i < 4; ++i){
					group.push_back(temp[i]);
				}
				max = product;
			}
				
		}
	}
	return max;
}

int main(){

	vector< vector<int> > nums;
	vector<int> group;

	nums.resize(20);
	for (int i = 0; i < 20; ++i){
		nums[i].resize(20);
	}

	ifstream in("Data.txt");

	for (int i = 0; i < 20; ++i){
		for (int j = 0; j < 20; ++j){
			in >> nums[i][j];
		}
	}
	
	int max = maxMainDiagonal(nums, group);
	for (int i = 0; i < 4; ++i){
		cout << group[i] << 'x';
	}
	
	cout << "\b = " << max << endl;

	system("pause");
	return 0;
}