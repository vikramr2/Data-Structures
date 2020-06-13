#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Vector {
	public:
		//ctors
		Vector() : capacity(0), len(0), data(NULL) {}
		Vector(const Vector& v) {
			capacity = v.capacity;
			len = v.len;
			data = new T[v.capacity];
			for (int i = 0; i < v.len; i++) {
				data[i] = v.data[i];
			}
		}
		Vector& operator=(const Vector& v) {
			if (this != &v) {
				capacity = v.capacity;
				len = v.len;
				data = new T[v.capacity];
				for (int i = 0; i < v.len; i++) {
					data[i] = v.data[i];
				}
			}
			return *this;
		}
		
		//dtor
		~Vector() {
			len = 0;
			capacity = 0;
			if (data) {
				delete[] data;
			}
		}
		
		T at(int i) const throw(out_of_range) { 
			//invalid index
			if (i < 0 || i >= len) {
				throw out_of_range("Invalid Index");
			} else {
				return data[i];
			}
		}

		//index operator overload
		T operator [](int i) const { return data[i]; }
		
		//adds element and increases the length of the list by one
		void add(T e, int i) throw(out_of_range) {
			//overflow check: is our number of elements greater than current capacity?
			if (len >= capacity) {
				reserve(max(1, 2*capacity));
			}
			
			//shift elements
			for (int j = len-1; j >= i; j--) {
				data[j+1] = data[j];
			}
			
			//set passed index to element and increment length
			data[i] = e;
			len++;
		}
		
		//removes element and decreases size by 1
		void remove(int i) {
			//shift left and decrement length
			for (int j = i+1; j < len; j++) {
				data[j-1] = data[j];
			}
			len--;
		}
		
		
		void reserve(int N) {
			if (capacity >= N) return;
			T* B = new T[N];
			for (int j = 0; j < len; j++) {
				B[j] = data[j];
			}
			if (data) delete[] data;
			data = B;
			capacity = N;
		}
		
		int size() { return len; }
		bool empty() { return (len == 0); }

		void sort() {
			for (int i = 1; i < len; i++) {
				T cur = data[i];
				int j = i - 1;
				while ((j >= 0) && (data[j] > cur)) {
					data[j+1] = data[j];
					j--;
				}
				data[j+1] = cur;
			}
		}
	private:
		int capacity;
		int len;
		T* data;
};

template<typename T>
ostream& operator<< (ostream &out, Vector<T> a) {
	int i = 0;
	while (i < a.size()) {
		out << a[i] << ' ';
		i++;
	}
	return out;
}