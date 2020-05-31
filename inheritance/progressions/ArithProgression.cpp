#include "ArithProgression.h"

ArithProgression::ArithProgression(long i) : Progression(), inc(i) {}

long ArithProgression::nextVal() {
	cur += inc;
	return cur;
}