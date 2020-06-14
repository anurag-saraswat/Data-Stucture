#include "iostream"
#include <map>
#include <vector>

using namespace std;


class Node {
public:
	int key;

	Node *right;
	Node *left;

	Node(int d) {

		key = d;
		right = left = NULL;
	}
};

void VerticalOrderPrint(Node *ptr , int d, map<int , vector<int>> &m) {

	if (ptr == NULL) {
		return ;
	}

	m[d].push_back(ptr->key);
	VerticalOrderPrint(ptr->left, d - 1, m);
	VerticalOrderPrint(ptr->right, d + 1, m);
}


int main() {

	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->right = new Node(8);

	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right = new Node(9);


	map<int, vector<int>> m;
	int d = 0;

	VerticalOrderPrint(root, d, m);

	for (auto i : m) {

		cout << "At distance " << i.first << " : ";

		for (auto j : i.second) {

			cout << j << " , ";
		}

		cout << endl;


	}

	return 0;
}