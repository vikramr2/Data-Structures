#include "LinkedList.h"
#include <iostream>

template<typename T>
class Queue {
	public:
		Queue() : data(new LinkedList<T>), s(0) {}
		~Queue() { delete data; }
		void enqueue(T e) { 
			data->add(e); 
			data->advance();
			s++; 
		}
		void dequeue() throw() { data->remove(); s--; }
		T front() throw() {
			if (empty()) {
				throw("Queue is Empty");
			}
			return data->front();
		}
		int size() const { return s; }
		bool empty() const { return (s == 0); }
		void print() { std::cout << *data << std::endl; }
	private:
		LinkedList<T>* data;
		int s;
};