#include "AVL.h"
#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	BST<int> b;
	AVL<int> a;
	
	b.insert(2);
	b.insert(1);
	b.insert(5);
	b.insert(4);
	b.insert(3);
	
	a.insert(2);
	a.insert(1);
	a.insert(5);
	a.insert(4);
	a.insert(3);
	
	//testing parents
	cout << "PARENT TEST: " << a.find(2)->left->parent->data << endl;
	
	cout << "AVL INORDER :";
	a.inorder();
	cout << "BST INORDER :";
	b.inorder();
	
	//AVL should have a lower height due to correct rebalancing
	cout << "AVL Height: " << a.height() << endl;
	cout << "BST Height: " << b.height() << endl;
	
	a.remove(5);
	cout << "AVL INORDER (After Removal):";
	a.inorder();
}