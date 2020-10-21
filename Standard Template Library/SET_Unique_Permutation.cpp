#include "iostream"
#include <set>
#include <string>

using namespace std;



void permute(string a, int i , set<string> &s ) {

	if (a[i] == '\0') {
		s.insert(a);
		return;
	}

	//recursive case

	for (int j = i; a[j] != '\0'; j++) {

		swap(a[i], a[j]);
		permute(a, i + 1, s);
		swap(a[i], a[j]);

	}
}


int main() {

	set<string> s;
	string a = "abb";

	permute(a, 0, s);

	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}