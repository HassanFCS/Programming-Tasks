#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

template <class T>
T findMax(T a, T b){
	if (a>b)
		return a;
	else
		return b;
}

template <class T>
class BST{
	class TNode{//An inner class available to its outer class only, thus to keep data members public is safe
	public:
		T data;
		TNode *left, *right;
		TNode(T d, TNode *lt = NULL, TNode *rt = NULL){
			data = d;
			left = lt;
			right = rt;
		}
	};
	TNode *root;
	void findSum(TNode *t, int &Sum){
		if (t){
			Sum += t->data;
			findSum(t->left,Sum);
			findSum(t->right,Sum);
		}
	}
	int maxDepth(TNode *Node)
	{
		if (Node == NULL)
			return 0;
		else
		{
			/* compute the depth of each subtree */
			int LH = maxDepth(Node->left);	//MaxHeight on Left of Node.
			int RH = maxDepth(Node->right);	//MaxHeight on right of Node.

			/* use the larger one */
			if (LH > RH)
				return 1 + LH;
			else
				return 1 + RH;
		}
	}
	void inOrder(TNode *t){
		if (t){
			inOrder(t->left);
			cout << t->data << ' ';
			inOrder(t->right);
		}
	}
	void preOrder(TNode *t){
		if (t){
			cout << t->data << ' ';
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void postOrder(TNode *t){
		if (t){
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << ' ';
		}
	}
	int findMin(TNode *t){
		if (t->left == NULL)
			return t->data;
		else
			findMin(t->left);
	}
	int findMax(TNode *t){
		if (t->right == NULL)
			return t->data;
		else
			findMax(t->right);
	}
	
	TNode * Delete(int d, TNode* t)
	{

		if (t->data == d && t->left == NULL && t->right == NULL)
			delete t;
		else if (t->data == d && t->left == NULL)
		{
			swap(t->right->data, t->data);
			t->right = Delete(d, t->right);
		}
		else if (t->data == d && t->right == NULL)
		{
			swap(t->left->data, t->data);
			t->left = Delete(d, t->left);
		}
		else if (t->data == d)
		{
			swap(t->left->data, t->data);
			t = t->left;
			t->right = Delete(d, t->right);
		}
		return t;
	}

public:
	BST(){
		root = NULL;
	}

	void add(T d){	//Wrapper Function It will call from main function.
		root = add(root, d);
	}

	TNode* add(TNode *t, T d){
		if (t == NULL)
			t = new TNode(d);
		else if (t->data == d)//if a Number repeat.	
			return t;
		else if (t->data>d)
			t->left = add(t->left, d);
		else
			t->right = add(t->right, d);
		return t;
	}

	void inOrder(){
		inOrder(root);
		cout << '\n';
	}

	void preOrder(){
		preOrder(root);
		cout << '\n';
	}

	void postOrder(){
		postOrder(root);
		cout << '\n';
	}

	void Sum(){
		int Sum = 0;
		findSum(root, Sum);
		cout << Sum << '\n';
	}
	int Height(){
		return maxDepth(root);
	}
	int findMin(){
		return findMin(root);
	}
	int findMax(){
		return findMax(root);
	}
	void Delete(int d)
	{
		root = Delete(d, root);
	}
	//Array Implementation to find sum of Array.
	//void findSum(int *x, int i, int &sum, const int SIZE){
	//	if (i>SIZE) return;//array finished, therefore no more function calls
	//	sum += x[i]; //add current element into sum
	//	findSum(x, i + 1, sum, SIZE);
	//}
	//int findSum(int *x, const int SIZE){
	//	int sum = 0;
	//	findSum(x, 0, sum, SIZE);
	//	return sum;
	//}

};
int main(){
	srand((unsigned int)time(0));
	BST <int> tree;
	int i;
	cout << "Tree : ";
	for (i = 0; i < 10; i++){
		int val = rand() % 100;
		cout << val << ' ';
		tree.add(val);
	}
	cout << "\nInOrder : ";
	tree.inOrder();
	cout << "PreOrder : ";
	tree.preOrder();
	cout << "PostOrder : ";
	tree.postOrder();
	//cin >> i;
	//tree.Delete(i);
	cout << "Height : " << tree.Height() << '\n';
	tree.Sum();
	cout << tree.findMin() << '\n';
	cout << tree.findMax() << '\n';
	system("pause");
	return 0;
}
