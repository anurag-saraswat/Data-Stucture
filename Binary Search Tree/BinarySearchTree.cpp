#include "iostream"
using namespace std;
#include<algorithm>

void Insert(int data);
void Inorder(struct Node *p);
struct Node* Search(int data);
int Height(struct Node *t);
struct Node* InSucc(struct Node* t);
struct Node* InPred(struct Node* t);


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

void Inorder(struct Node *p) {

	if (p) {
		Inorder(p->lchild);
		cout << p->key << " ";
		Inorder(p->rchild);
	}
}

void PostOrder(struct Node *p) {
	if (p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout << p->key << " ";
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

int Height(struct Node *t) {

	if (t == NULL) return 0;
	return 1 + max(Height(t->rchild), Height(t->lchild));
}

struct Node* InSucc(struct Node* t) {

	if (t->rchild == NULL) {
		return NULL;
	}

	t = t->rchild;
	while (t != NULL and t->lchild != NULL) {
		t = t->lchild;
	}
	return t;
}

struct Node* InPred(struct Node* t) {

	if (t->lchild == NULL) {
		return NULL;
	}

	t = t->lchild;
	while (t != NULL and t->rchild != NULL) {
		t = t->rchild;
	}
	return t;
}

void Delete(int data) {

	struct Node* t = root, *parent, *q , *qparent;

	while (t != NULL) {

		if (data == t->key) break;

		else if (data > t->key)  {
			parent = t;
			t = t->rchild;
		}

		else if (data < t->key) {
			parent = t;
			t = t->lchild;

		}

	}

	if (t == NULL) {
		cout << endl << "Element " << data << " is not present in tree. So not deleted!!! ";
		return;
	}

	if (t->lchild == NULL and t->rchild == NULL) {
		if (t->key > parent->key)parent->rchild = NULL;
		else parent->lchild = NULL;

		return;
	}

	int x = Height(t->rchild);
	int y = Height(t->lchild);



	if (y >= x) {

		q = t;
		qparent = t;
		q = q->lchild;

		if (q->rchild == NULL) {
			t->key = q->key;
			t->lchild = q->lchild;
			free(q);
			return;

		}

		while (q != NULL and q->rchild != NULL) {
			qparent = q;
			q = q->rchild;
		}

		t->key = q->key;

		if (q->lchild != NULL) {
			qparent->rchild = q->lchild;
		}
		else {
			qparent->rchild = NULL;
		}

		free(q);

		return;

	}

	else {

		q = t;
		qparent = t;
		q = q->rchild;

		if (q->lchild == NULL) {
			t->key = q->key;
			t->rchild = NULL;
			free(q);
			return;

		}

		while (q != NULL and q->lchild != NULL) {
			qparent = q;
			q = q->lchild;
		}

		t->key = q->key;

		if (q->rchild != NULL) {
			qparent->lchild = q->rchild;
		}
		else {
			qparent->lchild = NULL;
		}

		free(q);

		return;

	}
}


int main() {

	Insert(25);
	Insert(18);
	Insert(14);
	Insert(20);
	Insert(36);
	Insert(28);
	Insert(17);
	Insert(13);
	Insert(15);
	Insert(40);
	Insert(45);
	Insert(38);
	Insert(37);


	cout << "Inorder Traversal Of Tree is: ";
	Inorder(root);

	Delete(37);
	Delete(25);
	Delete(100);

	cout << endl << "Inorder Traversal Of Tree After Deletion: ";
	Inorder(root);




	cout << endl << "PostOrder Traversal Of Tree is: ";
	PostOrder(root);

	cout << endl;

	cout << "Height of tree is: " << Height(root) << endl;

	int x = 18;
	struct Node *t = Search(x);
	if (t)cout << "Element " << t->key << " is Found!!" << endl;
	else cout << "Element is not found" << endl;

	struct Node *temp = InSucc(t);

	if (temp != NULL) {
		cout << "Inorder Succeor of " << x << " is: " << temp->key << endl;
	}

	temp = InPred(t);

	if (temp != NULL) {
		cout << "Inorder Predecessor of " << x << " is: " << temp->key << endl;
	}


	return 0;
}