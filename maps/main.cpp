#include <iostream>
#include "Map.h"

using std::cout;
using std::endl;

int main() {
	Map<int, char> m;
	m.put(1, 'f');
	m.put(2, 'a');
	Map<int, char>::entry& e = *(m.find(2));
	cout << e.value << endl;
	cout << m.size() << endl;
	m.put(2, 'b');
	cout << e.value << endl;
	cout << m.size() << endl;
}