#include "HashMap.h"
#include <tr1/functional>
#include <iostream>

int main() {
	HashMap<int, int, std::tr1::hash<int> > h(4);
	h.put(1, 1);
	h.put(5, 2); //collision: handled through separate chaining
	h.put(0, 3);
	h.put(2, 4);
	h.put(3, 5);
	for (typename HashMap<int, int, std::tr1::hash<int> >::Iterator i = h.begin(); !(i == h.end()); ++i) {
		std::cout << (*i).value << std::endl;
	}
}
	