//#include "iostream"
//
//using namespace std;
//
//template <class t>
//class Node{
//public:
//	t Data;
//	Node *Next;
//	Node(t D = 0, Node *N = NULL) {
//		Data = D;
//		Next = N;
//	}
//	Node(const Node <t> *N){
//		Data = N->Data;
//		Next = N->Next;
//	}
//};
//
//template <class t>
//class SLList{
//	Node <t> *Head;
//	Node <t> *Tail;
//	void PrintReverse(Node <t> *T){
//		if (T == NULL){
//			return;
//		}
//		PrintReverse(T->Next);
//		cout << T->Data << ' ';
//	}
//public:
//	SLList(){
//		Head = NULL;
//		Tail = NULL;
//	}
//
//	SLList(t D){
//		Head = new Node <t> (D);
//		Tail = Head;
//	}
//
//	SLList(const SLList &Obj){
//		this->AddNodes(Obj);
//	}
//
//	Node <t> GetHead(){
//		return *Head;
//	}
//
//	void AddAtHead(t D){
//		if (!Head)
//			Tail = Head = new Node <t> (D, Head);
//		else
//			Head = new Node <t> (D, Head);
//	}
//
//	void RemoveHead(){
//		if (Head){
//			Node <t> *Temp;
//			Temp = Head->Next;
//			delete Head;
//			Head = Temp;
//		}
//	}
//
//	void RemoveTail(){
//		if (Head && Head->Next){
//			Node <t> *Temp = Head;
//			for (Temp; Temp->Next->Next != NULL; Temp = Temp->Next);
//			delete Tail;
//			Temp->Next = NULL;
//			Tail = Temp;
//		}
//		else if (Head){
//			delete Head->Next;
//			Tail = Head;
//		}
//	}
//
//	void InsertAfter(t D, Node <t> Add){
//		Node <t> *Temp = Head;
//		Node <t> *Temp1;
//		for (Temp; Temp != NULL; Temp = Temp->Next){
//			if (Temp->Data == D){
//				Temp1 = Temp->Next;
//				Temp->Next = new Node <t>(Add);
//				Temp->Next->Next = Temp1;
//				break;
//			}
//		}
//	}
//
//	void InsertBefore(t D, Node <t> Add){
//		Node <t> *Temp = Head;
//		Node <t> *Temp1;
//		if (Head->Next){
//			for (Temp; Temp != NULL; Temp = Temp->Next){
//				if (Temp->Next->Data == D) {
//					Temp1 = Temp->Next;
//					Temp->Next = new Node <t>(Add);
//					Temp->Next->Next = Temp1;
//					break;
//				}
//			}
//		}
//		else{
//			if (Head->Data == D){
//				Temp1 = Head;
//				Head = new Node <t>(Add);
//				Head->Next = Temp1;
//			}
//		}
//	}
//
//	void PrintReverse(){
//		PrintReverse(Head);
//	}
//
//	void DeleteAllNodes(){
//		if (Head == NULL)
//			return;
//		Head = Head->Next;
//		DeleteAllNodes();
//		delete Head;
//	}
//
//	SLList& AddNodes(const SLList &Obj){
//		Node <t> *T;
//		Node <t> *Y;
//		Y = Obj.Head;
//		if (!Obj.Head)
//			return *this;
//		if (!Head){
//			Head = new Node <t>(Obj.Head->Data);
//			Y = Obj.Head->Next;
//		}
//		for (T = Head; T->Next != NULL; T = T->Next);
//		for (; Y != NULL; Y = Y->Next, T = T->Next)
//			T->Next = new Node <t>(Y->Data);
//		Tail = T;
//		return *this;
//	}
//
//	void AddAtTail(t D){
//		if (!Head)
//			Tail = Head = new Node <t>(D, Head);
//		else{
//			Tail->Next = new Node <t>(D);
//			Tail = Tail->Next;
//		}
//	}
//
//	SLList& operator=(const SLList &Obj){
//		this->AddNodes(Obj);
//		return *this;
//	}
//
//	template <class t>
//	friend ostream &operator<<(ostream &,const SLList <t> &);
//};
//
//template <class t>
//ostream &operator<<(ostream &out, const SLList <t> &Obj){
//	for (Node <t> *T = Obj.Head; T != NULL; T = T->Next)
//		out << T->Data << ' ';
//	out << '\n';
//	return out;
//}
//
////ADDNODES || Copy || Assignment Operator..!!
////Sort
//
//int main(){
//	SLList <int> List0(1);
//	SLList <int> List1;
//	List0.AddAtHead(1);
//	List0.AddAtHead(0);
//	List0.AddAtHead(2);
//	List0.AddAtTail(3);
//	List0.AddAtTail(4);
//	List1.AddAtHead(1);
//	List1.AddAtHead(0);
//	List1.AddAtHead(2);
//	List1.AddAtTail(3);
//	List1.AddAtTail(4);
//	cout << List0 << List1;
//	List0.DeleteAllNodes();
//	List1.RemoveHead();
//	cout << List0 << List1;
//	List1.RemoveTail();
//	cout << List1;
//	Node <int> Samp(25);
//	List1.InsertAfter(0, Samp);
//	cout << List1;
//	Node <int> Samp1(20);
//	List1.InsertAfter(3, Samp1);
//	cout << List1;
//	Node <int> Samp2(30);
//	List1.InsertBefore(20, Samp2);
//	cout << List1;
//	SLList <int> List2(0);
//	Node <int> Samp3(35);
//	List2.InsertBefore(0, Samp3);
//	cout << List2 << '\n';
//	cout << List2.AddNodes(List1);
//	cout << List0.AddNodes(List1);
//	List0.PrintReverse();
//	List0.RemoveTail();
//	cout << '\n';
//	cout << List0;
//	cout << List2;
//	List2.RemoveTail();
//	cout << List2;
//	SLList <int> List3;
//	List3 = List2;
//	cout << List3;
//	SLList <int> List4(List3);
//	cout << List4;
//	return 0;
//}