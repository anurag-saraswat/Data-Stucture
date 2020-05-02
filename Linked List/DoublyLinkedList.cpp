#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *prev;
	struct Node *next;
};

struct Node* Create(int *arr, int size) {

	struct Node *temp, *ptr;
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	head->prev = NULL;
	head->next = NULL;
	head->key = arr[0];
	ptr = head;

	for (int i = 1; i < size; i++) {

		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->key = arr[i];
		temp->prev = ptr;
		temp->next = NULL;
		ptr->next = temp;
		ptr = ptr->next;
	}

	ptr->next = head;
	head->prev = ptr;

	return head;
}

void Display1(struct Node *head) {

	cout << "Element Of List Using next Pointer Are: ";

	if (head == NULL) {
		cout << "List is Empty";
		return;
	}

	struct Node *temp = head;

	do {
		cout << temp->key << "<->";
		temp = temp->next;
	} while (temp != head);

	cout << temp->key << endl;
}

void Display2(struct Node *head) {

	cout << "Element Of List Using prev Pointer Are: ";

	if (head == NULL) {
		cout << "List is Empty";
		return;
	}

	struct Node *temp = head;

	do {
		cout << temp->key << "<->";
		temp = temp->prev;
	} while (temp != head);

	cout << temp->key << endl;
}

struct Node* Insert(struct Node *head, int key, int index, int size) {

	if (index<0 or index>size) {
		cout << "Index not valid" << endl;
		return head;
	}

	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = key;
	struct Node *ptr = head;

	if (index == 1) {
		temp->prev = head->prev;
		temp->next = head;
		head->prev = temp;
		temp->prev->next = temp;
		head = temp;
		return head;
	}

	for (int i = 1; i < index - 1; i++) {
		ptr = ptr->next;
	}

	temp->next = ptr->next;
	temp->prev = ptr;
	temp->next->prev = temp;
	ptr->next = temp;
	return head;
}


int main() {

	struct Node *head = NULL;
	int size = 6;
	int arr[] = {1, 2, 3, 4, 5, 6};

	head = Create(arr, size);
	Display1(head);
	Display2(head);
	head = Insert(head, 88, 6, size);
	Display1(head);

	return 0;
}