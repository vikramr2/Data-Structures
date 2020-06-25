#include "Set.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
	Set<int> S;
	S.insert(1); S.insert(2); S.insert(3);
	Set<int> T;
	T.insert(2); T.insert(3);
	S.Intersect(T);
	Set<int> U;
	U.insert(2);
	S.Subtract(U);
	Set<int> V;
	V.insert(4);
	S.Union(V);
	
	//after all these tranforms, should get {3, 4}
	for (int i = 0; i < S.size(); i++) {
		cout << S.getElems()[i] << endl;
	}
}