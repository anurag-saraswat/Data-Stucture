#include <iostream>
#include <queue>

using namespace std;


int main() {

	queue<int> que;

	for (int i = 0; i < 10; i++)que.push(i);

	while (!que.empty()) {

		cout << que.front() << " ";
		que.pop();
	}

	cout << endl;

	return 0;
}