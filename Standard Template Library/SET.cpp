// Collection of unique elements.
// Underlying data structure Red Black Tree
// By default order


#include "iostream"
#include<set>

using namespace std;


int main() {

	int arr[] = {10, 20, 11, 30, 22, 40, 33, 10, 11};

	int size = sizeof(arr) / sizeof(int) ;

	set<int> s;

	for (int i = 0; i < size; i++) {

		s.insert(arr[i]);

	}

	//Delete Element

	s.erase(22);

	auto it = s.find(30);
	s.erase(it);

	// Print all element

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {

		cout << *it << ",";

	}

	cout << endl;

	return 0;
}