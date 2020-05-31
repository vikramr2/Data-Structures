#include "GeomProgression.h"

GeomProgression::GeomProgression(long b) : Progression(1), base(b) {}

long GeomProgression::nextVal() {
	cur *= base;
	return cur;
}