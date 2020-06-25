#include <iostream>
#include "Progression.h"
#include "GeomProgression.h"
#include "ArithProgression.h"

int main() {
	Progression* p;
	
	cout << "Arith" << endl;
	p = new ArithProgression(5);
	p->printProgression(10);
	
	cout << "Geom" << endl;
	p = new GeomProgression(3);
	p->printProgression(10);
}
	