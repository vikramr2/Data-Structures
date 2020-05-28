#include <iostream>

using namespace std;

void printArray(int** A, int m, int n) {
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	//This is how you initialize an n*m dynamic array
	int** A = new int*[5];
	
	for (int i = 0; i < 5; i++) {
		A[i] = new int[4];
	}
	
	//filling values
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = i*j;
		}
	}
	
	printArray(A, 4, 5);
	
	//This is how you delete a dynamic array
	for (int i = 0; i < 5; i++) {
		delete[] A[i];
	}
	delete[] A;
}