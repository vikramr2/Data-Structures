#include <iostream>
#include "Scores.h"

using namespace std;

int main() {
	Scores s(4);
	const Scores::GameEntry e1 = {"Bob", 2};
	const Scores::GameEntry e2 = {"Vik", 3};
	s.add(e1);
	s.add(e2);
	s.print();
}