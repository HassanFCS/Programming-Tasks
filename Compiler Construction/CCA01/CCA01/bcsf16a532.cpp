//#include "iostream"
//#include "string"
//#include <conio.h>
//using namespace std;
//
//char NextState(char CS, char V){
//	if (V == '0'){
//		if (CS == 'A')
//			return 'B';
//		else if (CS == 'B')
//			return 'B';
//		else if (CS == 'C')
//			return 'D';
//		else if (CS == 'D')
//			return 'D';
//		else if (CS == 'E')
//			return 'F';
//		else if (CS == 'F')
//			return 'F';
//		else if (CS == 'G')
//			return 'F';
//	}
//	else if (V == '1'){
//		if (CS == 'A')
//			return 'E';
//		else if (CS == 'B')
//			return 'C';
//		else if (CS == 'C')
//			return 'C';
//		else if (CS == 'D')
//			return 'C';
//		else if (CS == 'E')
//			return 'E';
//		else if (CS == 'F')
//			return 'G';
//		else if (CS == 'G')
//			return 'G';
//	}
//}
//
//bool IsAccept(char LS){
//	if (LS == 'A' || LS == 'B' || LS == 'E' || LS == 'D' || LS == 'G')
//		return true;
//	else
//		return false;
//}
//
//bool IsValid(string A, int i, char Start){
//	if (i + 1 == A.length()){
//		char NS = NextState(Start, A[i]);
//		cout << NS;
//		return IsAccept(NS);
//	}
//	else{
//		char NS = NextState(Start, A[i]);
//		cout << NS << ' ';
//		i++;
//		return IsValid(A, i, NS);
//	}
//}
//
//int main(){
//	string Input="";
//	char SS = 'A';
//	Input = _getch();
//	cout << Input;
//	if (Input == "\r")
//	{
//		cout << "\nAccepted\n";
//	}
//	else
//	{
//		char ch = _getch();
//		while (ch != '\r')
//		{
//			cout << ch;
//			Input += ch;
//			ch = _getch();
//		}
//		cout << '\n' << SS << ' ';
//		if (IsValid(Input, 0, SS))
//			cout << "\nAccepted\n";
//		else
//			cout << "\nRejected\n";
//	}
//	system("pause");
//	return 0;
//}