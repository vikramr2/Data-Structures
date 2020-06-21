#include <list>
#include <vector>
#include "Map.h"

template <typename K, typename V, typename H>
class HashMap {
	public:
		//we'll just redefine Map's Entry struct as our entry here
		typedef typename Map<const K, V>::entry Entry;
		class Iterator;
	public:
		//Hash Maps have a max capacity for their  bucket array
		HashMap(int capacity = 100) : n(0), B(capacity) {}

		int size() const { return n; }
		bool empty() const { return n==0; }
		
		//iterate to element in key in unhashed index
		Iterator find(const K& k) {
			Iterator p = finder(k);
			if (endOfBkt(p)) return end();
			else return p;
		}
		
		/*Put rules:
			- if the key exists, replace its value
			- if the key has the same hash as another existing key, just add it to the bucket
				- this is called "separate chaining"*/
		Iterator put(const K& k, const V& v) {
			Iterator p = finder(k);
			Entry e = {k, v};
			if (endOfBkt(p)) return inserter(p, e);
			else {
				p.ent->value = v;
				return p;
			}
		}
		
		//find corresponding iterator to key and use helper
		void erase(const K& k) {
			Iterator p = finder(k);
			if (endOfBkt(p)) throw("Nonexistent Elem");
			eraser(p);
		}
		void erase(const Iterator& p) { eraser(p); }
		
		//Construct an iterator containing the first entry of the first element of the bucket list 
		Iterator begin() {
			if (empty()) return end();
			BItor bkt = B.begin();
			while (bkt->empty()) ++bkt;
			return Iterator(B, bkt, bkt->begin());
		}
		
		//conversely, the last entry of the last element of the bucket list
		Iterator end() { return Iterator(B, B.end()); }
	protected:
		//defining hash map components
		typedef std::list<Entry> Bucket;
		typedef std::vector<Bucket> BktArray;
		
		//hashmap utilities
		
		//find helper
		Iterator finder(const K& k) {
			//get index of this key
			int i = hash(k) % B.size(); 
			
			//iterate to this index
			BItor bkt = B.begin() + i;
			Iterator p(B, bkt, bkt->begin());
			while (!endOfBkt(p) && (*p).key != k) {
				nextEntry(p);
			}
			return p;
		}
		
		//insert/erase entry in appropriate bucket
		Iterator inserter(const Iterator& p, const Entry& e) {
			EItor ins = p.bkt->insert(p.ent, e);
			n++;
			return Iterator(B, p.bkt, ins);
		}
		void eraser(const Iterator& p) {
			p.bkt->erase(p.ent);
			n--;
		}
		
		//defining bucket and bucketlist iterators
		typedef typename BktArray::iterator BItor;
		typedef typename Bucket::iterator EItor;
		
		//iterator helper methods
		static void nextEntry(Iterator& p) { ++p.ent; }
		static bool endOfBkt(const Iterator& p) { return p.ent == p.bkt->end(); }
	private:
		int n;
		H hash;
		BktArray B;
	public:
		class Iterator {
			private:
				//location described by (bucketlist pos, bucket pos)
				EItor ent; //1
				BItor bkt; //2
				const BktArray* ba;
			public:
				Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
					: ent(q), bkt(b), ba(&a) { }
					
				Entry& operator*() const { return *ent; }
				bool operator==(const Iterator& p) const {
					if (ba != p.ba || bkt != p.bkt) return false; //not in same bucket
					else if (bkt == ba->end()) return true; //if at end
					else return (ent == p.ent); //if entries are the same
				}
				Iterator& operator++() {
					//increment entry
					++ent;
					
					//if at the end of the bucket, move to nect bucket in bucket array
					if (endOfBkt(*this)) {
						++bkt;
						while (bkt != ba->end() && bkt->empty()) {
							++bkt;
						}
						if (bkt == ba->end()) return *this;
						ent = bkt->begin();
					}
					return *this;
				}
				friend class HashMap;
		};
};