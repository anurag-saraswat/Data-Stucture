#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool compare(int a, int b) {

	//cout << "comparing " << a << " and " << b << "....." << endl;
	return a > b;
}


int main() {


	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(arr) / sizeof(int);


	//Finding Element

	int key = 4;
	auto it = find(arr, arr + n, key);
	cout << "key " << key << " is present at Index: " << it - arr << endl;


	//Binary Search
	int element = 9;
	auto present = binary_search(arr, arr + n, element);

	if (present)cout << "Element " << element << " is present" << endl;
	else cout << "Element is not present" << endl;



	//Lower Bound and Upper Bound

	cout << endl;

	auto itr1 = lower_bound(arr, arr + n, element);
	cout << "Lower Bound of Element " << element << " is: " << itr1 - arr << endl;

	auto itr2 = upper_bound(arr, arr + n, element);
	cout << "Upper Bound of Element " << element << " is: " << itr2 - arr << endl;

	cout << "Frequency of Occurence of element " << element << " is: " << itr2 - itr1 << endl;

	cout << endl;

	//Sorting array


	sort(arr, arr + n);

	cout << "Sorted Element in increasing order are: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	sort(arr, arr + n, compare); //passing function name as parameter

	cout << "Sorted Element in decreasing order are: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	//Rotate and Permutation using Vector

	vector<int> v = {10, 30, 15, 78, 17};

	cout << "Element  of Vector are: ";
	for (int x : v) cout << x << " ";

	rotate(v.begin(), v.begin() + 2, v.end());


	cout << endl << "Element  of Vector after rotation: ";
	for (int x : v) cout << x << " ";

	sort(v.begin(), v.end());

	next_permutation(v.begin(), v.end());
	next_permutation(v.begin(), v.end());
	next_permutation(v.begin(), v.end());
	next_permutation(v.begin(), v.end());

	cout << endl << "Different Permutation are: ";
	for (int x : v) cout << x << " ";
	cout << endl;






	return 0;
}