#include "iostream"
using namespace std;


struct Array {
	int a[20];
	int length;
	int size;
};

void display(struct Array arr) {
	cout << "Elements of Array are: " << endl;
	for (int i = 0; i < arr.length; i++) {
		cout << arr.a[i] << " ";
	}
}

struct Array * merge(struct Array arr1, struct Array arr2) {

	//struct Array *arr = (struct Array * )malloc(sizeof(struct Array));
	Array *arr = new Array;
	int r = 0;
	int l = 0;
	int k = 0;
	arr->length = arr1.length + arr2.length ;
	arr->size = 20;

	while ( (r < arr1.length) and (l < arr2.length) ) {
		if (arr1.a[r] < arr2.a[l]) {
			arr->a[k++] = arr1.a[r++];
		}
		else {
			arr->a[k++] = arr2.a[l++];
		}
	}

	for (; r < arr1.length; r++) {
		arr->a[k++] = arr1.a[r];
	}

	for (; l < arr2.length; l++) {
		arr->a[k++] = arr2.a[l];
	}

	return arr;
}

int main() {

	struct Array arr1 = {{10, 21, 33, 45, 46, 98}, 6, 10};
	struct Array arr2 = {{5, 11, 25, 54, 84, 77}, 6, 10};
	struct Array *arr;
	cout << "Array1: ";
	display(arr1);
	cout << endl;

	cout << "Array2: ";
	display(arr2);
	cout << endl;

	arr = merge(arr1, arr2);
	cout << "Array after merge: ";
	display(*arr);
	cout << endl;

	return 0;
}