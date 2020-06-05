#include "LinkedList.h"
#include <iostream>

template<typename T>
class Queue {
	public:
		Queue() : data(new LinkedList<T>), s(0) {}
		~Queue() { delete data; }
		
		//Adds to back
		void enqueue(T e) { 
			data->add(e);
			
			//to reset queue to adding back instead of front, we advance
			data->advance();
			s++; 
		}
		
		//Removes from front
		void dequeue() throw() { data->remove(); s--; }
		
		//Must throw exception if the queue is empty
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