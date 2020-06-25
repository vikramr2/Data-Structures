#include "Dictionary.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

//This is an undirected graph, meaning there are no directions marked in this graph
template <typename T>
class Graph {
	public:
		//vertex storing data and whether in DFS we've visited
		struct vertex {
			T value;
			bool visited;
			
			T operator*() { return value; }
		};
	public:
		//insert an edge between v1 and v2 by making them correspond to eachother
		void insertEdge(vertex* v1, vertex* v2) {
			data.insert(v1, v2);
			data.insert(v2, v1);
		}
		
		//get all adjacent vertices to the current vertex
		vector<vertex*> adjacent(vertex* v) { return data.corresponding(v); }
		
		/*Depth First Search Traversal
			- go as far as you can on one path
			- move to the next path when done*/
		void DFS(vertex* start) {
			//if we've already visited the starting point, this traversal has already been done
			if (!(start->visited)) {
				//if we haven't, then print the value and mark it visited
				cout << *(*start) << endl;
				start->visited = true;
			} 
			else return;
			
			//now recurse in the direction of the first vertex we haven't visited
			for (int i = 0; i < adjacent(start).size(); i++) {
				if (!(adjacent(start)[i]->visited)) {
					DFS(adjacent(start)[i]);
				}
			}
		}
	private:
		/*We'll use a dictionary where a vertex is a key, and its adjacent vertices are its values
		  This representation is called the adjacency list representation*/
		Dictionary<vertex*, vertex*> data;
		
		/*other representations include
			- Adjacency matrices
				- vertices mark rows and columns
				- M[i][j] = 0 if there isnt an edge (ui, vj)
				- M[i][j] = 1 otherwise
			- Nodal structure
				- basically what we did with the general tree implementation!*/
};