#include "Heap.h"
#include <iostream>

using std::ostream;

//type S serves as a priority value, type T is the actual data value
template <typename S, typename T>
class PriorityQueue {
	public:
		//data type to group type S and type T into one
		struct pair {
			S key;
			T value;
			
			//must overload <, > for comparisons to work in heap operations
			bool operator<(const pair& other) { return key < other.key; }
			bool operator>(const pair& other) { return key > other.key; }
		};
	public:
		PriorityQueue() : data(new Heap<pair>) {}
		~PriorityQueue() { delete data; }
		
		int size() { return data->size(); }
		bool empty() { return data->empty(); }
		
		void insert(S k, T v) { 
			pair p = {k, v};
			data->add(p);
		}
		
		pair min() { return data->min(); }
		pair remove() { return data->removeMin(); }
	private:
		//our data will essentially be a heap of pairs
		Heap<pair>* data;
};

/*This is so that C++ doesn't complain as heap's "print()" function needs 
  to be able to run "cout << data[i]"*/
template <typename S, typename T>
ostream& operator<<(ostream& os, const typename PriorityQueue<S, T>::pair g) { 
	os << '<' << g.key << ", " << g.value << '>';
	return os;
}