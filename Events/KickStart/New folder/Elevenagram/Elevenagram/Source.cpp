#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool CheckEgram(string n){
	sort(n.begin(), n.end());
	do{
		int val = stoi(n);
		if (val % 11 == 0)
			return true;
	} while (next_permutation(n.begin(), n.end()));
	return false;
}

int main(){
	int TC;
	cin >> TC;
	for (int i = 0; i < TC; i++){
		string str = "";
		int no;
		for (int j = 1; j <= 9; j++){
			cin >> no;
			while (no>0){
				str += j + 48;
				no--;
			}
		}
		if (CheckEgram(str)){
			cout << "Case #" << i + 1 << ": YES\n";
		}
		else{
			cout << "Case #" << i + 1 << ": NO\n";

		}
	}
	system("PAUSE");
	return 0;
}