#include <iostream>

using namespace std;

inline int sum(int n) {return (n-1)*n/2;}

int main() {
	cout << sum(11) << endl; //SHOULD BE 45
}