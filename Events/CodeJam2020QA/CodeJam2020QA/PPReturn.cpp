//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//
//
//using namespace std;
//
//void sort(int **Vs, int N){
//	for (int i = 0; i < N; i++){
//		int min = 2147483647;
//		int mini = 0;
//		for (int j = i; j < N; j++){
//			if (min>Vs[j][1]){
//				mini = j;
//				min = Vs[j][1];
//			}
//		}
//		swap(Vs[i], Vs[mini]);
//	}
//}
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 0;
//	while (TC--){
//		CN++;
//		int N;
//		cin >> N;
//		int **CSETime = new int*[N];
//		for (int i = 0; i < N; i++){
//			CSETime[i] = new int[2];
//		}
//		int **SETime = new int*[N];
//		for (int i = 0; i < N; i++){
//			SETime[i] = new int[3];
//		}
//		for (int i = 0; i < N; i++){
//			SETime[i][0] = i;
//			cin >> SETime[i][1] >> SETime[i][2];
//		}
//		sort(SETime, N);
//		int CE=0, JE=0;
//		string str = "C";
//		CE = SETime[0][2];
//		for (int i = 1; i < N; i++){
//			if (SETime[i][1] < CE){
//				if (SETime[i][1] < JE){
//					str = "IMPOSSIBLE";
//					break;
//				}
//				else{
//					str += "J";
//					JE = SETime[i][2];
//				}
//			}
//			else{
//				str += "C";
//				CE = SETime[i][2];
//			}
//		}
//		string res = "";
//		if (str != "IMPOSSIBLE"){
//			for (int i = 0; i < N; i++){
//				for (int j = 0; j < N; j++){
//					if (i == SETime[j][0])
//						res += str[j];
//				}
//			}
//		}
//		else{
//			res = "IMPOSSIBLE";
//		}
//		cout << "Case #" << CN << ": " << res << '\n';
//	}
//	system("PAUSE");
//	return 0;
//}
