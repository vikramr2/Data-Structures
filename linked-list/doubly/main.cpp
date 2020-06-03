#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int>* l = new LinkedList<int>;
	l->addFront(2);
	l->addBack(3);
	l->addFront(1);
	cout << *l << endl;
	l->removeFront();
	l->removeBack();
	cout << *l << endl;
	delete l;
}