#include "iostream"
using namespace std;


struct Stack {
	int top;
	int size;
	int *arr;
} stk;

void Create(int size) {

	stk.size = size;
	stk.top = -1;
	stk.arr = (int *)malloc(size * sizeof(int));

}

void Display() {
	cout << "Elements Of Stack are: ";
	for (int i = 0; i <= stk.top; i++) {
		cout << stk.arr[i] << " ";
	}
	cout << endl;
}

void push(int x) {
	if (stk.top == stk.size - 1) {
		cout << "Stack Overflow" << endl;
		return;
	}
	stk.top++;
	stk.arr[stk.top] = x;
}

int pop() {

	if (stk.top == -1) {
		cout << "Stack is Empty" << endl;
		return -1;
	}

	return stk.arr[stk.top--];

}


int top() {
	return stk.arr[stk.top];
}


int main() {

	int size = 5;
	Create(size);

	push(1);
	push(2);
	push(3);
	Display();

	int x = pop();
	if (x != -1)cout << "Popped Element is: " << x << endl;

	x = pop();
	if (x != -1)cout << "Popped Element is: " << x << endl;

	push(8);
	push(7);

	x = top();
	if (x != -1)cout << "Top element is: " << x << endl;

	Display();

	return 0;

}