#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	BST<int> b;
	b.insert(2);
	b.insert(1);
	b.insert(5);
	b.insert(4);
	b.insert(3);
	b.remove(5);
	
	//should print 3
	cout << b.find(4)->left->data << endl;
	
	//should print 1, 2, 3, 4
	b.inorder();
}