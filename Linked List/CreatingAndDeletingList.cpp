#include "iostream"
using namespace std;

struct Node {
	int key;
	struct Node *next;
}*head = NULL;

void Display();
void RecDisplay();
void CountNode();
void Create(struct Node);
void SumOfElement();


void RecDisplay(struct Node *temp) {

	if (temp != NULL) {
		cout << temp->key << "->";
		RecDisplay(temp->next);
	}
}

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

void CountNode() {
	struct Node *temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	cout << "No. of Node in list are: " << count << endl;;
}

void SumOfElement() {
	struct Node *temp = head;
	int sum = 0;

	while (temp != NULL) {
		sum = sum + (temp->key);
		temp = temp->next;
	}

	cout << "Sum Of Elements of list: " << sum << endl;
}



int main() {

	int size = 10;
	int arr[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

	Create(arr, size);
	Display();
	//RecDisplay(head);
	CountNode();
	SumOfElement();


	return 0;

}