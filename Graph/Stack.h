#include "iostream"
using namespace std;

struct NodeStk {
	int key;
	struct NodeStk *next;
}*start = NULL , *top = NULL;

void push(int data) {
	struct NodeStk *temp = (struct NodeStk*)malloc(sizeof(struct NodeStk));
	temp->key = data;
	temp->next = NULL;

	if (start == NULL) {
		start = top = temp;
		return;
	}

	top->next = temp;
	top = top->next;
	return;
}

int pop() {

	int x = -1;

	if (start == NULL) {
		return -1;
	}

	x = top->key;

	if (start->next == NULL) {

		start = top = NULL;
		return x;
	}

	struct NodeStk *ptr = start;

	while (ptr->next != top) {
		ptr = ptr->next;
	}

	ptr->next = NULL;
	top = ptr;
	return x;

}


bool stkEmpty() {
	if (top == NULL) return true;
	else return false;
}

void stkDisplay() {
	cout << "Element of stack are: ";

	struct NodeStk *temp = start;

	while (temp != top) {
		cout << temp->key << " ";
		temp = temp->next;
	}
}


