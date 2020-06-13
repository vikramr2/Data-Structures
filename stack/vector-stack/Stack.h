#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

template<typename T>
class Stack {
	public:
		Stack() : data(new vector<T>) {}
		~Stack() { delete data; }
		
		int size() { return data->size(); }
		bool empty() { return data->empty(); }
		
		const T top() const throw() { 
			if (empty()) {
				throw("Stack is Empty");
			}
			return data->back();
		}
		
		void push(T e) { data->push_back(e); }
		void pop() { data->pop_back(); }
		
		void print() {
			for (int i = 0; i < data->size(); i++) {
				cout << data->at(i) << ' ';
			}
			cout << endl;
		}
	private:
		vector<T>* data;
};