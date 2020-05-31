#include "Progression.h"
#include <iostream>

using namespace std;

class ArithProgression : public Progression {
	public:
		ArithProgression(long i = 1);
	protected:
		virtual long nextVal();
		long inc;
};