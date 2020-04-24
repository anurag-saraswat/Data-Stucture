#include "iostream"
using namespace std;

struct Array {
	int a[20];
	int length;
	int size;
};

void Iterative_BinarySearch(struct Array *arr, int key) {
	int low = 0;
	int high = arr->length - 1;
	int mid;

	while (low <= high) {

		mid = (high + low) / 2;
		if (arr->a[mid] == key) {
			cout << "Element is found at index: " << mid + 1 << endl;
			return;
		}
		else if (key < (arr->a[mid])) {
			high  = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}

	cout << "Element Not Found" << endl;
}

void Rec_BinarySearch(struct Array *arr, int l, int h, int key) {
	int mid = 0;
	if (l <= h) {
		mid = (l + h) / 2;
		if (arr->a[mid] == key) {
			cout << "Key is found at Index: " << (mid + 1) << endl;
			return;
		}
		else if (key < (arr->a[mid])) {
			h  = mid - 1;
			Rec_BinarySearch(arr, l, h, key);
		}
		else {
			l = mid + 1;
			Rec_BinarySearch(arr, l, h, key);
		}

	}
	return;

}


int main() {

	struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 9, 10};
	Rec_BinarySearch(&arr1, 1, 9, 16);

	return 0;
}