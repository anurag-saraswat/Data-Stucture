#include "iostream"
using namespace std;

class fun {
public:

	void operator ()() {

		cout << "Inside Operator () of fun" << endl;
	}

};


int main() {

	fun f;  //constructor call

	f();   //Overloaded () operator = function call where f is a object // f is also called functor

	return 0;
}