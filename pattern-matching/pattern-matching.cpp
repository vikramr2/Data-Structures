#include <string>
#include <iostream>
#include <algorithm>

using std::min;
using std::string;
using std::cout;
using std::endl;

//helper function: get last occurance of char in string
int last(string T, char c) {
	//get length of T
	int n = T.size();
	
	//iterate until a matching char is found
	for (int i = n-1; i >= 0; i--) {
		if (T[i] == c) {
			return i;
		}
	}
	
	//return -1 if not found
	return -1;
}

//naive pattern matching algo
int brute_force(string T, string P) {
	//sizes
	int n = T.size();
	int m = P.size();
	
	//iterate 1 by 1 until matching sequence is found
	for (int i = 0; i < n-m; i++) {
		int j = 0;
		while (j < m && T[i+j] == P[j]) j++;
		if (j==m) return i;
	}
	
	//return -1 if not found
	return -1;
}

//more complex algo
int boyer_moore(string T, string P) {
	int n = T.size();
	int m = P.size();
	
	//iterators
	int i = m-1;
	int j = m-1;
	
	//iterate and check backwards
	while (i <= n-1) {
		//if the character matches
		if (P[j] == T[i]) {
			/*if we're comparing the patterns first char, 
			  we found a match because of the backwards check*/
			if (j == 0) return i;
			
			//otherwise check backwards to see if other chars match
			else { i--; j--; }
			
		//otherwise just make a jump and check again
		} else {
			i = i + m - min(j, 1+last(P, T[i]));
			j = m-1;
		}
	}
	return -1;
}

int main() {
	string T = "abcdefg";
	string P = "def";
	cout << brute_force(T, P) << endl;
	cout << boyer_moore(T, P) << endl;
}