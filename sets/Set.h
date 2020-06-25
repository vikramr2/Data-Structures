#include <vector>

using std::vector;

//a mergable set that can union, intersect and subtract
template <typename T>
class Set {
	public:
		int size() const { return data.size(); }
		bool empty() const { return data.empty(); }
		
		//find element in set through iterative approach
		int find(T e) {
			for (int i = 0; i < size(); i++) {
				if (data[i] == e) return i;
			}
			return -1;
		}
		
		//insert if element doesnt already exist
		void insert(T e) {
			if (find(e) != -1) return;
			data.push_back(e);
		}
		
		//erase element if it exists
		void erase(T e) {
			if (find(e) == -1) return;
			data.erase(data.begin()+find(e));
		}
		
		//get the elements in the set
		vector<T> getElems() { return data; }
		
		/*merge all elements with other set
			ex. {1, 2, 4}U{2, 4, 6}={1, 2, 4, 6}*/
		void Union(Set S) {
			for (int i = 0; i < S.size(); i++) {
				if (find(S.getElems()[i]) == -1) insert(S.getElems()[i]);
			}
		}
		
		/*intersect with other set
			ex. {1, 2, 4} intersect {2, 4, 6} = {2, 4}*/
		void Intersect(Set S) {
			for (int i = 0; i < size(); i++) {
				if (S.find(data[i]) == -1) erase(data[i]);
			}
		}
		
		/*subtract with other set
			ex. {1, 2, 3}\{2, 3} = {1}*/
		void Subtract(Set S) {
			for (int i = 0; i < S.size(); i++) {
				if (find(S.getElems()[i]) != -1) erase(S.getElems()[i]);
			}
		}
			
	private:
		vector<T> data;
};