#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


class Person {

public:

	string name;
	int age;

	Person(string n, int a) {
		name = n;
		age = a;
	}

};

class personCompare {

public:

	bool operator ()(Person a, Person b) {

		cout << "Comparing " << a.age << " with" << b.age << "..." << endl;

		return a.age > b.age;

	}
};

int main() {

	string name;
	int age, n;

	cin >> n;

	priority_queue<Person, vector<Person>, personCompare> pq;


	for (int i = 0; i < n; i++ ) {

		cin >> name >> age;
		Person p(name, age);
		pq.push(p);
	}

	cout << "Person in ascending order of age : " << endl;

	while (!pq.empty()) {

		Person per = pq.top();
		cout << per.name << " " << per.age << endl;
		pq.pop();

	}

	return 0;
}