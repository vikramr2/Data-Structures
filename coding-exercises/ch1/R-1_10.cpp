#include <iostream>

using namespace std;

void f(int x) {cout << ++x << endl;}
void g(int& x) {cout << ++x << endl;}
//void h(const int& x) {cout << ++x << endl;}

int main() {
	int a = 5;
	cout << a << endl;
	f(a);
	cout << a << endl;
	g(a);
	cout << a << endl;
	//h(a);
	//cout << a << endl;
}