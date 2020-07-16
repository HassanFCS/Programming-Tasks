#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//unsigned long long int MaxTill(vector <int> Vs, int ind){
//	unsigned long long  MovTill = ceil(Vs.size() / 2.0) - 1;
//	unsigned long long  Sum = 0;
//	for (unsigned long long k = ind; k <= ind + MovTill; k++){
//		Sum += Vs[k];
//	}
//	return Sum;
//}
//
//int main(){
//	int g = 0;
//	int TC;
//	cin >> TC;
//	while (TC > g){
//		int Size;
//		cin >> Size;
//		vector <int> Vs(Size);
//		char ch;
//		for (int i = 0; i < Size; i++){
//			cin >> ch;
//			Vs[i] = ch - 48;
//		}
//		unsigned long long int Max, CMax;
//		Max = MaxTill(Vs, 0);
//		if (Vs.size() == 2){
//			if (Vs[0]>Vs[1])
//				Max = Vs[0];
//			else
//				Max = Vs[1];
//		}
//		else{
//			for (int j = 0; j < Size / 2 - 1; j++){
//				CMax = MaxTill(Vs, j + 1);
//				if (Max < CMax)
//					Max = CMax;
//			}
//		}
//		cout << "Case #" << g + 1 << ": " << Max << '\n';
//		g++;
//	}
//	return 0;
//}

unsigned long long int max(unsigned long long int a, unsigned long long int b){
	if (a < b)
		return b;
	else
		return a;
}
						//O(n) Solution
int main(){
	int TC;
	cin >> TC;
	int T = 0;
	while (TC > T){
		int Size;
		cin >> Size;
		vector <unsigned long long int> Vs(Size);
		char ch;
		for (int i = 0; i < Size; i++){
			cin >> ch;
			Vs[i] = ch - 48;
		}
		unsigned long long int Max = 0;
		if (Vs.size() == 2){
			if (Vs[0]>Vs[1])
				Max = Vs[0];
			else
				Max = Vs[1];
		}
		else{
			int Till = ceil(Size / 2.0);
			for (int j = 0; j < Till; j++){
				Max += Vs[j];
			}
			unsigned long long int CMax = Max;
			for (int k = Till; k < Size; k++){
				CMax += Vs[k] - Vs[k - Till];
				Max = max(Max, CMax);
			}
		}
		cout << "Case #" << T + 1 << ": " << Max << '\n';
		T++;
	}
	system("PAUSE");
	return  0;
}