//#include "iostream"
//
//using namespace std;
//
//template <class t>
//class Stack{
//	t *Data;
//	int P, Size;
//public:
//	Stack(int S=0){
//		Data = new t [S];
//		Size = S;
//		P = 0;
//	}
//	t Pop(){
//		return Data[--P];
//	}
//	bool IsFull(){
//		return P == Size;
//	}
//	void Push(t D){
//		if (!IsFull())
//			Data[P++] = D;
//	}
//	t SeeTop(){
//		return Data[P - 1];
//	}
//	bool IsEmpty(){
//		return P == 0;
//	}
//};
//
//int main(){
//	Stack <int> St(10);
//	if (St.IsEmpty()){
//		St.Push(25);
//	}
//	St.Push(20);
//	cout << St.SeeTop() << '\n';
//	St.Push(30);
//	cout << St.Pop() << '\n';
//	cout << St.Pop() << '\n';
//	cout << St.Pop() << '\n';
//	if (St.IsEmpty())
//		St.Push(1);
//	cout << St.SeeTop() << '\n';
//	return 0;
//}