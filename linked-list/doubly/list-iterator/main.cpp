#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

int main() {
	List<int> l;
	l.insertFront(1);
	l.insertBack(3);
	l.insert(++l.begin(), 2);
	
	for (List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}