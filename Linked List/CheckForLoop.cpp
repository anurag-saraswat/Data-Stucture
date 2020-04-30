#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *next;
}*first = NULL, *second = NULL;


void Display(struct Node *head) {

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

void DisplayWithloop(struct Node *head, int size) {

	if (head == NULL) {
		cout << "list is empty" << endl;
		return;
	}

	cout << "Elemnts of list are: ";

	struct Node * temp = head;

	while (size--) {
		cout << temp->key << "->";
		temp = temp->next;
	}

	cout << temp->key << endl;
}

struct Node* Create(int *arr , int size) {
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->key = arr[0];
	ptr->next = NULL;
	struct Node *head = ptr;

	for (int i = 1; i < size; i++) {

		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->key = arr[i];
		temp->next = NULL;

		ptr->next = temp;
		ptr = ptr->next;
	}

	return head ;
}

struct Node* CreateWithLoop(int *arr , int size) {
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->key = arr[0];
	ptr->next = NULL;
	struct Node *head = ptr;

	for (int i = 1; i < size; i++) {

		struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
		temp->key = arr[i];
		temp->next = NULL;

		ptr->next = temp;
		ptr = ptr->next;
	}

	ptr->next = head;
	return head ;
}

bool isLoop(struct Node *ptr) {
	struct Node *slow = ptr, *fast = ptr;

	do {
		slow = slow->next;
		fast = fast->next;
		fast = fast ? fast->next : fast;
	} while (slow && fast && slow != fast);

	if (slow == fast) {
		return true;
	}
	else {
		return false;
	}

}


int main() {

	int size = 10;
	int arr1[] = {1, 2, 3, 10, 20, 30, 45, 50, 70, 78};
	first = Create(arr1, size);
	Display(first);
	bool res = isLoop(first);
	res ? cout << "Loop is present" << endl : cout << "Loop is not present" << endl;

	size = 10;
	int arr2[] = {10, 15, 25, 30, 42, 55, 66, 68, 82, 90};
	second = CreateWithLoop(arr2, size);
	DisplayWithloop(second, size);
	res = isLoop(second);
	res ? cout << "Loop is present" << endl : cout << "Loop is not present" << endl;

	return 0;
}
