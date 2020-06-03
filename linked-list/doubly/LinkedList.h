#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
	public:
		//each node stores data and a next pointer
		struct Node {
			T elem;
			Node* next;
			Node* prev;
		};
		LinkedList() : head(new Node), tail(new Node) {
			head->next = tail;
			tail->prev = head;
		}
		
		//delete each front in succession
		~LinkedList() {
			while(!empty()) removeFront();
			delete head;
			delete tail;
		}
		
		bool empty() const { return (head->next == tail); }
		const T& front() const { return head->next->elem; }
		const T& back() const { return tail->prev->elem; }
		
		void add(Node* v, const T& e) {
			Node* u = new Node; u->elem = e;
			u->next = v;
			u->prev = v->prev;
			v->prev->next = v->prev = u;
		}
		
		void addFront(const T& e) { add(head->next, e); }
		void addBack(const T& e) { add(tail, e); }
		
		void remove(Node* v) {
			Node* u = v->prev;
			Node* w = v->next;
			u->next = w;
			w->prev = u;
			delete v;
		}
		
		void removeFront() { remove(head->next); }
		void removeBack() { remove(tail->prev); }
		
		Node* head;
		Node* tail;
};

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& l) {
	typename LinkedList<T>::Node* cur = l.head->next;
	while (cur != l.tail) {
		os << cur->elem << ' ';
		cur = cur->next;
	}
	return os;
}