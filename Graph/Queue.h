#include "iostream"
using namespace std;

struct Node {
	int key;
	Node *next;
}*front = NULL, *rear = NULL;


void enqueue(int data) {
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

	if (temp == NULL) {
		cout << "Queue is full";
		return;
	}

	temp->key = data;
	temp->next = NULL;

	if (rear == NULL) {
		front = temp;
		rear = temp;
		return;
	}

	rear->next = temp;
	rear = rear->next;
	return;
}

int dequeue() {

	int x;

	if (front == NULL)return -1;

	x = front->key;

	if (front->next == NULL) {
		front = rear = NULL;
		return x;
	}

	front = front->next;
	return x;

}

bool isEmpty() {
	if (front == NULL) return true;
	else return false;
}