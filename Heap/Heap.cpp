#include "iostream"
using namespace std;

void Max_Heapify(int arr[], int index, int size);
void Min_Heapify(int arr[], int index, int size);
void Build_Max_Heap(struct Heap *heap);
void Build_Min_Heap(struct Heap *heap);
void Display(struct Heap heap);


struct Heap {
	int size;
	int index;
	int *arr;
};

void Build_Max_Heap(struct Heap *heap) {

	for (int i = heap->size / 2 ; i > 0; i-- ) {
		Max_Heapify(heap->arr, i, heap->size);
	}
}

void Build_Min_Heap(struct Heap *heap) {

	for (int i = heap->size / 2 ; i > 0; i-- ) {
		Min_Heapify(heap->arr, i, heap->size);
	}
}

void Max_Heapify(int arr[], int index, int size) {

	int left = 2 * index;
	int right = 2 * index + 1;
	int largest = index;


	if ((left <= size) and (arr[left] > arr[index])) {
		largest = left;
	}

	if ((right <= size) and (arr[right] > arr[index])) {
		largest = right;
	}

	if (largest != index) {
		int temp = arr[largest];
		arr[largest] = arr[index];
		arr[index] = temp;
		Max_Heapify(arr , largest, size);
	}
}

void Min_Heapify(int arr[], int index, int size) {

	int left = 2 * index;
	int right = 2 * index + 1;
	int minimum = index;


	if ((left <= size) and (arr[left] < arr[index])) {
		minimum = left;
	}

	if ((right <= size) and (arr[right] < arr[index])) {
		minimum = right;
	}

	if (minimum != index) {
		int temp = arr[minimum];
		arr[minimum] = arr[index];
		arr[index] = temp;
		Min_Heapify(arr , minimum, size);
	}
}


void MaxInsert(int *arr, int index) {

	int temp = arr[index];
	while (index > 1 and temp > arr[index / 2]) {
		arr[index] = arr[index / 2];
		index = index / 2;
	}

	arr[index] = temp;
	return;
}

void MinInsert(int arr[], int index) {

	int temp = arr[index];
	while (index > 1 and temp < arr[index / 2]) {

		arr[index] = arr[index / 2];
		index = index / 2;
	}

	arr[index] = temp;
	return;
}

int MaxDelete(int *arr, int index) {

	int temp = arr[index];
	arr[index] = arr[1];
	arr[1] = temp;

	return index;
}

void Display(struct Heap heap) {

	for (int i = 1; i <= heap.size; i++) {
		cout << heap.arr[i] << " ";
	}
	cout << endl;
	return;
}

int main() {

	struct Heap max_heap, min_heap;

	int arr[] = { -1, 5, 7, 6, 8, 9, 10};

	min_heap.size = 6;
	min_heap.index = 6;
	min_heap.arr = arr;

	max_heap.size = 6;
	max_heap.index = 6;
	max_heap.arr = arr;

	Build_Max_Heap(&max_heap);
	cout << "Element Of Max-Heap are: ";
	Display(max_heap);

	Build_Min_Heap(&min_heap);
	cout << "Element Of Min-Heap are: ";
	Display(min_heap);





	return 0;
}