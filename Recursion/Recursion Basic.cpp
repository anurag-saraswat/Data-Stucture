#include <iostream>
using namespace std;

void fun_reverse(int n) {

	if (n > 0) {
		cout << n << "\t";
		fun_reverse(n - 1);
	}


}

void fun_straight(int n) {

	if (n > 0) {
		fun_straight(n - 1);
		cout << n << "\t";
	}

}


int main() {
	fun_reverse(5);
	cout << endl;
	fun_straight(10);
	return 0;
}
