#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Array {
	public:
		//ctor
		Array() {
			len = 0;
			data = new T[len];
		}
		
		//dtor
		~Array() {
			delete[] data;
		}
		
		//index operator overload
		T operator [](int i) const throw(out_of_range) {
			if (i < 0 || i >= len) {
				throw out_of_range("Invalid Index");
			} else {
				return data[i];
			}
		}
		
		//adds element and increases the length of the list by one
		void add(T e, int i) throw(out_of_range) {
			if (i < 0 || i > len) {
				throw out_of_range("Invalid Index");
			}
			
			//copy elements into a larger array
			T* temp = new T[len+1];
			for (int j = 0; j < len + 1; j++) {
				if (j < i) {
					temp[j] = data[j];
				}
				if (j > i) {
					temp[j] = data[j-1];
				}
			}
			
			//set index i element to e
			temp[i] = e;
			
			//delete stray mem and set our data to this sized up array
			delete[] data; 
			data = temp;
			
			//increment length
			len++;
		}
		
		//removes element and decreases size by 1
		T remove(int i) throw(out_of_range) {
			if (i < 0 || i >= len) {
				throw out_of_range("Invalid Index");
			}
			
			//copy remaining elems into downsized array
			T* temp = new T[len-1];
			for (int j = 0; j < len; j++) {
				if (j < i) {
					temp[j] = data[j];
				}
				if (j > i) {
					temp[j-1] = data[j];
				}
			}
			
			//delete stray mem and reset data to this sized down array
			delete[] data;
			data = temp;
			
			//decrement length
			len--;
		}
		
		int len;
		
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
		T* data;
		
};

template<typename T>
ostream& operator<< (ostream &out, Array<T> const& a) {
	int i = 0;
	while (i < a.len) {
		out << a[i] << ' ';
		i++;
	}
	return out;
}