#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;

template <class T>
T findMax(T a, T b) {
	if (a>b)	return a;
	else		return b;
}

template <class T>
class BST {
	class TNode {
	public:
		T Data;
		TNode *left, *right;
		TNode(T d) {
			Data = d;
			left = right = NULL;
		}
	};
	TNode *Root;
	int LeftSubTree(int A[], int Size, int Start) {
		int Res = 0;
		if (Size < Start || A[Start] == -1)
			return 0;
		int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
		int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
		if (Res1 < Res2)
			return Res2;
		else
			return Res1;
	}

	int RightSubTree(int A[], int Size, int Start) {
		if (Size < Start || A[Start] == -1)
			return 0;
		int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
		int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
		if (Res1 < Res2)
			return Res2;
		else
			return Res1;
	}

	int HeightofTree(int A[], int Size, int Start) {
		if (A[Start] == -1)
			return 0;
		int Res1 = 1 + LeftSubTree(A, Size, (Start + 1) * 2 - 1);
		int Res2 = 1 + RightSubTree(A, Size, (Start + 1) * 2);
		if (Res1 < Res2)
			return Res2;
		else
			return Res1;
	}
	void Sum(TNode *t,int &S) {
		if (t) {
			Sum(t->left,S);
			S += t->Data;
			Sum(t->right,S);
		}
	}
	bool IsEvenExist(TNode *T) {
		if (T) {
			IsEvenExist(T->left);
			if (T->Data % 2 == 0) {
				return true;
			}
			IsEvenExist(T->right);
		}
	}
public:
	BST() {
		Root = NULL;
	}
	void Add(T d) {
		Root = Add(Root, d);
	}
	TNode* Add(TNode *t, T d) {
		if (t == NULL)
			t = new TNode(d);
		else if (t->Data == d)
			return t;
		else if (t->Data > d)
			t->left = Add(t->left, d);
		else
			t->right = Add(t->right, d);
		return t;
	}
	void InOrder() {
		InOrder(Root);
	}
	void InOrder(TNode *t) {
		if (t) {
			InOrder(t->left);
			cout << t->Data << ' ';
			InOrder(t->right);
		}
	}
	
	int HeightofTree(int A[], int Size) {
		return HeightofTree(A, 15, 0);
	}

	int Sum() {
		int S = 0;
		Sum(Root,S);
		return S;
	}

	bool IsEvenExist() {
		return IsEvenExist(Root);
	}
};

bool IsExist(int Ar[], int Val, int ind) {
	for (int j = 0; j < ind; j++) {
		if (Ar[j] == Val)
			return true;
	}
	return false;
}

int main() {
	srand((unsigned int)time(0));
	BST <int> Tree;
	int i, val;
	int Array[15];
	for (int i = 0; i < 15; i++) {
		val = rand() % 100;
		Array[i] = val;
		Tree.Add(val);
	}
	Tree.InOrder();
	cout << '\n' << Tree.HeightofTree(Array, 15) << '\n';
	cout << Tree.Sum() << '\n';
	if (Tree.IsEvenExist()) 
		cout << "Even Value Exist\n";
	else
		cout << "No Even Value\n";
	//tree.preOrder();				 
	//cout<<"Height:"<<tree.height()<<'\n';
	//cout<<"Sum:"<<tree.sum()<<'\n';
	/*cout<<"Event Element Exist:";
	if (tree.isEvenElementExist())   cout<<"Yes\n";
	else   cout<<"No\n";*/
	return 0;
}