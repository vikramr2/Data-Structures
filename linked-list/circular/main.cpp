#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int>* l = new LinkedList<int>;
	l->add(1);
	l->add(2);
	l->add(3);
	l->add(4);
	cout << *l << endl;
	l->advance();
	cout << *l << endl;
	l->remove();
	cout << *l << endl;
	l->reverse();
	cout << *l << endl;
	delete l;
}