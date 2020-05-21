#include "iostream"
using namespace std;

struct Node {
	Node *lchild;
	int key;
	Node *rchild;
} *root = NULL;

void Insert(int data) {

	struct Node *temp = (Node *)malloc(sizeof(struct Node));
	temp->key = data;
	temp->lchild = temp->rchild = NULL;

	if (root == NULL) {
		root = temp;
		return;
	}

	struct Node *ptr = root, *prev;

	while (ptr) {

		prev = ptr;

		if (data > ptr->key) {
			ptr = ptr->rchild;
		}

		else if (data < ptr->key) {
			ptr = ptr->lchild;

		}
		else
			return;
	}

	if (data > prev->key)prev->rchild = temp;
	else prev->lchild = temp;

	return;
}

void inorder(Node *p) {

	if (p) {
		inorder(p->lchild);
		cout << p->key << " ";
		inorder(p->rchild);

	}

}

struct Node* Search(int data) {

	struct Node *t = root;

	while (t) {

		if (data == t->key) return t;
		else if (data > t->key)t = t->rchild;
		else t = t->lchild;
	}

	return NULL;

}




int main() {

	Insert(10);
	Insert(20);
	Insert(30);
	Insert(5);
	Insert(15);
	Insert(13);

	cout << "Inorder Traversal Of Tree is: ";
	inorder(root);

	cout << endl;

	struct Node *t = Search(5);
	if (t)cout << "element " << t->key << " is Found!!" << endl;
	else cout << "Element is not found" << endl;

	t = Search(100);
	if (t)cout << "element " << t->key << " is Found!!" << endl;
	else cout << "Element is not found" << endl;


	return 0;
}