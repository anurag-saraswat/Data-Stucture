#include "iostream"
#include <list>
#include <string>

using namespace std;


int main() {

	// init

	list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9};

	list<string> l2;
	l2.push_back("Apple");
	l2.push_back("Banana");
	l2.push_front("Guava");
	l2.push_front("Mango");
	l2.push_front("kiwi");
	l2.push_front("Orange");

	//sort

	l2.sort();

	//reverse

	l2.reverse();

	// Deleting Element

	l2.pop_back();
	l2.pop_front();

	// Deleting element by value
	l2.push_back("Guava");
	l2.push_front("Guava");

	auto x = "Guava";

	l2.remove(x);



	//Traversing using iterator

	for (auto it = l1.begin(); it != l1.end(); it++) {
		cout << *it << "-->";
	}

	cout << "NULL" << endl;


	//treversing using element

	for (auto x : l2) {
		cout << x << "-->";
	}
	cout << "NULL" << endl;


	return 0;
}