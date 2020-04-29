#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *next;
}*head = NULL;

void Display() {

	if (head == NULL) {
		cout << "list is empty" << endl;
		return;
	}

	cout << "Elemnts of list are: ";

	struct Node * temp = head;

	while (temp != NULL) {
		cout << temp->key << "->";
		temp = temp->next;
	}

	cout << "NULL" << endl;
}

void Create(int *arr , int size) {
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->key = arr[0];
	ptr->next = NULL;
	head = ptr;

	for (int i = 1; i < size; i++) {

		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->key = arr[i];
		temp->next = NULL;

		ptr->next = temp;
		ptr = ptr->next;
	}
}

void reverse() {

	struct Node *p = head;
	struct Node *q = NULL;
	struct Node *r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

void recursive_reverse(struct Node *q,  struct Node *p) {
	if (p != NULL) {
		recursive_reverse(p, p->next);
		p->next = q;
	}
	else {
		head = q;
	}
}


int main() {

	int size = 10;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	Create(arr, size);
	Display();
	reverse();
	Display();
	recursive_reverse(NULL, head);
	Display();

	return 0;
}