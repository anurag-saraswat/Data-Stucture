#include "iostream"
using namespace std;

struct Queue {

	int size;
	int front;
	int rear;
	int *arr;
};

void create(struct Queue *que, int size) {

	que->arr = (int *)malloc(size * sizeof(int));
	que->size = size;
	que->front = -1;
	que->rear = -1;
}

void enqueue(struct Queue *que, int key) {

	if (que->front == -1 && que->rear == -1) {
		que->front = 0;

	}
	else if (que->front == 0 and que->rear == que->size - 1) {
		cout << "Queue is Full!!!!" << endl;
		return ;
	}
	else if (que->front != 0 and que->rear == que->size - 1) {
		que->rear = -1;
	}
	else if (que->rear == que->front - 1) {
		cout << "Queue is Full!!" << endl;
		return;
	}

	que->rear++;
	que->arr[que->rear] = key;
	return;
}

int dequeue(struct Queue *que) {

	if (que->front == que->rear) {
		cout << "Queue Is Empty!!!" << endl;
		return -1;
	}

	int x;

	x = que->arr[que->front];
	que->front = (que->front + 1) % que->size;
	return x;
}

void Display(struct Queue *que) {

	if (que->front == que->rear) {
		cout << "Queue is Empty!!" << endl;
		return;
	}

	int i = que->front;
	cout << "Elements of Queue Are: ";

	do {
		i = i % (que->size );
		cout << que->arr[i] << " ";
	} while ((i++) != que->rear);

}

int main() {

	int size = 6;
	struct Queue que;
	create(&que, size);

	enqueue(&que, 1);
	enqueue(&que, 2);
	enqueue(&que, 3);
	enqueue(&que, 4);
	enqueue(&que, 5);
	enqueue(&que, 6);

	int x = dequeue(&que);
	if (x != -1) cout << "Dequeued Element is : " << x << endl;

	x = dequeue(&que);
	if (x != -1) cout << "Dequeued Element is : " << x << endl;


	enqueue(&que, 1);
	enqueue(&que, 2);

	x = dequeue(&que);
	if (x != -1) cout << "Dequeued Element is : " << x << endl;

	x = dequeue(&que);
	if (x != -1) cout << "Dequeued Element is : " << x << endl;

	enqueue(&que, 10);
	enqueue(&que, 12);

	Display(&que);

	return 0;
}