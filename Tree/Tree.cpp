#include "iostream"
#include"Queue.h"
using namespace std;



template<class T>
class Tree {

public:
	TNode<T> *root;

	Tree() {
		root = NULL;
	}

	void createTree() {

		TNode<T> *temp1 = new TNode<T>();
		temp1->left = temp1->right = NULL;
		cout << "Enter Value Of Root Node: ";
		cin >> temp1->key;
		root = temp1;

		Queue<char> que;
		que.enqueue(root);

		TNode<T> *temp2, *temp3;

		while (!que.isEmpty()) {

			temp2 = que.dequeue();

			auto x = 'N';

			cout << endl << "Enter Left Child: ";
			cin >> x;
			if (x != 'N') {
				temp3 = new TNode<T>();
				temp3->left = temp3->right = NULL;
				temp3->key = x;
				temp2->left = temp3;
				que.enqueue(temp3);

			}

			cout << endl << "Enter Right Child: ";
			cin >> x;
			if (x != 'N') {
				temp3 = new TNode<T>();
				temp3->left = temp3->right = NULL;
				temp3->key = x;
				temp2->right = temp3;
				que.enqueue(temp3);

			}

		}
	}

	void preorder(TNode<T> *node) {
		if (node) {
			cout << node->key << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

	void postorder(TNode<T> *node) {
		if (node) {
			preorder(node->left);
			preorder(node->right);
			cout << node->key << " ";
		}
	}

	void inorder(TNode<T> *node) {
		if (node) {
			preorder(node->left);
			cout << node->key << " ";
			preorder(node->right);
		}
	}

	void levelorder() {

		Queue<char> que;
		que.enqueue(root);
		cout << root->key << " ";

		TNode<char> *temp;

		while (!que.isEmpty()) {

			temp = que.dequeue();

			if (temp->left) {
				cout << temp->left->key << " ";
				que.enqueue(temp->left);
			}

			if (temp->right) {
				cout << temp->right->key << " ";
				que.enqueue(temp->right);
			}
		}
	}

	int countingLeafNode() {

		if (root == NULL)return 0;

		int count = 0;

		Queue<char> que;
		que.enqueue(root);

		TNode<char> *temp;

		while (!que.isEmpty()) {

			temp = que.dequeue();

			if (temp->left == NULL and temp->right == NULL) {
				count++;
			}

			if (temp->left) {
				que.enqueue(temp->left);
			}

			if (temp->right) {
				que.enqueue(temp->right);
			}
		}
		return count;
	}
};

int main() {


	Tree<char> btree;
	btree.createTree();

	cout << endl << "Preorder Traversal of Tree is: ";
	btree.preorder(btree.root);

	cout << endl << "Post Traversal of Tree is: ";
	btree.postorder(btree.root);

	cout << endl << "Inorder Traversal of Tree is: ";
	btree.inorder(btree.root);

	cout << endl << "Level Order Traversal of Tree is: ";
	btree.levelorder();

	int count = btree.countingLeafNode();
	cout << endl << "Number Of Child Nodes are: " << count << endl;

	return 0;
}