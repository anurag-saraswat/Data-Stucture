#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *next;
};

struct Node* Create(int *arr , int size) {

	struct Node *temp, *head = (struct Node*)malloc(sizeof(struct Node));
	head->next = head;
	head->key = arr[0];
	temp = head;

	for (int i = 1; i < size; i++) {

		struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
		ptr->key = arr[i];
		ptr->next = head;
		temp->next = ptr;
		temp = temp->next;
	}

	return head;
}

void Display(struct Node *head) {

	cout << "Element Of List are: ";

	if (head == NULL) {
		cout << "List is Empty";
		return;
	}

	struct Node *temp = head;

	do {
		cout << temp->key << "->";
		temp = temp->next;
	} while (temp != head);

	cout << temp->key << endl;
}

int Length(struct Node *head) {
	int len = 0;

	if (head == NULL) {
		return 0;
	}

	struct Node *temp = head;
	do {
		len ++;
		temp = temp->next;
	} while (temp != head);

	return len;
}

struct Node* Insert(struct Node *head, int index, int x) {

	if (index < 0 or index > Length(head)) {
		cout << "Invalid index" << endl;
		return head;
	}

	if (index == 1) {

		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		struct Node *ptr = head, *prev = NULL;

		temp->key = x;

		do {
			prev = ptr;
			ptr = ptr->next;

		} while (ptr != head);

		prev->next = temp;
		temp->next = head;
		head = temp;
		return head;
	}

	struct Node *ptr = head;
	index--;

	while (--index) {
		ptr = ptr->next;
	}

	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->key = x;
	temp->next = ptr->next;
	ptr->next = temp;
	return head;
}

struct Node* Delete(struct Node *head, int index) {

	struct Node* temp = head, *ptr, *prev ;

	if (index == 1) {

		head = head->next;
		ptr = temp;
		do {
			prev = ptr;
			ptr = ptr->next;
		} while (ptr != temp);

		prev->next = head;

		free(temp);
		return head;
	}

	for (int i = 0; i < index - 1; i++) {

		prev = temp;
		temp = temp->next;
	}

	prev->next = temp->next;

	return head;
}


int main()
{
	int size = 5;
	int arr[] = {1, 2, 3, 4, 5};
	struct Node *head = Create(arr, size);
	Display(head);
	int len = Length(head);
	cout << "Length of List : " << len << endl;
	head = Insert(head, 2 , 89);
	Display(head);
	head = Delete(head, 6);
	Display(head);

	return 0;
}