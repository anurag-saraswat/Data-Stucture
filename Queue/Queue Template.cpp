#include "iostream"
using namespace std;

template <class T>
class Node {
public:
	Node *prev = NULL;
	T key;
	Node *next = NULL;
};


template <class T>
class Queue {
public:

	Node<T> *rear;
	Node<T> *front;

	Queue() {
		rear = NULL;
		front = NULL;
	}

	void enqueue(T data) {

		Node<T> *temp = new Node<T>();

		if (temp == NULL) {
			cout << "Queue is not empty";
			return;
		}

		if (rear == NULL and front == NULL) {
			temp->prev = temp->next = NULL;
			temp->key = data;
			rear = temp;
			front = temp;

			return;
		}

		temp->key = data;
		temp->prev = rear;
		rear->next = temp;
		rear = rear->next;
	}

	void Display() {

		if (front == NULL and rear == NULL) {
			cout << "Queue is empty" << endl;
			return;
		}

		cout << "Elements of Queue are: ";

		Node<T> *temp = front;

		if (temp->next == NULL) {
			cout << temp->key << endl;
			return;
		}

		while (temp != NULL) {
			cout << temp->key << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	void dequeue() {

		if (front == rear) {
			cout << "Queue is empty..Nothing to be dequeued" << endl;
			return;
		}

		Node<T> *temp = front;
		auto data = front->key;
		front = front->next;
		front->prev = NULL;
		delete temp;
		cout << "Element Dequeued is: " << data << endl;
		return;
	}
};

int main() {

	Queue<char> que;
	que.enqueue('a');
	que.enqueue('b');
	que.enqueue('c');
	que.enqueue('d');
	que.Display();
	que.dequeue();
	que.dequeue();
	que.Display();

	Queue<int> queInt;
	queInt.enqueue(1);
	queInt.enqueue(2);
	queInt.enqueue(3);
	queInt.enqueue(4);
	queInt.Display();
	queInt.dequeue();
	queInt.dequeue();
	queInt.Display();

	return 0;
}