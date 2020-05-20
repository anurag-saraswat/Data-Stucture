#include "iostream"
using namespace std;

template<class T>
class TNode {
public:
	TNode<T> *left = NULL;
	T key;
	TNode<T> *right = NULL;
};

template<class T>
class Node {
public:
	TNode<T> *key;
	Node *next = NULL;
};


template<class T>
class Queue {
public:

	Node<T> *rear;
	Node<T> *front;

	Queue() {
		rear = NULL;
		front = NULL;
	}

	void enqueue(TNode<T> *data) {

		Node<T> *temp = new Node<T>();

		if (temp == NULL) {
			cout << "Queue is FULL";
			return;
		}

		if (rear == NULL and front == NULL) {
			temp->next = NULL;
			temp->key = data;
			rear = temp;
			front = temp;
			return;
		}

		temp->key = data;
		rear->next = temp;
		rear = rear->next;
		return;
	}

	void Display() {

		if (front == NULL and rear == NULL) {
			cout << "Queue is empty" << endl;
			return;
		}

		cout << "Elements of Queue are: ";

		Node<T> *temp = front;

		if (temp->next == NULL) {
			cout << temp->key->key << endl;
			return;
		}

		while (temp != NULL) {
			cout << temp->key->key << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	TNode<T>* dequeue() {

		if (front == NULL and rear == NULL) {
			cout << "Queue is empty..Nothing to be dequeued" << endl;
			return NULL;
		}


		Node<T> *temp = front;
		TNode<T>* data = front->key;
		front = front->next;
		delete temp;

		if (front == NULL) {
			rear = NULL;
		}

		return data;
	}

	bool isEmpty() {
		if (front == NULL and rear == NULL)return true;
		else return false;
	}
};
