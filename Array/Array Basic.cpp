#include "iostream"
using namespace std;

void display(struct Array arr);
void append(struct Array *arr , int x );
void insert(struct Array *arr, int x, int index);
void delete_item(struct Array *arr, int index);


struct Array {
	int a[10];
	int size;
	int length;
};

void append(struct Array *arr , int x ) {

	if (arr->length == arr->size) {
		cout << "Array is full" << endl;
	}
	else {
		arr->a[arr->length] = x;
		arr->length++;
		cout << "Array after append, ";
		display(*arr);
	}
}

void insert(struct Array *arr, int x, int index) {
	if (arr->length == arr->size ) {
		cout << "Array is full" << endl;
	}
	else if ((index < 1) or (index > arr->size)) {
		cout << "Index Not Found";
	}
	else if (index > arr->length) {
		arr->a[index - 1] = x;
		arr->length++;


	}
	else {
		for (int i = (arr->length); i >= index; i--) {
			arr->a[i] = arr->a[i - 1];
		}

		arr->a[index - 1] = x;
		arr->length++;
	}
	cout << "Array after insertion, ";
	display(*arr);
}

void delete_item(struct Array *arr, int index) {

	if (arr->length == 0) {
		cout << "Array is empty" << endl;
	}
	else {
		for (int i = index - 1; i < arr->length; i++) {
			arr->a[i - 1] = arr->a[i];
		}
		arr->length--;
	}
	cout << "Array after deletion, ";
	display(*arr);


}

void display(struct Array arr) {

	cout << "Elements Are: ";
	for (int i = 0; i < arr.length; i++) {
		cout << arr.a[i] << "\t";
	}
	cout << endl;
}


int main() {

	struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
	display(arr);
	append(&arr, 10);
	insert(&arr, 50, 2);
	delete_item(&arr, 3);

	return 0;
}