#include "List.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void sort(List<T>& S) {
	int n = S.size();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n-1; j++) {
			typename List<T>::Iterator prec = S.atIndex(j-1);
			typename List<T>::Iterator succ = S.atIndex(j);
			if (*prec > *succ) {
				int tmp = *prec; *prec = *succ; *succ = tmp;
			}
		}
	}
}

int main() {
	List<int> l;
	l.insertBack(3);
	l.insertBack(1);
	l.insertBack(6);
	l.insertBack(5);
	l.insertBack(4);
	l.insertBack(2);
	l.insertBack(8);
	l.insertBack(7);
	l.insertBack(9);
	
	for (List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
	
	sort(l);
	for (List<int>::Iterator i = l.begin(); i != l.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}
	