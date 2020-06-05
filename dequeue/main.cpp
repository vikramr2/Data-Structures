#include "Dequeue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Dequeue<int>* d = new Dequeue<int>;
	d->insertFront(2);
	d->insertFront(1);
	d->insertBack(3);
	d->print();
	cout << "Front: " << d->front() << "\nBack: " << d->back() << endl;
	d->eraseFront();
	d->eraseBack();
	d->print();
	delete d;
}
	