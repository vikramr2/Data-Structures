#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

int main() {
	Pair<int, int> p1(1, 2);
	cout << p1 << endl;
	Pair<string, double> p2("a", 2.3);
	cout << p2 << endl;
	
	//NOTE: must have space '> >' or it'll be '>>'
	Pair<Pair<int, int>, Pair<string, double> > p3(p1, p2);
	cout << p3 << endl;
}