#include <iostream>
#include <vector>
#include "Array.h"

using namespace std;

int main() {
	Array<int> a;
	a.add(1, 0);
	a.add(6, 1);
	a.add(5, 2);
	cout << a << endl;
	a.remove(0);
	cout << a << endl;
	a.add(4, 2);
	cout << a << endl;
	a.add(8, 0);
	cout << a << endl;
	a.sort();
	cout << a << endl;
	
	Array<char> c;
	c.add('c', 0);
	c.add('h', 1);
	c.add('a', 2);
	c.sort();
	cout << c << endl;
	
	//lets make a matrix
	
	//static
	int M[10][10];
	for (int i = 0; i < 10; i++) { //Times Table!
		for (int j = 0; j < 10; j++) {
			M[i][j] = (i+1)*(j+1);
		}
	}
	
	for (int i = 0; i < 10; i++) { //Print!
		for (int j = 0; j < 10; j++) {
			cout << M[i][j] << ' ';
		}
		cout << endl;
	}
	
	//dynamic
	int** D = new int*[10];
	for (int i = 0; i < 10; i++) {
		D[i] = new int[10];
	}
	
	for (int i = 0; i < 10; i++) { //Times Table!
		for (int j = 0; j < 10; j++) {
			D[i][j] = (i+1)*(j+1);
		}
	}
	
	for (int i = 0; i < 10; i++) { //Print!
		for (int j = 0; j < 10; j++) {
			cout << D[i][j] << ' ';
		}
		cout << endl;
	}
	
	for (int i = 0; i < 10; i++) { //deletion
		delete[] D[i];
	}
	delete[] D;
	
	
	//vector
	vector< vector<int> > V(10, vector<int>(10)); //10x10
	cout << V[5][5] << endl;
}