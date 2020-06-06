#include <iostream>
#include <list>
#include<algorithm>

using namespace std;


int main() {

	list<pair<int, int>> *l;
	int v, e;

	cout << "Enter no. vertices: ";
	cin >> v;

	l = new list<pair<int, int>>[v];

	cout << "Enter no. of edges: ";
	cin >> e;

	cout << "Enter Edges with weight:" << endl;

	int x, y, w;

	for (int i = 0; i < e; i++) {

		cin >> x >> y >> w;

		l[x].push_back(make_pair(y, w));

		l[y].push_back(make_pair(x, w));

	}


	for (int i = 0; i < v; i++) {

		cout << "Vertex : " << i << " :";

		for (auto it : l[i]) {

			cout << "(" << it.first << "," << it.second << ")";
		}

		cout << endl;
	}

	return 0;
}