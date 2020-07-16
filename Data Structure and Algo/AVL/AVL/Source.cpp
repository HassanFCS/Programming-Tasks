#include "iostream"
#include <conio.h>
using namespace std;
class Node {
public:
	int data;
	Node *right;
	Node *left;
	int height;
	Node(int d, Node *r, Node *l)
	{
		data = d;
		right = r;
		left = l;
	}
};

class AVL {
private:
	Node * root;
	int bf;
public:
	AVL()
	{
		root = NULL;
	}
	Node *rotateRight(Node *t)
	{
		Node *p = t->left;
		t->left = p->right;
		p->right = t;
		return p;
	}
	Node *rotateLeft(Node *t)
	{
		Node *p = t->right;
		t->right = p->left;
		p->left = t;
		return p;
	}
	int height(Node *t)
	{
		if (t)
			return t->height;
		return 0;
	}
	int max(int a, int b)
	{
		if (a > b)
			return a;
		return b;
	}
	void addNode(int d)
	{
		root = addNode(d, root);
	}
	Node *addNode(int d, Node *t)
	{
		if (t == NULL)
			t = new Node(d, NULL, NULL);
		else if (t->data == d)
			t = t;
		else if (t->data > d)
			t->left = addNode(d, t->left);
		else if (t->data < d)
			t->right = addNode(d, t->right);
		int rbf = 0;
		bf = height(t->left) - height(t->right);
		if (bf == +2)
		{
			rbf = height(t->left->left) - height(t->left->right);
			if (rbf >= 0)
				t = rotateRight(t);
			else if (rbf == -1)
			{
				t->left = rotateLeft(t->left);
				t = rotateRight(t);
			}
		}
		else if (bf == -2)
		{
			rbf = height(t->right->left) - height(t->right->right);
			if (rbf <= 0)
				t = rotateLeft(t);
			else if (rbf == +1)
			{
				t->right = rotateRight(t->right);
				t = rotateLeft(t);
			}
		}
		t->height = 1 + max(height(t->left), height(t->right));
		return t;
	}
	void InOrder() 
	{
		InOrder(root);
		cout << '\n';
	}
	void PreOrder()
	{
		PreOrder(root);
		cout << '\n';
	}
	void InOrder(Node *t)
	{
		if (t)
		{
			InOrder(t->left);
			cout << t->data << ' ';
			InOrder(t->right);
		}
	}
	void PreOrder(Node *t)
	{
		if (t)
		{
			cout << t->data << ' ';
			PreOrder(t->left);
			PreOrder(t->right);
		}
	}

	void PrintTree()
	{
		system("cls");
		RecPrintTree(root, 0);
		_getch();

	}
	void RecPrintTree(Node *t, int h)
	{
		if (!t) return;
		RecPrintTree(t->right, h + 1);

		for (int i = 0; i < h; i++)
		{
			cout << "\t";
		}
		cout << t->data<<endl;

		RecPrintTree(t->left, h + 1);
	}

	void Delete(int d)
	{
		root = Delete(d, root);
	}
	Node *findLeftMost(Node *r)
	{
		if (r->left == NULL)
			return r;
		return findLeftMost(r->left);
	}
	Node *Delete(int d, Node*r)
	{
		if (r)
		{
			if (r->data == d)
			{
				if (r->left == NULL && r->right == NULL)
				{
					delete r;
					r = NULL;
				}
				else if (r->left != NULL && r->right != NULL)
				{
					Node *l = findLeftMost(r->right);
					r->data = l->data;
					Delete(l->data, l);
				}
				else if (r->left != NULL)
				{
					Node *t = r;
					r = r->left;
					delete t;
					t = NULL;
				}
				else if (r->right != NULL)
				{
					Node *t = r;
					r = r->right;
					delete t;
					t = NULL;
				}
			}
			else if (r->data < d)
				r->right = Delete(d, r->right);
			else
				r->left = Delete(d, r->left);
			if (r) {
				bf = height(r->left) - height(r->right);
				int rbf = 0;
				if (bf == +2)
				{
					rbf = height(r->left->left) - height(r->left->right);
					if (rbf == -1)
						r->left = rotateRight(r->left);
					rotateRight(r);
				}
				else if (bf == -2)
				{
					rbf = height(r->right->left) - height(r->right->right);
					if (rbf == +1)
						r->right = rotateLeft(r->right);
					rotateLeft(r);
				}
				r->height = 1 + max(height(r->left), height(r->right));
			}
			return r;
		}
	}
	
};

int main()
{
	AVL tree;

	tree.addNode(4);
	tree.PrintTree();

	tree.addNode(2);
	tree.PrintTree();

	tree.addNode(3);
	tree.PrintTree();

	tree.addNode(1);
	tree.PrintTree();

	tree.addNode(5);
	tree.PrintTree();

	tree.addNode(9);
	tree.PrintTree();

	tree.addNode(10);
	tree.PrintTree();

	tree.addNode(0);
	tree.PrintTree();

	tree.addNode(11);
	tree.PrintTree();

	tree.Delete(11);
	tree.PrintTree();
	return 0;
}