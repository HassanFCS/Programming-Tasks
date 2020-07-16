#include "iostream"

using namespace std;

template <class t>
class Node{
public:
	t Data;
	Node *Next;
	Node *Previous;
	Node(t D = 0, Node *N = NULL, Node *P = NULL){
		Data = D;
		Next = N;
		Previous = P;
	}
	Node(const Node <t> *N){
		Data = N->Data;
		Next = N->Next;
		Previous = N->Previous;
	}
};

template <class t>
class DLList{
	Node <t> *Head;
	Node <t> *Tail;
public:
	DLList(){
		Head = NULL;
		Tail = NULL;
	}
	DLList(t D){
		Head = new Node <t>(D);
		Tail = Head;
	}
	void AddAtHead(t D){
		if (!Head)
			Tail = Head = new Node <t>(D);
		else{
			Head = new Node <t> (D, Head);
			Head->Next->Previous = Head;
		}
	}
	void RemoveHead(){
		Node <t> *Temp = Head;
		Head = Head->Next;
		Head->Previous = NULL;
		delete Temp;
	}
	void RemoveTail(){
		Node <t> *Temp = Tail;
		Tail = Tail->Previous;
		Tail->Next = NULL;
		delete Temp;
	}
	void AddAtTail(t D){
		if (!Head)
			Tail = Head = new Node <t>(D);
		else{
			Tail = new Node <t>(D,NULL,Tail);
			Tail->Previous->Next = Tail;
		}
	}

	///*void InsertAfter(t D, Node <t> Add){
	//	Node <t> *Temp = Head;
	//	Node <t> *Temp1;
	//	for (Temp; Temp != NULL; Temp = Temp->Next){
	//		if (Temp->Data == D){
	//			Temp1 = Temp->Next;
	//			Temp->Next = new Node <t>(Add);
	//			Temp->Next->Next = Temp1;
	//			Temp1->Previous = Temp->Next;
	//			break;
	//		}
	//	}
	//}*/

	void Print(){
		Node <t> *Temp = Head;
		for (Temp; Temp != NULL; Temp=Temp->Next){
			cout << Temp->Data << ' ';
		}
		cout << '\n';
	}
	void PrintReverse(){
		Node <t> *Temp = Tail;
		for (Temp; Temp != NULL; Temp = Temp->Previous){
			cout << Temp->Data << ' ';
		}
		cout << '\n';
	}
	/*template <class t>
	friend ostream &operator<<(ostream &,const SLList <t> &);*/
};

//template <class t>
//ostream &operator<<(ostream &out, const DLList <t> &Obj){
//	for (Node <t> *T = Obj.Head; T != NULL; T = T->Next)
//		out << T->Data << ' ';
//	out << '\n';
//	return out;
//}

int main(){
	DLList <int> Obj;
	Obj.AddAtHead(10);
	Obj.AddAtHead(20);
	Obj.AddAtHead(30);
	Obj.AddAtTail(0);
	Obj.AddAtTail(-10);
	Obj.AddAtTail(-20);
	Obj.Print();
	Obj.PrintReverse();
	Obj.RemoveHead();
	Obj.RemoveHead();
	Obj.Print();
	Obj.PrintReverse();
	Obj.RemoveTail();
	Obj.RemoveTail();
	Obj.Print();
	Node <int> Obj1(45);
	Obj.PrintReverse();
	Obj.RemoveTail();
	Obj.Print();
	return 0;
}