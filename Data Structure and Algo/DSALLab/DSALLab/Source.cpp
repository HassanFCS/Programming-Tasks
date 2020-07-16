#include "iostream"
#include "ctime"
using namespace std;

template <class t>
class Node{
public:
	t Data;
	Node *Next;
	Node(t D = 0, Node *N = NULL) {
		Data = D;
		Next = N;
	}
	Node(const Node <t> *N){
		Data = N->Data;
		Next = N->Next;
	}
};


template <class t>
class SLList{
	Node <t> *Head;
	Node <t> *Tail;
	void Print(Node <t> *T){
		if (T == NULL){
			return;
		}
		cout << T->Data << ' ';
		Print(T->Next);
	}
public:
	SLList(){
		Head = NULL;
		Tail = NULL;
	}

	SLList(t D){
		Head = new Node <t>(D);
		Tail = Head;
	}

	SLList(const SLList &Obj){
		this->AddNodes(Obj);
	}
	Node <t> GetHead(){
		return *Head;
	}
		
	void RemoveHead(){
		if (Head){
			Node <t> *Temp;
			Temp = Head->Next;
			delete Head;
			Head = Temp;
		}
	}
	
	void Print(){
		Print(Head);
	}

	void RemoveTail(){
		if (Head && Head->Next){
			Node <t> *Temp = Head;
			for (Temp; Temp->Next->Next != NULL; Temp = Temp->Next);
				delete Tail;
			Temp->Next = NULL;
			Tail = Temp;
			}
		else if (Head){
			delete Head->Next;
			Tail = Head;
		}
	}	
	
	void AddAtTail(t D){
		if (!Head)
			Tail = Head = new Node <t>(D, Head);
		else{
			Tail->Next = new Node <t>(D);
			Tail = Tail->Next;
		}
	}
	
	void Search(int Val){
		bool flag = true;
		if (Head->Data == Val){
			cout << "Yes " << Val << " Exist in the List.\n";
			flag = false;
		}
		for (Node <t> *t = Head; t->Next != NULL && flag; t = t->Next){
			if (t->Data == Val){
				cout << "Yes " << Val << " Exist in the List.\n";
				flag = false;
			}
		}
		if (flag)
			cout << Val << " Not Exist.\n";

	}

	SLList& operator=(const SLList &Obj){
		this->AddNodes(Obj);
		return *this;
	}
	
		template <class t>
		friend ostream &operator<<(ostream &,const SLList <t> &);
};
	
template <class t>
ostream &operator<<(ostream &out, const SLList <t> &Obj){
	for (Node <t> *T = Obj.Head; T != NULL; T = T->Next)
		out << T->Data << ' ';
	out << '\n';
	return out;
}

//int main(){
//	SLList <int> List;
//	List.AddAtTail(5);
//	List.AddAtTail(6);
//	List.AddAtTail(7);
//	List.Print();
//	cout << '\n';
//	List.RemoveTail();
//	List.Print();
//	cout << '\n';
//	List.Search(5);
//	List.RemoveHead();
//	List.Print();
//	cout << '\n';
//	List.Search(6);
//	List.Search(5);
//	system("PAUSE");
//	return 0;
//}

bool IsRepeat(int val, int A[],int Size){
	for (int i = 0; i < Size; i++){
		if (A[i] == val)
			return true;
	}
	return false;
}

int Hash(int Val){
	return Val % 20;
}

//int main(){
//	srand(time(0));
//	int Array[40];
//	for (int i = 0; i < 40; i++)
//		Array[i] = -1;
//	int N = 10;
//	for (int i = 0; i < 40; i++){
//		do{
//			N = (rand() % 90) + 10;
//		} while (IsRepeat(N, Array, 40));
//		Array[i] = N;
//	}
//	for (int i = 0; i < 40; i++)
//		cout << Array[i] << ' ';
//	SLList <int> LLA[20];
//	for (int i = 0; i < 20; i++){
//		LLA[Hash(Array[i])].AddAtTail(Array[i]);
//	}
//	cout << "\n\nPrint Array of LinkedList\n";
//	for (int i = 0; i < 20; i++){
//		LLA[i].Print();
//		cout << '\n';
//	}
//	cout << "\n\n";
//	system("PAUSE");
//	return 0;
//}

int left(int i){
	return (i + 1) * 2 - 1;
}
int right(int i){
	return (i + 1) * 2;
}
int parent(int i){
	return (i - 1) / 2;
}
void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void increaseKey(int *data, int i, int val){
	while (i != 0 && data[parent(i)] < data[i]){
		swap(data, i, parent(i));
		i = parent(i);
	}
}
void decreaseKey(int *data, int i, int size){
	while (left(i)< size){
		int largest = left(i);
		if (right(i)<size && data[right(i)]>data[left(i)])
			largest = right(i);
		if (data[i]<data[largest]){
			swap(data, i, largest);
			i = largest;
		}
		else return;
	}
}

int LastIndex(int *A,int Size){
	for (int i = 0; i < Size; i++){
		if (A[i] == -1)
			return i;
	}
}

void AddElement(int *A, int Size,int Element){
	int LI=LastIndex(A, Size);
	A[LI] = Element;
	increaseKey(A, LI, Element);
}

void RemoveElement(int *A, int Size, int Element){
	int LI = LastIndex(A, Size);
	A[0] = A[LI - 1];
	A[LI - 1] = -1;
	decreaseKey(A, LI - 1, 15);
}

int main(){
	int N;
	int Array[15] = { -1,-1,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1, -1, -1 };
	for (int i = 0; i < 15; i++){
		for (int i = 0; i < 15; i++){
			cout << Array[i] << ' ';
		}
		cout << '\n';
		cin >> N;
		AddElement(Array, 15, N);
	}
	cout << "Remove Elements.\n";
	for (int i = 0; i < 15; i++){
		for (int i = 0; i < 15; i++){
			cout << Array[i] << ' ';
		}
		cout << '\n';
		RemoveElement(Array, 15, 0);
	}
	system("PAUSE");
	return 0;
}