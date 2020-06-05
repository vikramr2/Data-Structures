#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
	Stack<int>* s = new Stack<int>;
	cout << s->empty() << endl;
	s->push(1);
	s->push(2);
	s->push(3);
	s->print();
	s->pop();
	s->print();
	delete s;
}