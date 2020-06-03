#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
	public:
		struct Node {
			T elem;
			Node* next;
		};
		LinkedList() : head(NULL) {}
		~LinkedList() { while(!empty()) removeFront(); }
		bool empty() const { return !head; }
		const T& front() const { return head->elem; }
		void addFront(const T& e) {
			Node* h = new Node;
			h->elem = e;
			h->next = head;
			head = h;
		}
		void removeFront() {
			Node* h = head;
			head = h->next;
			delete h;
		}
		Node* head;
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