#include <iostream>

using std::cout;
using std::endl;

/*Let n = the degree of the BTree.
  Each node in a BTree has n-1 keys and n children.
  All leaves have the same depth.*/
template <typename T>
class BTree {
	public:
		struct node {
			//values and nodes are arrays, limited to the degree
			node** children;
			T* vals;
			
			//number of current elements
			int num_vals;
			
			//degree of node
			int deg;
			
			//whether the node has no children
			bool leaf;
			
			//constructor initializes arrays, sets the leaf and degree
			node(int degree, bool l) {
				children = new node*[degree];
				vals = new T[degree - 1];
				num_vals = 0;
				leaf = l;
				deg = degree;
			}
			
			//deletes the values and children
			~node() {
				delete[] vals;
				delete[] children;
			}
			
			//adds to a node that isn't full
			void simpleAdd(T e) {
				int i = num_vals-1;
				//if the node is a leaf, then set the appropriate entry to this value
				if (leaf) {
					while (i >= 0 && vals[i] > e) {
						vals[i+1] = vals[i];
						i--;
					}
					
					vals[i+1] = e;
					num_vals++;
				//otherwise, navigate to the correct node
				} else {
					while (i >= 0 && vals[i] > e) i--;
					if (children[i+1]->num_vals == deg-1) {
						split(i+1, children[i+1]);
						if (vals[i+1] < e) i++;
					}
					children[i+1]->simpleAdd(e);
				}
			}
			
			//splits the node into 3 at index i
			void split(int i, node* n) {
				//initializes new node and fill left
				node* m = new node(deg, n->leaf);
				m->num_vals = deg/2-1;
				for (int j = 0; j < deg/2-1; j++) {
					m->vals[j] = n->vals[j+deg/2];
				}
				
				//if n isnt a leaf, then move n's right down
				if (!(n->leaf)) {
					for (int j = 0; j < deg/2; j++) {
						m->children[j] = n->children[j+deg/2];
					}
				}
				
				//move children
				n->num_vals = deg/2 -1;
				for (int j = num_vals; j >= i+1; j--) children[j+1] = children[j];
				children[i+1] = m;
				
				//move values
				for (int j = num_vals-1; j >= i; j--) vals[j+1] = vals[j];
				vals[i] = n->vals[deg/2-1];
				num_vals++;
			}
		};
	public:
		BTree(int d) : degree(d), root(NULL) {}
		~BTree() { destroy(root); }
		
		void add(T e) {
			//if root is null, set it
			if (!root) {
				root = new node(degree, true);
				root->vals[0] = e;
				root->num_vals = 1;
			} else {
				//if node is full, split and perform a simple case add
				if (root->num_vals == degree - 1) {
					node* n = new node(degree, true);
					
					//split
					n->children[0] = root;
					n->split(0, root);
					int i = 0;
					if (n->vals[0] < e) i++;
					
					//perform simple add
					n->children[i]->simpleAdd(e);
					root = n;
					
				//otherwise, perform a simple case add
				} else {
					root->simpleAdd(e);
				}
			}
		}
		
		node* find(T e) { return findHelper(e, root); }
	private:
		node* root;
		int degree;
		
		//recursive find
		node* findHelper(T e, node* n) {
			//search for appropriate key
			int i = 0;
			while (i < n->num_vals && e > n->vals[i]) i++;
			
			//if key is this one, return this node
			if (n->vals[i] == e) return n;
			
			//if this node is a leaf, then key doesn't exist
			if (n->leaf) return NULL;
			
			//recurse into appropriate node
			return findHelper(e, n->children[i]);
		}
		
		//recursive destructor helper
		void destroy(node* n) {
			if (!n) return;
			
			//delete all children, then current node
			for (int i = 0; i < n->num_vals; i++) {
				delete n->children[i];
			}
			delete n;
		}
};