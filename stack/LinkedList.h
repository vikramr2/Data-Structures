#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
	public:
		//each node stores data and a next pointer
		struct Node {
			T elem;
			Node* next;
		};
		LinkedList() : head(NULL), s(0) {}
		
		//delete each front in succession
		~LinkedList() { while(!empty()) removeFront(); }
		
		bool empty() const { return !head; }
		const T& front() const { return head->elem; }
		
		//point new node to head, and reset head
		void addFront(const T& e) {
			Node* h = new Node;
			h->elem = e;
			h->next = head;
			head = h;
			s++;
		}
		
		//reset head and delete old head
		void removeFront() {
			Node* h = head;
			head = h->next;
			delete h;
			s--;
		}
		Node* head;
		
		int size() { return s; }
	private:
		int s;
};

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& l) {
	typename LinkedList<T>::Node* cur = l.head;
	while (cur) {
		os << cur->elem << ' ';
		cur = cur->next;
	}
	return os;
}