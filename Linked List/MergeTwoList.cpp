#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;


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

void Merge() {

	struct Node *iter = NULL;

	if (first->key > second->key) {
		third = second;
		second = second->next;
		third->next = NULL;
	}
	else {
		third = first;
		first = first->next;
		third->next = NULL;
	}


	iter = third;
	while (first and second) {

		if (first->key > second->key) {
			iter->next = second;
			iter = iter->next;
			second = second->next;
			iter->next = NULL;
		}
		else {
			iter->next = first;
			iter = iter->next;
			first = first->next;
			iter->next = NULL;
		}

	}

	if (first) {
		iter->next = first;
	}

	if (second) {
		iter->next = second;
	}
}

int main() {

	int size = 4;
	int arr1[] = {5, 10, 15, 40};
	first = Create(arr1, size);
	Display(first);

	size = 3;
	int arr2[] = {2, 3, 20};
	second = Create(arr2, size);
	Display(second);
	Merge();
	Display(third);


	return 0;
}