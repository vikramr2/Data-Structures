#include <vector>
#include <iostream>
#include "Map.h"

using std::cout;
using std::endl;
using std::vector;

/*A search table is also called an "ordered map".
  Basically a map that stays sorted*/
template <typename K, typename V>
class SearchTable {
	public:
		//redefining types from map
		typedef typename Map<K, V>::entry entry;
		typedef typename Map<K, V>::iterator iterator;
	public:
		SearchTable() : data(new vector<entry>) {}
		~SearchTable() { delete data; }
		
		//Map methods
		int size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		iterator begin() const { return data->begin(); }
		iterator end() const { return data->end(); }
		void erase(const K& k) throw() { 
			if (find() == -1) throw("Out of Bounds");
			data->erase(find(k)); 
		}
		
		//binary search from whole array
		int find(const K& k) const { 
			return find(0, size()-1, k); 
		}
		
		//put new entry in sorted location
		iterator put(const K& k, const V& v) {
			//if the element exists, just reset key
			if (find(k) != -1) {
				(begin()+(find(k)))->value = v;
				return begin()+find(k);
			}
			
			//create new entry
			entry e = {k, v};
			
			//if the list of entries is empty, push back
			if (empty()) {
				data->push_back(e);
				return begin();
			}
			
			//iterate until the right ordered spot is found for the new entry
			for (iterator i = begin(); i != end(); ++i) {
				if ((*i).key > k) {
					data->insert(i, e);
					return i;
				}
			}
			
			//otherwise, if the entry is greater than all items, push back
			data->push_back(e);
			return end()-1;
		}
		
		//get min and max iterator
		iterator firstEntry() const { return begin(); }
		iterator lastEntry() const { return end()-1; }
		
		//iterate to ceiling and floor entries of given key
		iterator ceilingEntry(const K& k) {
			for (iterator i = begin(); i != end(); ++i) {
				if ((*i).key >= k) {
					return i;
				}
			}
			return end();
		}
		iterator floorEntry(const K& k) {
			for (iterator i = end()-1; i != begin()-1; --i) {
				if ((*i).key <= k) {
					return i;
				}
			}
			return end();
		}
		
		//iterate to higher and lower entries of the given key
		iterator higherEntry(const K& k) {
			for (iterator i = begin(); i != end(); ++i) {
				if ((*i).key > k) {
					return i;
				}
			}
			return end();
		}
		iterator lowerEntry(const K& k) {
			for (iterator i = end()-1; i != begin()-1; --i) {
				if ((*i).key < k) {
					return i;
				}
			}
			return end();
		}
	private:
		vector<entry>* data;
		
		//binary search helper
		int find(int beg, int last, const K& k) const {
			//check if last index is invalid
			if (last < 0) return -1;
			
			//if the list is empty, then an invalid index is returned
			if (empty()) return -1;
			
			//if we're down to one element, check if it is what we're searching for
			if (beg == last) {
				if (data->at(beg).key != k) return -1;
				else return beg;
			}
			
			//get and check middle value
			int middle = (beg + last)/2;
			if (data->at(middle).key == k) return middle;
			
			/*return a binary search of whichever side of middle doesn't return invalid index
			  if both are invalid, return -1*/
			if (find(beg, middle-1, k) != size()) return find(beg, middle-1, k);
			if (find(middle+1, last, k) != size()) return find(middle+1, last, k);
			return -1;
		}
};