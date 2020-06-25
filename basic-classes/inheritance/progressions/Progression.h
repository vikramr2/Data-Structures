#ifndef prog
#define prog
#include <iostream>

using namespace std;

class Progression {
	public:
		Progression(long f = 0) : first(f), cur(f) {}
		virtual ~Progression() {};
		void printProgression(int n);
	protected:
		virtual long firstVal();
		virtual long nextVal();
		long first;
		long cur;
};
#endif