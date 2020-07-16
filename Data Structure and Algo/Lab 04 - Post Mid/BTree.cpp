#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

template <class T>
T findMax(T a, T b){
	if (a>b)	return a;
	else		return b;
}
template <class T>
class BST{
	class TNode{//An inner class available to its outer class only, thus to keep data members public is safe
		public:
			T data;
			TNode *left, *right;
			TNode(T d, TNode *lt=NULL, TNode *rt=NULL){
				data=d;
				left=lt;
				right=rt;
			}
	};
	TNode *root;
public:
	BST(){	root=NULL;	}
	void add(T d){	root=add(root, d);	}
	TNode* add(TNode *t, T d){		
		if (t==NULL)			t=new TNode(d);
		else if (t->data==d)	return t;	
		else if (t->data>d)		t->left=add(t->left, d);
		else					t->right=add(t->right, d);
		return t;
	}
	void inOrder(){	inOrder(root);		cout<<'\n';	}
	void inOrder(TNode *t){
		if (t){
			inOrder(t->left);
			cout<<t->data<<' ';
			inOrder(t->right);
		}
	}
};
int main(){
	srand((unsigned int)time(0));
	BST <int> tree;
	int i;
	for (i=0;i<10;i++)
		tree.add(rand()%100);
	tree.inOrder();
	return 0;
}
