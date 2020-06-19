#include <iostream>
#include "Heap.h"

using std::cout;
using std::endl;

//The heapsort can sort a set using a heap in O(nlogn) time
int main() {
	//unordered array
	int arr[5] = {3, 4, 1, 5, 2};
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	//initialize heap and add array elements
	Heap<int> h;
	for (int i = 0; i < 5; i++) {
		h.add(arr[i]);
	}
	h.print();
	
	//then remove from heap one by one and set in array
	for (int i = 0; i < 5; i++) {
		arr[i] = h.removeMin();
		h.print();
	}
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	/*this works because the heap will remove minimum elements first
	  since each removal is O(logn) time, and we have n removals, 
	  that results in O(nlogn) time*/
}