#include "iostream"
using namespace  std;


template<class T>
class Node {
	T
};


template<class T>
class Queue {
private:
	T *front;
	T *rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}

	void Display();
	void Enqueue(T x);
	T Deque();
};

template<class T>
void Queue<T>::Enqueue(T x) {



}




int main() {


	return 0;
}
