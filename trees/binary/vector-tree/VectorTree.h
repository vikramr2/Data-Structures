#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

//binary tree implemented from a vector
template <typename T>
class VectorTree {
	public:
		//default constructor
		VectorTree() : data(new vector<T>(1, T())) {}
		
		//recursively destruct at root
		~VectorTree() { delete data; }
		
		//number of nodes is simply the length of the vector
		int size() const { return data->size()-1; }
		
		bool empty() const { return (size()==1); }
		
		/*We define the root as index 1.
		  Index 0 wouldn't work as left child would be inaccessible
			i.e. 0*2=0*/
		T root() const { 
			if (empty()) return NULL;
			return (*data)[1]; 
		}
		
		//adds leaf to tree: just add to the vector
		void addLeaf(T c) {
			data->push_back(c);
		}
		
		//root, left, right
		void preorder() { if (!empty()) preorderHelper(1, 0); }
		
		//left, root, right
		void inorder() { if (!empty()) inorderHelper(1, 0); }
		
		//left, right, root
		void postorder() { if (!empty()) postorderHelper(1, 0); }
		
		//height from root (index 1)
		int height() { if (!empty()) return height(1); }
	private:
		vector<T>* data;
	
		//recursive traversal helpers
		void preorderHelper(int n, int level) {
			//if you're at null, then you stop
			if (n >= size()) return;
			
			//just for depiction: indent based on current level
			for (int i = 0; i < level; i++) {
				cout << '\t';
			}
			
			//print current node
			cout << (*data)[n] << endl;
			
			/*NOTE: each element in the vector is a node
					the element at index*2 is the left child
					the element at index*2+1 is the right child */
					
			preorderHelper(n*2, level+1); //left
			preorderHelper(n*2+1, level+1); //right
		}
		void inorderHelper(int n, int level) {
			if (n >= size()) return;
			for (int i = 0; i < level; i++) {
				cout << '\t';
			}
			preorderHelper(n*2, level+1);
			cout << (*data)[n] << endl;
			preorderHelper(n*2+1, level+1);
		}
		void postorderHelper(int n, int level) {
			if (n >= size()) return;
			for (int i = 0; i < level; i++) {
				cout << '\t';
			}
			preorderHelper(n*2, level+1);
			preorderHelper(n*2+1, level+1);
			cout << (*data)[n] << endl;
		}
		
		//height of tree in levels passed by index
		int height(int n) {
			if (n >= size()) return 0;
			return 1 + max(height(n*2), height(n*2+1));
		}
};