#include <iostream>
#include <math.h> 

using namespace std;

bool isTwoPower(int i) {
	double l = log2(double(i));
	return l == int(l);
}

int sumOdd(int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			ret += i;
		}
	}
	return ret;
}

int div2(int d) {
	int ret = 0;
	while (d > 2.0) {
		ret++;
		d /= 2.0;
	}
	return ret;
}

int main() {
	if (isTwoPower(1024)) {
		cout << 1024 << " is a power of 2" << endl;
	}
	if (!isTwoPower(1000)) {
		cout << 1000 << " is not a power of 2" << endl;
	}
	
	cout << sumOdd(10) << endl;
	cout << sumOdd(2) << endl;
	
	cout << div2(1025.0) << endl;
	cout << div2(2.1) << endl;
}