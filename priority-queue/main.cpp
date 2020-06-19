#include "PriorityQueue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	PriorityQueue<int, char> p;
	p.insert(2, 'c');
	p.insert(4, 'a');
	p.insert(1, 'd');
	p.insert(3, 'f');
	
	//should print d, c, f, a
	cout << p.remove().value << endl;
	cout << p.remove().value << endl;
	cout << p.remove().value << endl;
	cout << p.remove().value << endl;
}