#include <iostream>
using namespace std;

struct Array {
	int a[10];
	int length;
	int size;
};

void display(struct Array arr) {

	cout << "Elements Are: ";
	for (int i = 0; i < arr.length; i++) {
		cout << arr.a[i] << "\t";
	}
	cout << endl;
}

void swap1(struct Array *arr, int i) {
	int temp = arr->a[i];
	arr->a[i] = arr->a[i - 1];
	arr->a[i - 1] = temp;
}

void swap2(struct Array *arr, int i) {
	int temp = arr->a[i];
	arr->a[i] = arr->a[0];
	arr->a[0] = temp;
}

void move2end_Lsearch(struct Array *arr, int key) {
	for (int i = 0; i <= arr->length; i++) {
		if (arr->a[i] == key) {
			cout << "Key is found at index: " << i + 1 << endl;
			if (i != 0) {swap2(arr, i);}
			return;
		}
	}
	cout << "Element is not in list" << endl;
}

void transposition_Lsearch(struct Array *arr, int key) {

	for (int i = 0; i <= arr->length; i++) {

		if (arr->a[i] == key) {
			cout << "Key is found at index: " << i + 1 << endl;
			if (i != 0) {swap1(arr, i);}
			return;
		}
	}

	cout << "Element is not in list" << endl;
}



int main() {

	struct Array arr = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 9, 10};
	display(arr);
	transposition_Lsearch(&arr, 21);
	display(arr);
	move2end_Lsearch(&arr, 16);
	display(arr);
	return 0;
}