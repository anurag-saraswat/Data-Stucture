// String Class is alternative of char *

#include "iostream"
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {

	if (a.length() == b.length()) {
		return a < b;
	}
	else {

		return a.length() < b.length();
	}

}

int main() {

	string arr[100];
	int n;

	cin >> n;
	cin.get();

	for (int i = 0; i < n; i++) {
		getline(cin, arr[i]);
	}

	sort(arr, arr + n, compare);

	cout << endl << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}







