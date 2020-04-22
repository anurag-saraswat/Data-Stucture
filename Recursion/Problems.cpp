#include "iostream"
using namespace std;

int factorial(int n) {
	if (n == 1 or n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

int sumNaturalnum(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return n + sumNaturalnum(n - 1);
	}
}


int power(int n, int m) {
	if (m == 0) {
		return 1;
	}
	else {
		return n * power(n, m - 1);
	}
}

int main() {
	int result = power(3, 2);
	cout << result << endl;
	return 0;
}