#include "Map.h"
#include <vector>

using std::vector;

/*A dictionary is like a map, except it stores multiple values per key
  We essentially implement it by using a map between keys and a vector of values*/
template <typename K, typename V>
class Dictionary {
	private:
		//redefining map types
		typedef typename Map<K, V>::entry entry;
		typedef typename Map<K, vector<V> >::iterator iterator;
	public:
		Dictionary() : data(new Map<K, vector<V> >), n(0) {}
		~Dictionary() { delete data; }
		
		int size() const { return n; }
		bool empty() const { return (n==0); }
		
		//finds first item in key's list of values
		entry find(const K& k) {
			//loop to find key
			for (iterator i = data->begin(); i != data->end(); ++i) {
				if (i->key == k) {
					//return an entry with the first value
					entry e = {k, i->value[0]};
					return e;
				}
			}
			
			//otherwise return a blank entry
			return entry();
		}
		
		//finds all items correlated to key
		vector<entry> findAll(const K& k) {
			//initialize empty value vector
			vector<V> values;
			bool found = false;
			for (iterator i = data->begin(); i != data->end(); ++i) {
				if (i->key == k) {
					//if key was found, set values, and mark a found value
					values = i->value;
					found = true;
					break;
				}
			}
			
			//if we still havent found a value corresponding to the key, return an empty vector
			if (!found) return vector<entry>();
			
			//build a vector of entries from a vector of values
			vector<entry> ret;
			for (int i = 0; i < values.size(); i++) {
				entry e = {k, values[i]};
				ret.push_back(e);
			}
			return ret;
		}
		
		//given a key, get all values corresponding
		vector<V> corresponding(const K& k) {
			//initialize empty value vector
			for (iterator i = data->begin(); i != data->end(); ++i) {
				if (i->key == k) {
					//if key was found, set values, and mark a found value
					return i->value;
				}
			}
			
			//if we still havent found a value corresponding to the key, return an empty vector
			return vector<V>();
		}
		
		//inserts a key value pair
		entry insert(const K& k, const V& v) {
			entry e = {k, v};
			
			//if empty, insert a first entry
			if (empty()) {
				vector<V> vs;
				vs.push_back(v);
				data->put(k, vs);
				n++;
				return e;
			}
			
			//if there doesn't exist this key, insert a new entry for this key
			if (!(find(k) != entry())) {
				vector<V> vs;
				vs.push_back(v);
				data->put(k, vs);
				n++;
				return e;
			}
			
			//if this key exists, add a value to its vector
			for (iterator i = data->begin(); i != data->end(); ++i) {
				if (i->key == k) {
					i->value.push_back(v);
					n++;
					return e;
				}
			}
		}
		
		
		//delete arbitrary entry with this key
		void erase(const K& k) {
			//if this key doesnt exist, exit
			if (find(k) == entry()) return;
			
			//otherwise, loop to this existing key
			for (iterator i = data->begin(); i != data->end(); ++i) {
				if (i->key == k) {
					//pop a value out of its vector
					i->value.pop_back();
				}
			}
			n--;
		}
	private:
		int n;
		Map<K, vector<V> >* data;
};