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

void Delete(int key) {

	struct Node *temp = head;
	struct Node *prev = NULL;
	while (temp->key != key) {
		prev = temp;
		temp = temp->next;
	}

	if ( prev == NULL) {
		head = temp->next;
		//free(temp);
		return;
	}

	else {
		prev->next = temp->next;
		return;
	}
}

void DeleteDuplicte() {
	struct Node *temp1 = head;
	struct Node *temp2 = NULL;


	while (temp1 != NULL) {

		int data = temp1->key;
		temp2 = temp1->next;

		while (temp2 != NULL) {

			if (temp2->key == data) {
				Delete(data);
			}
			temp2 = temp2->next;
		}

		temp1 = temp1->next;
	}
}

int main() {

	int size = 10;
	int arr[] = {1, 2, 3, 1, 3, 5, 6, 5, 7, 7};

	Create(arr, size);
	Display();
	DeleteDuplicte();
	Display();

	return 0;
}