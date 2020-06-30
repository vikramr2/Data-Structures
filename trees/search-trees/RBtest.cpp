#include "RB.h"

int main() {
	RB<int> r;
	r.insert(3);
	r.insert(2);
	r.insert(1);
	r.insert(4);
	
	//TESTING ONLY
	/*r.testSetup(3);
	cout << r.find(3)->right->data << endl;*/
	
	r.inorder();
	r.preorder();
}