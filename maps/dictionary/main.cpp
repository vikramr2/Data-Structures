#include <iostream>
#include "Dictionary.h"

using std::cout;
using std::endl;

int main() {
	Dictionary<char, int> d;
	d.insert('a', 1);
	d.insert('a', 2);
	d.insert('d', 2);
	d.insert('e', 1);
	for (int i = 0; i < d.findAll('a').size(); i++) {
		cout << "a: " << d.findAll('a')[i].value << endl;
	}
	
	for (int i = 0; i < d.findAll('d').size(); i++) {
		cout << "d: " << d.findAll('d')[i].value << endl;
	}
	
	for (int i = 0; i < d.findAll('e').size(); i++) {
		cout << "e: " << d.findAll('e')[i].value << endl;
	}
}