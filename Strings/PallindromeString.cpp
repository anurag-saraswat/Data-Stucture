#include "iostream"
using namespace std;


int main() {

	char s[] = "abaaaba";
	int i = 0, j = 0;
	char temp;

	while (s[i] != '\0') {
		i++;
	}
	i--;

	while (j < i) {

		if (s[i] == s[j]) {
			i--;
			j++;
		}
		else {
			cout << "Not Pallindrome String" << endl;
			exit(1);
		}

	}

	cout << "String is Pallindrome" << endl;

	return 0;
}