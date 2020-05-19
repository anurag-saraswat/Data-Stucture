#include "iostream"
#include"Queue.h"
using namespace std;


int main() {

	Queue<char> que;
	cout << que.isEmpty() << endl;

	TNode<char> *temp = new TNode<char>();
	temp->key = 'a';
	que.enqueue(temp);
	que.Display();

	temp = new TNode<char>();
	temp->key = 'b';
	que.enqueue(temp);
	que.Display();

	return 0;
}