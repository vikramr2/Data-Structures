#include <iostream>

using namespace std;

bool isMultiple(int a, int b) {
	return (a % b == 0);
}

int main() {
	int l1 = 12345678L;
	int l2 = 2L;
	cout << isMultiple(l1, l2) << endl;
	l1 = 123456789L;
	cout << isMultiple(l1, l2) << endl;
}