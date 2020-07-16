//////#include <iostream>
//////#include <string>
//////
//////using namespace std;
//////
//////string Add(string A, string B){
//////	return A + B;
//////}
//////
//////string getString(char x)
//////{
//////	string s(1, x);
//////	return s;
//////}
//////
//////string AInverese(string A, string B){
//////	char FL = B[0];
//////	string Res;
//////	Res = Res + getString(FL);
//////	for (int i = 1; i < A.size(); i++){
//////		Res = Res + A[i];
//////	}
//////	return Res;
//////}
//////
//////string BInverese(string A, string B){
//////	char FL = A[0];
//////	string Res;
//////	Res = Res + getString(FL);
//////	for (int i = 1; i < B.size(); i++){
//////		Res = Res + B[i];
//////	}
//////	return Res;
//////}
//////
//////int main(){
//////	string A, B;
//////	cin >> A >> B;
//////	cout << A.size() << " " << B.size() << '\n';
//////	cout << Add(A, B) << '\n';
//////	cout << AInverese(A, B) << ' ' << BInverese(A, B) << '\n';
//////	//system("PAUSE");
//////	return 0;
//////}
////
////
////
////
////
////
////
////
////
////#include <sstream>
////#include <vector>
////#include <iostream>
////using namespace std;
////
////vector<int> parseInts(string str) {
////	vector <int> Res;
////	string S;
////	for (int i = 0; i < str.size(); i++){
////		if (str[i] != ','){
////			S = S + str[i];
////		}
////		else{
////			int x;
////			stringstream geek(S);
////			geek >> x;
////			Res.push_back(x);
////			S = "";
////		}
////	}
////	int x;
////	stringstream geek(S);
////	geek >> x;
////	Res.push_back(x);
////	return Res;
////}
////
////int main() {
////	string str;
////	cin >> str;
////	vector<int> integers = parseInts(str);
////	for (int i = 0; i < integers.size(); i++) {
////		cout << integers[i] << "\n";
////	}
////	//system("PAUSE");
////	return 0;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//#include <iostream>
//#include <sstream>
//using namespace std;
//
//class Student{
//private:
//	int age;
//	int standard;
//	string first_name;
//	string last_name;
//public:
//	void set_age(int a){
//		age = a;
//	}
//	void set_standard(int s){
//		standard = s;
//	}
//	void set_first_name(string fn){
//		first_name = fn;
//	}
//	void set_last_name(string ln){
//		last_name = ln;
//	}
//	int get_age() { return age; }
//	int get_standard() { return standard; }
//	string get_first_name() { return first_name; }
//	string get_last_name() { return last_name; }
//	string to_string(){
//		string Res;
//		stringstream SS;
//		SS << age;
//		Res = SS.str() + ",";
//		Res = Res + first_name + ",";
//		Res = Res + last_name + ",";
//		SS.str("");
//		SS << standard;
//		Res = Res + SS.str();
//		return Res;
//	}
//};
//
//int main() {
//	int age, standard;
//	string first_name, last_name;
//
//	cin >> age >> first_name >> last_name >> standard;
//
//	Student st;
//	st.set_age(age);
//	st.set_standard(standard);
//	st.set_first_name(first_name);
//	st.set_last_name(last_name);
//
//	cout << st.get_age() << "\n";
//	cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
//	cout << st.get_standard() << "\n";
//	cout << "\n";
//	cout << st.to_string();
//
//	return 0;
//}


//#include <iostream>
//#include <deque> 
//using namespace std;
//
//int Max(deque <int> mydeque){
//	int m = -99999;
//	for (int i = 0; i<mydeque.size(); i++){
//		if (m<mydeque[i])
//			m = mydeque[i];
//	}
//	return m;
//}
//
//void printKMax(int arr[], int n, int k){
//	//Write your code here.
//	deque <int> mydeque;
//	for (int i = 0, j = 0; i<n; i++){
//		mydeque.push_back(arr[i]);
//		j++;
//		if (j == k){
//			cout << Max(mydeque) << " ";
//			j--;
//			mydeque.pop_front();
//		}
//	}
//	cout << '\n';
//}
//
//int main(){
//
//	int t;
//	cin >> t;
//	while (t>0) {
//		int n, k;
//		cin >> n >> k;
//		int i;
//		int *arr=new int[n];
//
//		for (i = 0; i<n; i++)
//			cin >> arr[i];
//		printKMax(arr, n, k);
//		t--;
//	}
//	system("PAUSE");
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//string isValid(string s) {
//	vector <int>Vs(26, 0);
//	for (int i = 0; i<s.size(); i++)
//		Vs[s[i] - 'a']++;
//	bool flag1 = false;
//	bool flag2 = false;
//	int min;
//	for (int i = 0; i<s.size(); i++){
//		if (Vs[i]>0){
//			if (flag1 == false){
//				min = Vs[i];
//				flag1 = true;
//			}
//			if (flag2 == false && abs(min - Vs[i])>0)
//				flag2 = true;
//			else if ((flag2) && (abs(min - Vs[i])>0))
//				return "NO";
//		}
//	}
//	return "YES";
//}
//
//int main(){
//	string str;
//	cin >> str;
//	cout << isValid(str) << '\n';
//	system("PAUSE");
//	return 0;
//}
