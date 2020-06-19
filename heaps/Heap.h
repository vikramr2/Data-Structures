#include <vector>
#include <iostream>
#include <stdexcept>

using std::swap;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
class Heap {
	public:
		/*initialize vector to have 1 dummy element
		  doing so makes 1 the first index
		  this is becuase we define 2*i as i's left child*/
		Heap() : data(new vector<T>) {
			data->push_back(T());
		}
		~Heap() { delete data; }
		
		//size is therefore the vector's size minus 1
		int size() { return data->size()-1; }
		bool empty() { return (size()==0); }
		
		//HEAP PROPERTY: Root is the min (min heap) or max (max heap)
		T min() { return data[1]; }
		
		//push back and reorder via heapify up to reorder
		void add(T e) {
			data->push_back(e);
			heapifyUp(size());
		}
		
		//remove minimum
		T removeMin() {
			if (empty()) return T();
			
			//swap min to back
			T temp = (*data)[1];
			swap((*data)[1], (*data)[size()]);
			
			//pop back 
			data->pop_back();
			
			//reorder via heapify down
			heapifyDown(1);
			return temp;
		}
		
		//For testing purposes
		void print() {
			for (int i = 1; i <= size(); i++) {
				cout << (*data)[i] << ' ';
			}
			cout << endl;
		}
	private:
		vector<T>* data;
		
		//reorder from down up
		void heapifyUp(int n) {
			//if were already up then we're done
			if (n==1) return;
			
			/*vector tree definition: parent is the index divided by two (int division)
			  this was explained in my VectorTree class*/
			int parent = n/2;
			
			//swap with parent if not ordered and recurse up
			if ((*data)[n] < (*data)[parent]) {
				swap((*data)[n], (*data)[parent]);
				heapifyUp(parent);
			}
		}
		
		//reorder from top down
		void heapifyDown(int n) {
			//same vector tree definition for children
			int left = n*2;
			int right = n*2+1;
			
			//get minimum element between current left and right
			int smallest = n;
			
			//checking if we're in bounds
			if (left <= size() && (*data)[left] < (*data)[smallest]) {
				smallest = left;
			}
			
			if (right <= size() && (*data)[right] < (*data)[smallest]) {
				smallest = right;
			}
			
			//if not ordered, swap with min child and recurse down
			if (smallest != n) {
				swap((*data)[n], (*data)[smallest]);
				heapifyDown(smallest);
			}
		}
};