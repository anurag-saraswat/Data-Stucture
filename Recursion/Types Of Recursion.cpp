

#include "iostream"
using namespace std;


//Recursive recction call is present at the end/tail
//At returning time recction does not perform any thing
void rec_tail(int n) {
	if (n > 0) {

		cout << n << "\t";
		rec_tail(n - 1);

	}
}

//Recursive recction call is present at the start/head
//No statement before recursive call
void rec_head(int n) {
	if (n > 0) {
		rec_head(n - 1);
		cout << n << "\t";
	}
}

void rec_tree(int n) {
	if (n > 0) {
		cout << n << "\t";
		rec_tree(n - 1);
		rec_tree(n - 1);
	}
}


void rec_indirectB(int n);

void rec_indirectA(int n) {
	if (n > 0) {
		cout << n << "\t";
		rec_indirectB(n - 1);
	}
}
void rec_indirectB(int n) {
	if (n > 1) {
		cout << n << "\t";
		rec_indirectA(n / 2);
	}
}

int rec_nested(int n) {
	cout << n << "\t";
	if (n > 100) {
		return n - 10;
	}
	else {
		return rec_nested(rec_nested(n + 11));
	}
}


int main() {

	cout << "Tail Recursion: ";
	rec_tail(5);
	cout << endl << "Head Recursion: ";
	rec_head(5);
	cout << endl << "Tree Recursion: ";
	rec_tree(4);
	cout << endl << "Indirect Recursion: ";
	rec_indirectA(100);
	cout << endl << "Nested Recursion: ";
	rec_nested(95);
	cout << endl;

	return 0;

}