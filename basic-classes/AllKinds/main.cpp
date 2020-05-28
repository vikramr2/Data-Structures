#include <iostream>
#include "AllKinds.h"

int main() {
	AllKinds a(1, 1234L, 12.34f);
	cout << a.i_f() << ", " << a.i_l() << ", " << a.l_f() << a.all() << endl;
	a.setInt(2);
	a.setLong(123456789L);
	a.setFloat(12.3456789f);
	cout << a.i_f() << ", " << a.i_l() << ", " << a.l_f() << a.all() << endl;
}