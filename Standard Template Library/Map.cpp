//Map is associative container that stores mapping between key and value
//All objects are ordered according to key
//Internally uses self balance binary search tree
//Every key must be unique
//Multi map is used if keys are not unique
// insert,find,erase == log(N)

#include "iostream"
#include <string>
#include <map>

using namespace std;

int main() {

	map<string, int> m;

	//Insert

	m.insert(make_pair("Physics", 156));

	pair<string, int> p;
	p.first = "Chemistry";
	p.second = 222;

	m.insert(p);

	m["Maths"] = 356;


	//Search

	string book = "Maths";

	auto it = m.find(book);

	if (it != m.end()) {
		cout << "Price of book " << book << " is: " << m[book] << endl;
	}
	else cout << "Book is not available" << endl;



	// iterate over key

	cout << endl << "Elements of Map are: " << endl;

	for (it = m.begin(); it != m.end(); it++) {

		cout << (*it).first << " " << it->second << endl;

	}







	return 0;
}