#include "BTree.h"
#include <iostream>

int main() {
	BTree<int> t(3);
	t.add(1);
	t.add(2);
	t.add(4);
	t.add(3);
	
	BTree<int>::node* f = t.find(1);
	for (int i = 0; i < f->num_vals; i++) {
		cout << f->vals[i] << ' ';
	}
	cout << endl;
}
	