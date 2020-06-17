#include "VectorTree.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	VectorTree<int> v;
	for (int i = 1; i < 20; i++) {
		v.addLeaf(i);
	}
	cout << "\nPreorder:" << endl; 
	v.preorder();
	cout << "\nInorder:" << endl;
	v.inorder();
	cout << "\nPostorder:" << endl;
	v.postorder();
	cout << "\nHeight: " << v.height() << endl;
}