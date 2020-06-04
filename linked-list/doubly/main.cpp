#include <iostream>
#include "LinkedList.h"

using namespace std;

template<typename T>
void reverse(LinkedList<T>& L) {
	LinkedList<T> L2;
	
	//copy into L2 via front
	while(!L.empty()) {
		T s = L.front();
		L.removeFront();
		L2.addFront(s);
	}
	
	//copy back via back
	while(!L2.empty()) {
		T s = L2.front();
		L2.removeFront();
		L.addBack(s);
	}
}

int main() {
	LinkedList<int>* l = new LinkedList<int>;
	l->addFront(2);
	l->addBack(3);
	l->addFront(1);
	cout << *l << endl;
	reverse(*l);
	cout << *l << endl;
	l->removeFront();
	l->removeBack();
	cout << *l << endl;
	l->removeFront();
	l->removeFront(); //throws exception
	delete l;
}