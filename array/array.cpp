#include <iostream>

using namespace std;

int main() {
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