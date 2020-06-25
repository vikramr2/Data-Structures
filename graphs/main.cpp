#include <iostream>
#include "Graph.h"

using std::cout;
typedef Graph<int>::vertex vertex;

int main() {
	//create vertices
	vertex a = {1, false};
	vertex b = {2, false};
	vertex c = {3, false};
	vertex d = {4, false};
	
	//lets traverse a cycle
	Graph<int> g;
	g.insertEdge(&a, &b);
	g.insertEdge(&b, &c);
	g.insertEdge(&c, &a);
	g.DFS(&a);
}
	