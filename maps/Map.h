#include <vector>

using std::vector;

template <typename K, typename V>
class Map {
	public:
		struct entry {
			K key;
			V value;
		};
		typedef typename vector<entry>::iterator iterator;
	public:
		Map() : data(new vector<entry>) {}
		~Map() { delete data; }
	
		int size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		
		iterator begin() const { return data->begin(); }
		iterator end() const { return data->end(); }
		
		iterator find(const K& k) const {
			for (iterator i = begin(); i != end(); ++i) {
				if (i->key == k) {
					return i;
				}
			}
			return end();
		}
		
		iterator put(const K& k, const V& v) {
			for (iterator i = begin(); i != end(); ++i) {
				if (i->key == k) {
					i->value = v;
					return i;
				}
			}
			entry e = {k, v};
			data->push_back(e);
			return end();
		}
		
		void erase(const K& k) throw() { 
			if (find() == end()) throw("Out of Bounds");
			data->erase(find(k)); 
		}
	private:
		vector<entry>* data;
};