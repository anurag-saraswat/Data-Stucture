#include "iostream"
using namespace std;

struct Node {
	int val;
	struct Node *next;
};

struct Stack {

	int size;
	int top;
	struct Node *ptr;
};

void Create(struct Stack* stk, int size) {

	stk->size = size;
	stk->top = -1;
	stk->ptr = NULL;
}

void push(struct Stack *stk, int key) {

	if (stk->top == stk->size - 1) {
		cout << "Stack OverFlow" << endl;
		return;
	}

	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = key;
	temp->next = NULL;

	struct Node *ptr;
	stk->top++;
	ptr = stk->ptr;

	if (stk->top == 0) {
		stk->ptr = temp;
		return;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = temp;
}

void Display(struct Node *temp) {

	cout << "Elements Of Stack are: ";
	while (temp != NULL) {
		cout << temp->val << " ";
		temp = temp->next;

	}
	cout << endl;
	return;
}

int pop(struct Stack *stk) {

	if (stk->top == -1) {
		cout << "Stack is Empty !!! " << endl;
		return -1;
	}

	struct Node *prev = NULL, *temp = stk->ptr;

	if (stk->top == 0) {
		int x = temp->val;
		stk->ptr == NULL;
		stk->top--;
		return x;
	}

	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}

	int x = temp->val;
	prev->next = NULL;
	free(temp);
	stk->top--;
	return x;
}


int main() {

	int size = 5;
	struct Stack stk;
	Create(&stk, size);


	push(&stk, 1);
	push(&stk, 3);
	push(&stk, 5);
	Display(stk.ptr);

	int x = pop(&stk);
	if (x != -1)cout << "Popped Element is: " << x << endl;

	x = pop(&stk);
	if (x != -1)cout << "Popped Element is: " << x << endl;

	x = pop(&stk);
	if (x != -1)cout << "Popped Element is: " << x << endl;

	x = pop(&stk);
	if (x != -1)cout << "Popped Element is: " << x << endl;

	return 0;
}

