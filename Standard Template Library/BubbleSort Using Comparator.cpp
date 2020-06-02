#include "iostream"
using namespace std;

bool compareInc(int x, int y) {
	return x > y;
}

bool compareDec(int x, int y) {
	return x < y;
}

void BubbleSort(int *arr, int size, bool(&cmp)(int a, int b)) {

	int end = size - 1;

	for (int i = 0; i < size ; i++) {

		for (int j = 0; j < end; j++) {

			if (cmp(arr[j], arr[j + 1]))swap(arr[j], arr[j + 1]);
		}

		end--;
	}
}

int main() {

	int arr[] = {5, 2, 6, 9, 8, 10, 3, 1};
	int size = sizeof(arr) / sizeof(int);


	cout << "Unsorted Element Are:  ";

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";

	}
	cout << endl;


	cout << "Element arranged in Increasing Order are:  ";
	BubbleSort(arr, size, compareInc);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";

	}
	cout << endl;


	cout << "Element arranged in Decreasing Order are:  ";
	BubbleSort(arr, size, compareDec);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;


	return 0;
}
