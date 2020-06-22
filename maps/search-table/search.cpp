#include "SearchTable.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	SearchTable<int, int> s;
	s.put(2, 3);
	s.put(1, 2);
	s.put(3, 1);
	s.put(2, 4);
	for (typename SearchTable<int, int>::iterator i = s.begin(); i != s.end(); ++i) {
		cout << (*i).value << endl;
	}
	cout << s.size() << endl;
	cout << s.higherEntry(2)->value << endl;
	cout << s.lowerEntry(2)->value << endl;
	cout << s.ceilingEntry(2)->value << endl;
	cout << s.floorEntry(2)->value << endl;
}