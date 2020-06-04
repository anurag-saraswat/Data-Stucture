#include <iostream>
#include <vector>

using namespace std;


int main() {

	// declaration and initialisation

	vector<int> a;
	vector<int> b(5, 0); // 5 int with value 0;
	vector<int> c(b.begin(), b.end());
	vector<int> d{1, 2, 3, 4, 5};

	// traversal

	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << ", ";
	}
	cout << endl;

	for (auto it = c.begin(); it != c.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

	for (int x : d) {
		cout << x << ", ";
	}
	cout << endl;

	// Add Element in VECTOR

	vector<int> v;  //doubles size whenever it get full

	int i = 0;
	while (i < 5) {
		v.push_back(i++);
	}

	for (int x : v) {
		cout << x << ", ";
	}
	cout << endl;


	//Understanding at memory level by comparing v and d;


	cout << v.size() << endl;
	cout << v.capacity() << endl; // Size of underlying array
	cout << v.max_size() << endl; // maximum no of element a vector can hold in the worst case according to available mamory in the system


	cout << d.size() << endl;
	cout << d.capacity() << endl; // Size of underlying array
	cout << d.max_size() << endl; // maximum no of element a vector can hold in the worst case according to available mamory in the system


	//Other Methods

	v.pop_back(); // remove last element

	v.insert(v.begin() + 3 , 4 , 100); // add 4 element with value 100 at index begin +3

	// Erase some element from the middle

	v.erase(v.begin() + 3);
	v.erase(v.begin() + 3 , v.begin() + 5);
	for (int x : v) {
		cout << x << ", ";
	}


	cout << endl << v.front() << endl;
	cout << v.back() << endl;


	// reserve function : To avoid doubling of array reserve function is used.

	vector<int> u;
	int j = 0;
	while (j < 10) {
		cout << "Capacity is..." << u.capacity() << endl;
		u.push_back(j++);
	}

	vector<int> t;
	t.reserve(1000);

	j = 0;
	while (j < 10) {
		cout << "Capacity is..." << t.capacity() << endl;
		t.push_back(j++);
	}

	return 0;
}