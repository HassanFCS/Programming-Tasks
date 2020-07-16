//#include <iostream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//int main(){
//	int TC;
//	cin >> TC;
//	int CN = 0;
//	while (TC--){
//		CN++;
//		string str;
//		cin >> str;
//		stack <char> St;
//		string res = "";
//		for (int i = 0; i < str.length(); i++){
//			if (St.size() == (str[i]-'0')){
//				res += str[i];
//			}
//			else if (St.size() > (str[i] - '0')){
//				for (int j = 0; St.size() > (str[i] - '0');){
//					St.pop();
//					res += ')';
//				}
//				res += str[i];
//			}
//			else{
//				for (int j = 0; St.size() < (str[i] - '0');){
//					St.push(')');
//					res += '(';
//				}
//				res += str[i];
//			}
//		}
//		for (int k = 0; St.size()>0;){
//			res += ')';
//			St.pop();
//		}
//		cout << "Case #" << CN << ": " << res << '\n';
//	}
//	system("PAUSE");
//	return 0;
//}