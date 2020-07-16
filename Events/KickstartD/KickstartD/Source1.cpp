//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void Sol(vector <int> &AVs, vector <int> Vs){
//	AVs[0] = 1;
//	for (int i = 1; i < Vs.size(); i++)
//	{
//		AVs[i] = 1;
//		for (int j = 0; j < i; j++)
//			if (Vs[i] > Vs[j] && AVs[i] < AVs[j] + 1)
//				AVs[i] = AVs[j] + 1;
//	}
//	/*for (int i = 0; i < AVs.size(); i++){
//			cout << AVs[i] << " ";
//	}
//	cout << '\n';*/
//}
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 1;
//	while (TC--){
//		int	n;
//		cin >> n;
//		vector <int> Vs(n);
//		vector <int> AVs(n,0);
//		vector <int> IVs(n, 0);
//		int res = 0;
//		for (int i = 0; i < n; i++){
//			cin >> Vs[i];
//		}
//		Sol(IVs, Vs);
//		AVs[0] = 1;
//		for (int i = 1; i < Vs.size(); i++){
//			if (IVs[i]>IVs[i - 1]){
//				AVs[i] = AVs[i - 1] + 1;
//				if (AVs[i]>4){
//					res++;
//					AVs[i]=1;
//				}
//			}
//			else
//				AVs[i] = 1;
//		}
//		/*for (int i = 0; i < AVs.size(); i++){
//			cout << AVs[i] << " ";
//		}
//		cout << '\n';*/
//		cout << "Case #" << CN << ": " << res << '\n';
//		CN++;
//	}
//	system("PAUSE");
//	return 0;
//}



#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++){
		int n;
		cin >> n;
		int l = 0, s = 0;
		int prev = 0;
		int count = 0;
		while (n--){
			int x;
			cin >> x;
			if (prev == 0)
				prev = x;
			else if (prev>x){
				l++;
				if (abs(l - s) == 4){
					l = 0;
					s = 0;
					count++;
				}
			}
			else if (prev<x){
				s++;
				if (abs(l - s) == 4){
					l = 0;
					s = 0;
					count++;
				}
			}
			prev = x;
		}
		cout << "Case #" << i << ": " << count << endl;
	}
	return 0;
}