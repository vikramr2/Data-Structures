#include "LinkedList.h"
#include <iostream>

using namespace std;

template<typename T>
class Stack {
	public:
		Stack() : data(new LinkedList<T>), s(0) {}
		~Stack() { delete data; }
		int size() const { return s; }
		bool empty() const { return (s == 0); }
		const T top() const throw() { 
			if (empty()) {
				throw("Stack is Empty");
			}
			return data->head->elem; 
		}
		void push(T e) { 
			data->addFront(e); 
			s++;
		}
		void pop() throw() { 
			if (empty()) {
				throw("Stack is Empty");
			}
			data->removeFront();
			s--;
		}
		void print() { cout << *data << endl; }
	private:
		LinkedList<T>* data;
		int s;
};