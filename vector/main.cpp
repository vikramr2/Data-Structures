#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
	Vector<int> a;
	a.add(1, 0);
	a.add(6, 1);
	a.add(5, 2);
	cout << a << endl;
	a.remove(1);
	cout << a << endl;
	a.add(4, 2);
	cout << a << endl;
	a.add(8, 0);
	cout << a << endl;
	a.sort();
	cout << a << endl;
	
	Vector<char> c;
	c.add('c', 0);
	c.add('h', 1);
	c.add('a', 2);
	c.sort();
	cout << c << endl;
}