#include "Progression.h"

void Progression::printProgression(int n) {
	cout << firstVal();
	for (int i = 2; i <= n; i++) {
		cout << ' ' << nextVal();
	}
	cout << endl;
}

long Progression::firstVal() {
	cur = first;
	return cur;
}

long Progression::nextVal() {
	return ++cur;
}