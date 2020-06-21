#include <vector>

using std::vector;

template <typename K, typename V>
class Map {
	public:
		//every entry is a pair containing an address (key) and a value
		struct entry {
			K key;
			V value;
		};
		
		//redefine the map's iterator as the data vector's iterator
		typedef typename vector<entry>::iterator iterator;
	public:
		Map() : data(new vector<entry>) {}
		~Map() { delete data; }
	
		int size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		iterator begin() const { return data->begin(); }
		iterator end() const { return data->end(); }
		
		//find entry given its key
		iterator find(const K& k) const {
			//loop through data, return iterator to entry if it exists
			for (iterator i = begin(); i != end(); ++i) {
				if (i->key == k) {
					return i;
				}
			}
			
			//otherwise just return a NULL iterator
			return end();
		}
		
		//put in new entry in map
		iterator put(const K& k, const V& v) {
			//if this key exists in data, just reset the associated value
			for (iterator i = begin(); i != end(); ++i) {
				if (i->key == k) {
					i->value = v;
					return i;
				}
			}
			
			//otherwise add a new entry all together
			entry e = {k, v};
			data->push_back(e);
			return end();
		}
		
		//erase entry to given key
		void erase(const K& k) throw() { 
			if (find() == end()) throw("Out of Bounds");
			data->erase(find(k)); 
		}
	private:
		//implementation using a vector of key value entries
		vector<entry>* data;
};