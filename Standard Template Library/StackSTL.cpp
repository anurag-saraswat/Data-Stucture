#include <iostream>
#include <stack>

using namespace std;


int main() {


	stack<int> stk;

	for (int i = 0; i < 10; i++)stk.push(i);

	while (!stk.empty()) {

		cout << stk.top() << " ";
		stk.pop();
	}

	cout << endl;
	return 0;
}