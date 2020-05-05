#include "iostream"
using namespace std;

template<class T>
class Stack {
private:
	T *str;
	int size;
	int top;
public:
	Stack() {
		size = 10;
		top = -1;
		str = new T[this->size];
	}

	Stack(int size) {
		this->size = size;
		top = -1;
		str = new T[this->size];
	}

	void push(T x);
	T pop();
	int StackTop();
	void Display();
	int isFull();
	int isEmpty();
};

template<class T>
int Stack<T>::isFull() {
	if (top == size - 1)return 1;
	else return 0;
}

template<class T>
int Stack<T>::isEmpty() {
	if (top == -1)return 1;
	else return 0;
}

template<class T>
void Stack<T>::push(T x) {

	if (isFull()) {
		cout << "Stack Overflow" << endl;
	}
	else {
		top++;

		str[top] = x;
	}

	return;
}

template<class T>
T Stack<T>::pop() {
	T x = -1;
	if (isEmpty()) {
		cout << "Stack UnderFlow!!" << endl;
	}
	else {
		x = str[top];
		top--;
	}
	return x;
}

template<class T>
void Stack<T>::Display() {

	cout << "Element of the stack are: ";

	for (int i = 0; i <= top; i++) {
		cout << str[i] << " " ;
	}

	cout << endl;
}

bool isBalance(Stack<char> *stk, char *expr ) {

	int i = 0;
	char x;

	while (expr[i] != '\0') {

		if ((expr[i] == '{') or (expr[i] == '[') or (expr[i] == '(') ) {
			stk->push(expr[i]);
		}
		else if (expr[i] == '}') {
			x = stk->pop();
			if (x != '{')return false;
		}
		else if (expr[i] == ']') {
			x = stk->pop();
			if (x != '[')return false;
		}

		else if (expr[i] == ')') {
			x = stk->pop();
			if (x != '(')return false;
		}

		i++;
	}

	if (stk->isEmpty())return true;

	return false;

}
int main() {

	Stack<char> stk(100);
	char expr[] = "{[a+b]*[(a+b)*c]}";

	bool res = isBalance(&stk , expr);
	cout << res << endl;

	char expr1[] = "{[a+b]*[(a+b)*c]]}";
	res = isBalance(&stk , expr1);
	cout << res << endl;

	return 0;
}