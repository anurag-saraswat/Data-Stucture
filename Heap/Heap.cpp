#include "iostream"
using namespace std;

void Max_Heapify(int arr[], int index, int size);
void Min_Heapify(int arr[], int index, int size);
void Build_Max_Heap(struct Heap *heap);
void Build_Min_Heap(struct Heap *heap);
void Display(struct Heap heap);
void MaxDelete(struct Heap *heap);
void Inc_HeapSort(struct Heap *heap);
void Dec_HeapSort(struct Heap *heap);


struct Heap {
	int init_size;
	int size;
	int *arr;
};

void Build_Max_Heap(struct Heap *heap) {

	for (int i = heap->size ; i >= 1; i-- ) {

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


	if ((left <= size) and (arr[left] > arr[largest])) {
		largest = left;
	}

	if ((right <= size) and (arr[right] > arr[largest])) {
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


	if ((left <= size) and (arr[left] < arr[minimum])) {
		minimum = left;
	}

	if ((right <= size) and (arr[right] < arr[minimum])) {
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

void MaxDelete(struct Heap *heap) {

	int temp = heap->arr[heap->size];
	heap->arr[heap->size] = heap->arr[1];
	heap->arr[1] = temp;
	heap->size--;
	Build_Max_Heap(heap);
	return;
}

void MinDelete(struct Heap *heap) {

	int temp = heap->arr[heap->size];
	heap->arr[heap->size] = heap->arr[1];
	heap->arr[1] = temp;
	heap->size--;
	Build_Min_Heap(heap);
	return;
}

void Inc_HeapSort(struct Heap *heap) {

	for (int i = 1; i >= heap->size; i++) {
		MaxDelete(heap);
	}

	heap->size = heap->init_size;
	cout << "Element Sorted in decreasing order are: ";
	Display(*heap);
}

void Dec_HeapSort(struct Heap *heap) {

	for (int i = 1; i >= heap->size; i++) {
		MinDelete(heap);
	}

	heap->size = heap->init_size;
	cout << "Element Sorted in increasing order are: ";
	Display(*heap);
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

	int arr1[] = { -1, 5, 7, 6, 8, 9, 10};
	int arr2[] = { -1, 5, 7, 6, 8, 9, 10};

	min_heap.size = 6;
	min_heap.init_size = 6;
	min_heap.arr = arr1;

	max_heap.size = 6;
	max_heap.init_size = 6;
	max_heap.arr = arr2;

	Build_Max_Heap(&max_heap);
	cout << "Element Of Max-Heap are: ";
	Display(max_heap);


	Build_Min_Heap(&min_heap);
	cout << "Element Of Min-Heap are: ";
	Display(min_heap);

	Inc_HeapSort(&max_heap);
	Dec_HeapSort(&min_heap);

	return 0;
}