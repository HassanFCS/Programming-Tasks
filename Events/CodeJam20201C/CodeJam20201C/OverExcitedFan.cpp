//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void ChgXY(int x, int y, string str, vector <vector <int>> &EState){
//	vector <int> state(2);
//	state[0] = x;
//	state[1] = y;
//	EState.push_back(state);
//	for (int i = 0; i < str.length(); i++){
//		if (str[i] == 'N')
//			y++;
//		else if (str[i] == 'S')
//			y--;
//		else if (str[i] == 'E')
//			x++;
//		else if (str[i] == 'W')
//			x--;
//		state[0] = x;
//		state[1] = y;
//		EState.push_back(state);
//	}
//}
//
//int ComputeRes(int &rx, int &ry, vector <vector <int>> &EState){
//	for (int i = 0; i < EState.size(); i++){
//		if (i >= abs(EState[i][0]) + abs(EState[i][1])){
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 1;
//	while (TC--){
//		int res;
//		int x, y;
//		int rx=0, ry=0;
//		string str;
//		cin >> x >> y;
//		cin >> str;
//		vector <vector <int>> EState;
//		ChgXY(x, y, str, EState);
//		res=ComputeRes(rx, ry, EState);
//		//for (int i = 0; i < EState.size(); i++)
//		//	cout << EState[i][0] << '\t' << EState[i][1] << '\n';
//		if (res==-1)
//			cout << "Case #" << CN << ": IMPOSSIBLE\n";
//		else
//			cout << "Case #" << CN << ": " << res << '\n';
//		CN++;
//
//	}
//	//system("PAUSE");
//	return 0;
//}