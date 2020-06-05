#include "LinkedList.h"
#include <iostream>

template<typename T>
class Dequeue {
	public:
		Dequeue() : data(new LinkedList<T>), s(0) {}
		~Dequeue() { delete data; }
		void insertFront(T e) { data->addFront(e); s++; }
		void insertBack(T e) { data->addBack(e); s++; }
		void eraseFront() throw() { data->removeFront(); s--; }
		void eraseBack() throw() { data->removeBack(); s--; }
		T front() throw() {
			if (empty()) {
				throw("Dequeue is empty");
			}
			return data->front(); 
		}
		T back() throw() { 
			if (empty()) {
				throw("Dequeue is empty");
			}
			return data->back(); 
		}
		int size() { return s; }
		bool empty() { return (s==0); }
		void print() { std::cout << *data << std::endl; }
	private:
		LinkedList<T>* data;
		int s;
};