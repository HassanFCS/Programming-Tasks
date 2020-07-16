//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void PrimeSieve(vector <bool> &Prime){
//	int n = Prime.size() - 1;
//	for (int i = 2; i*i < n + 1; i++){
//		if (Prime[i]){
//			for (int j = i*i; j < n + 1; j += i)
//				Prime[j] = false;
//		}
//	}
//}
//
//int PrintCentury(vector <bool> &Vs, int n){
//	int count = 0;
//	int res = 0;
//	for (int i = 2; i <= Vs.size(); i++){
//		if (Vs[i]){
//			count++;
//			if (count == 100){
//				res++;
//				count = 0;
//			}
//		}
//		if (i == n)
//			break;
//	}
//	return res;
//}
//
//int main(){
//	vector <bool> Vs(10000001, true);
//	int TC;
//	PrimeSieve(Vs);
//	cout << "Test Cases : ";
//	cin >> TC;
//	for (int i = 0; i < TC; i++){
//		int n;
//		cin >> n;
//		if (n >= 2)
//			cout << PrintCentury(Vs, n) << '\n';
//		else
//			cout << -1 << '\n';
//	}
//	system("PAUSE");
//	return 0;
//}