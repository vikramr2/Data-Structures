#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

//An AVL Tree is essentially a BST that can rebalance itself using rotation of nodes in its subtree
template <typename T>
class AVL {
	public:
		struct node {
			T data;
			node* left;
			node* right;
			node* parent;
			
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
		AVL() : root(NULL) {}
		
		//same implementation as BST
		node* find(T e) { return findHelper(e, root); }
		void inorder() {
			inorderHelper(root);
			cout << endl;
		}
		
		//get the value of the root
		T getRoot() { return root->data; }
		
		//insertion is slightly different
		void insert(T e) {
			//same as BST, except with a NULL parent value added
			node* n = new node{e, NULL, NULL, NULL};
			if (!root) {
				root = n;
				return;
			}
			insertHelper(n, root);
			
			//but now we require rebalancing of the tree
			rebalance(n);
		}
		
		//similarly, removal is the same except now we need to rebalance
		node* remove(T e) {
			node* r = removeHelper(e, root);
			rebalance(r);
			return r;
		}
		
		//height will just recurse from root and count levels
		int height() { return height(root); }
	private:
		node* root;
		
		
		/**BASIC HELPERS*/
		node* findHelper(T e, node* n) {
			if (!n) return NULL;
			if (n->data == e) return n;
			if (e < n->data) return findHelper(e, n->left);
			if (e > n->data) return findHelper(e, n->right);
		}
		void inorderHelper(node* n) {
			if (!n) return;
			inorderHelper(n->left);
			cout << n->data << ' ';
			inorderHelper(n->right);
		}
		
		/**INSERTION/REMOVAL HELPERS*/
		void insertHelper(node* e, node* n) {
			if (*(*e) < *(*n)) {
				if (!(n->left)) {
					n->left = e;
					
					//same idea, now we just set parents
					e->parent = n;
				}
				else {
					insertHelper(e, n->left);
				}
			} else {
				if (!(n->right)) {
					n->right = e;
					e->parent = n;
				}
				else {
					insertHelper(e, n->right);
				}
			}
		}
		node* removeHelper(T e, node* n) {
			if (!n) return NULL;
			if (e < *(*n)) {
				n->left = removeHelper(e, n->left);
				
				//again set parents
				n->left->parent = n;
			}
			else if (e > *(*n)) {
				n->right = removeHelper(e, n->right);
				if (n->right) {
					n->right->parent = n;
				}
			}
			else {
				if (!(n->left)) {
					node* t = n->right;
					delete n;
					return t;
				} else if (!(n->right)) {
					node* t = n->left;
					delete n;
					return t;
				}
				node* t = ++n;
				n->data = t->data;
				n->right = removeHelper(t->data, n->right);
				n->right->parent = n;
			}
			return n;
		}
		
		/**REBALANCE HELPERS*/
		int height(node* n) {
			if (!n) return 0;
			return 1 + max(height(n->left), height(n->right));
		}
		
		/*Def BALANCE: height or right child minus left child.
			- AVL is imbalanced if the magnitude of the balance is greater than 1.
			- Left heavy: balance > 1
			- Right heavy: balance < -1*/
		int bal(node* n) { return height(n->left)-height(n->right); }
		
		//right rotation of subtree rooted at node n
		node* right(node* n) {
			/*Reconnect nodes accordingly.
			  To get the specifics of how this works, Google Images "AVL Rotation"*/
			node* x = n->left;
			node* t = x->right;
			n->left = t;
			if (t) {
				t->parent = n;
			}
			x->right = n;
			n->parent = x;
			return x;
		}
		
		//left rotation of subtree rooted at node n
		node* left(node* n) {
			node* x = n->right;
			node* t = x->left;
			n->right = t;
			t->parent = n;
			x->left = n;
			n->parent = x;
			return x;
		}
		
		//Rebalance subtree rooted at node n
		void rebalance(node* n) {
			//do we even need to rebalance?
			int balance = bal(n);
			
			//left cases
			if (balance > 1) {
				//record n's old parent before resetting n
				node* par = n->parent;
				
				//check whether n is a left or right child of its parent
				bool l;
				if (n->parent->left == n) l = true;
				else l = false;
				
				balance = bal(n->left);
				
				//Left, left case
				if (balance > 0) {
					//right rotate at n
					n = right(n);
					
					//reset parent, and based on our earlier bool, reset n's parent's child
					n->parent = par;
					if (l) n->parent->left = n;
					else n->parent->right = n;
				}
				
				//Left, right case
				if (balance < 0) {
					//left rotate left child, and reset parent
					n->left = left(n->left);
					n->left->parent = n;
					
					//same procedure for n
					n = right(n);
					n->parent = par;
					if (l) n->parent->left = n;
					else n->parent->right = n;
				}
			
			//right cases
			} else if (balance < -1) {
				node* par = n->parent;
				bool l;
				if (n->parent->left == n) l = true;
				else l = false;
				balance = bal(n->right);
				
				//essentially the left procedures, but flipped
				
				//Right, right
				if (balance < 0) {
					n = left(n);
					n->parent = par;
					if (l) n->parent->left = n;
					else n->parent->right = n;
				}
				
				//Right, left
				if (balance > 0) {
					n->right = right(n->right);
					n->right->parent = n;
					n = right(n);
					n->parent = par;
					if (l) n->parent->left = n;
					else n->parent->right = n;
				}
			}
			
			/*if the node doesn't have a parent, it either was or is the root:
				- Reset the root
				- Terminate*/
			if (!(n->parent)) {
				root = n;
				return;
			
			//otherwise recurse upward
			} else {
				rebalance(n->parent);
			}
		}
};