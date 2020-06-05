#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
	public:
		struct Node {
			T elem;
			Node* next;
		};
		LinkedList() : cursor(NULL) {}
		~LinkedList() { while(!empty()) remove(); }
		bool empty() const { return !cursor; }
		
		/*We define the back as the cursor
		  This means the front is cursor->next!*/
		const T& back() const { return cursor->elem; }
		const T& front() const { return cursor->next->elem; }
		
		/*Advance the cursor to the next node T
		  This essentially rotates the list*/
		void advance() throw() { 
			if (empty()) {
				throw("Cant advance");
			}
			cursor = cursor->next; 
		}
		
		void add(const T& e) {
			//initialize node
			Node* n = new Node;
			n->elem = e;
			
			//if list is empty, set cursor to this
			if (!cursor) {
				n->next = n;
				cursor = n;
			}
			
			//otherwise insert after cursor
			else {
				n->next = cursor->next;
				cursor->next = n;
			}
		}
		
		void remove() throw() {
			if (empty()) {
				throw("Cant remove");
			}
			Node* n = cursor->next;
			if (n == cursor) { 
				//is this the only node?
				cursor = NULL;
				
			//if not, shift cursor and delete old node
			} else {
				cursor->next = n->next;
			}
			delete n;
		}
			
		Node* cursor;
		
	private:
		int size;
};

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& l) {
	bool cycled = false;
	typename LinkedList<T>::Node* cur = l.cursor->next;
	while(!cycled) {
		os << cur->elem << ' ';
		cur = cur->next;
		if (cur == l.cursor->next) {
			cycled = true;
		}
	}
	return os;
}