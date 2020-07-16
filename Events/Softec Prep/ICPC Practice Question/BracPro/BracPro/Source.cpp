#include "iostream"
#include "string"
#include "string.h"
#include "fstream"
#include "vector"

using namespace std;

//bool CheckCount(string A){
//	int i = 0;
//	do{
//
//	} while (A[i] != '\0');
//}
//
//bool IsTrue(string A){
//	if ((A.length()-1) % 2 != 0)
//		return false;
//	else if (CheckCount(A))
//	
//}

//int main(){
//	string A;
//	cin >> A;
//	if (!IsTrue(A))
//		cout << '1';
//	else
//		cout << '0';
//	system("PAUSE");
//	return 0;
//}

bool CheckBrac(char A){
	if (A == ']')
		return true;
	else if (A == ')')
		return true;
	else if (A == '}')
		return true;
	else
		return false;
}

bool CheckLast(vector <int> & Vec, char A){
	int Size = Vec.size() - 1;
	if (Vec[Size] == A)
		return true;
	return false;
}

bool Check(vector <int> & A, string Val){
	int i = 1;
	do{
		if (CheckBrac(Val[i])){
			if (CheckLast(A, Val[i])){
				A.pop_back();
			}
			else
				return false;
		}
		i++;
		A.push_back(Val[i]);
	} while (Val[i] != '\0');
	A.pop_back();
	if (A.size() == 0)
		return true;
	else
		return false;
}

int main(){
	int i = 0;
	string Val;
	cin >> Val;
	vector <int> A;
	do{
		A.push_back(Val[i]);
		if (CheckBrac(Val[i]))
			cout << '0';
		else{
			if (Check(A, Val))
				cout << '1';
			else
				cout << '0';
		}
	} while (A.size() == 0);
	system("PAUSE");
	return 0;
}