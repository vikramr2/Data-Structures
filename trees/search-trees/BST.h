#include <iostream>

using std::cout;
using std::endl;

/*Binary Search Tree
	- All less than current node is in the left subtree
	- All Greater than or equal to current node is in the right subtree*/
template <typename T>
class BST {
	public:
		//node to store data
		struct node {
			T data;
			
			node* left;
			node* right;
			
			T operator*() { return data; }
			
			//this operator is to get an inorder successor
			node* operator++() {
				//move right
				node* curr = right;
				
				//and move as far left as possible
				while (curr && curr->left) {
					curr = curr->left;
				}
				
				return curr;
			}
		};
	public:
		BST() : root(NULL) {}
		
		//recursively destroy from root
		~BST() { destroy(root); }
		
		//navigate to appropriate leaf and insert
		void insert(T e) {
			//create node
			node* n = new node;
			n->data = e;
			n->left = NULL;
			n->right = NULL;
			
			//if this is the first insertion, set root
			if (!root) {
				root = n;
				return;
			}
			
			//otherwise, recurse to correct leaf and insert
			insertHelper(n, root);
		}
		
		//both find and remove recurse from root
		node* find(T e) { return findHelper(e, root); }
		node* remove(T e) { return removeHelper(e, root); }
		
		//print left, root, right: this should print elements in sorted order
		void inorder() {
			inorderHelper(root);
			cout << endl;
		}
		
		/*careful, if there will be any dangling nodes, call destructor first.
		  this is meant for AVL insertions*/
		void resetRoot(node* n) { root = n; }
		
		node* getRoot() { return root; }
		
		int height() { return height(root); }
	protected:
		node* root;
		
		//helpers:
		/** recursive insertion helper
		* @param e: node to insert
		* @param n: current node being inspected*/
		void insertHelper(node* e, node* n) {
			//if the node to insert has a lower value than the current node, focus on left subtree
			if (*(*e) < *(*n)) {
				/*if no left child exists, set it
				  otherwise recurse left*/
				if (!(n->left)) {
					n->left = e;
				}
				else {
					insertHelper(e, n->left);
				}
			//otherwise focus on right subtree, follow the same procedure
			} else {
				if (!(n->right)) {
					n->right = e;
				}
				else {
					insertHelper(e, n->right);
				}
			}
		}
		
		/** recursive find helper
		* @param e: element to search for
		* @param n: current node being inspected*/
		node* findHelper(T e, node* n) {
			//if the current node is null, we return no match
			if (!n) return NULL;
			
			//if the current node's data is the desired value, return this node
			else if (n->data == e) return n;
			
			//otherwise, recurse in the appropriate subtree
			else if (n->data > e) findHelper(e, n->left);
			else findHelper(e, n->right);
		}
		
		/** recursive remove helper
		* @param e: element to remove
		* @param n: current node being inspected*/
		node* removeHelper(T e, node* n) {
			if (!n) return NULL;
			
			//recurse in correct direction
			if (e < *(*n)) n->left = removeHelper(e, n->left);
			else if (e > *(*n)) n->right = removeHelper(e, n->right);
			
			//if we're exactly where we want to remove
			else {
				//check leaves and act accordingly
				
				//if only one leaf exists, move it up
				if (!(n->left)) {
					node* t = n->right;
					delete n;
					return t;
				} else if (!(n->right)) {
					node* t = n->left;
					delete n;
					return t;
				}
				
				//if no leaves exist, move inorder successor up
				node* t = ++n;
				n->data = t->data;
				n->right = removeHelper(t->data, n->right);
			}
			return n;
		}
		
		/** recursive inorder helper
		* @param n: current node being inspected*/
		void inorderHelper(node* n) {
			//if current node is null, exit
			if (!n) return;
			
			//recurse left, print current, recurse right
			inorderHelper(n->left);
			cout << *(*n) << ' ';
			inorderHelper(n->right);
		}
		
		//recursive destroy helper
		void destroy(node* n) {
			if (!n) return;
			
			//destroy subtrees, then delete current node
			destroy(n->left);
			destroy(n->right);
			delete n;
		}
		
		//height recursive function
		int height(node* n) {
			if (!n) return 0;
			return 1 + max(height(n->left), height(n->right));
		}
};