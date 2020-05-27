#include "iostream"
#include "Queue.h"
using namespace std;


void BFS(int G[][7], int size , int node ) {

	cout << "Breadth First Traversal of Graph is: ";

	int visited[size] = {0};

	cout << node << " ";
	visited[node] = 1;
	enqueue(node);

	while (!isEmpty()) {

		int u = dequeue();

		for (int v = 1; v < size; v++) {

			if (G[u][v] == 1 and visited[v] == 0) {

				cout << v << " ";
				visited[v] = 1;
				enqueue(v);
			}
		}
	}

	cout << endl;
}

int main() {

	int G[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 1, 0, 1, 1},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0}
	};

	BFS(G, 7, 6);

	return 0;
}