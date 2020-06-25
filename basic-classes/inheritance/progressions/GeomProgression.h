#include "Progression.h"
#include <iostream>

using namespace std;


class GeomProgression : public Progression {
	public:
		GeomProgression(long b = 2);
	protected:
		virtual long nextVal();
		long base;
};