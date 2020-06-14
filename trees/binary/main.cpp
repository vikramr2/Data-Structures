#include <iostream>
#include "BinaryTree.h"

using std::cout;
using std::endl;

int main() {
	BinaryTree<int> b;
	b.addRoot(1);
	b.expandExternal(b.root(), 2, 3);
	b.expandExternal(b.root()->left, 4, 5);
	b.preorder();
	cout << endl;
	b.postorder();
	cout << endl;
	b.inorder();
	cout << endl;
	cout << b.height() << endl;
}