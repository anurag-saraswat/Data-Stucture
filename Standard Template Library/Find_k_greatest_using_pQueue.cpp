#include "iostream"
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;


int main() {

	int n, init = 3;
	priority_queue<int, vector<int>, greater<int>> pq;

	while (scanf("%d", &n) != EOF) {
		if (init != 0) {
			init --;
			pq.push(n);
		}
		pq.push(n);
		pq.pop();
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}