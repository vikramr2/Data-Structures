#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList<int>* l = new LinkedList<int>;
	l->addFront(1);
	l->addFront(2);
	l->addFront(3);
	cout << *l << endl;
	cout << l->size() << endl;
	l->removeFront();
	cout << *l << endl;
	delete l;
}