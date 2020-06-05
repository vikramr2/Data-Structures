#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Queue<int>* q = new Queue<int>;
	cout << q->empty() << endl;
	q->enqueue(1);
	q->enqueue(2);
	q->enqueue(3);
	q->print();
	cout << q->front() << endl;
	q->dequeue();
	q->print();
	cout << q->front() << endl;
	delete q;
}

