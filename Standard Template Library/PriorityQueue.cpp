#include "iostream"
#include <queue>

using namespace std;

int main() {

	int n = 20;


	//Max priority queue

	priority_queue<int> pq_max;

	for (int i = 0; i < n; i++)pq_max.push(i);

	while (!pq_max.empty()) {
		cout << pq_max.top() << " ";
		pq_max.pop();
	}

	cout << endl;


	//Min Priority Queue

	priority_queue<int, vector<int>, greater<int>> pq_min;

	for (int i = 0; i < n; i++)pq_min.push(i);

	while (!pq_min.empty()) {
		cout << pq_min.top() << " ";
		pq_min.pop();
	}

	cout << endl;

	return 0;
}
