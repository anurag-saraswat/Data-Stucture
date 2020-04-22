#include "iostream"
using namespace std;


double rec_taylorSeries(int x, int n) {
	static double p = 1, f = 1;
	double result;

	if (n == 0) {
		return 1;
	}
	result = rec_taylorSeries(x, n - 1);
	p = p * x;
	f = f * n;
	return result + (p / f);
}

double iterative_taylorSeries_HornersRule(int x, int n) {
	double sum = 1;
	for (; n > 0; n--) {
		sum = 1 + (sum * x) / n ;
	}
	return sum;
}

double rec_taylorSeries_HornersRule(int x, int n) {

	static double sum = 1;

	if (n == 0) {
		return sum;
	}

	sum = 1 + (sum * x) / n;
	return rec_taylorSeries_HornersRule(x, n - 1);
}

int main() {

	double result = rec_taylorSeries(3, 20);
	cout << "Using Naive Approach: " << result << endl;

	result = iterative_taylorSeries_HornersRule(3, 20);
	cout << "Using Iterative Horners Rule: " << result << endl;

	result = rec_taylorSeries_HornersRule(3, 20);
	cout << "Using Recursive Horners Rule: " << result << endl;

	return 0;
}