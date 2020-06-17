#include <iostream>

using std::cout;
using std::endl;
using std::max;

template <typename T>
class BinaryTree {
	protected:
		//single node in tree
		struct node {
			T elem;
			node* left;
			node* right;
			/*NOTE: can doubly link by saying
			    node* parent;
			  but I'm lazy haha so here's a singly linked binary tree*/
			  
			//operator to get node value
			T& operator*() { return elem; }
		};
	public:
		//default constructor
		BinaryTree() : _root(NULL), n(0) {}
		
		//recursively destruct at root
		~BinaryTree() { destructorHelper(_root); }
		
		int size() const { return n; }
		bool empty() const { return (n==0); }
		node* root() const { return _root; }
		
		//adds root to empty tree
		void addRoot(T e) {
			if (!empty()) return;
			_root = new node{e, NULL, NULL};
			n = 1;
		}
		
		//expands left to have two children. For one, specify left or right as NULL.
		void expandExternal(node* x, T l, T r) {
			if (!x) return;
			if (x->left || x->right) return;
			x->left = new node{l, NULL, NULL};
			x->right = new node{r, NULL, NULL};
			n += 2;
		}
		
		//root, left, right
		void preorder() { if (_root) preorderHelper(_root); }
		
		//left, root, right
		void inorder() { if (_root) inorderHelper(_root); }
		
		//left, right, root
		void postorder() { if (_root) postorderHelper(_root); }
		
		int height() { if (_root) return heightHelper(_root); }
	private:
		//recursive traversal helpers
		void preorderHelper(node* v) {
			//if you're at null, then you stop
			if (!v) return;
			
			cout << *(*v) << ' ';
			preorderHelper(v->left);
			preorderHelper(v->right);
		}
		void inorderHelper(node* v) {
			if (!v) return;
			inorderHelper(v->left);
			cout << *(*v) << ' ';
			inorderHelper(v->right);
		}
		void postorderHelper(node* v) {
			if (!v) return;
			postorderHelper(v->left);
			postorderHelper(v->right);
			cout << *(*v) << ' ';
		}
		
		//height recursive function
		int heightHelper(node* v) {
			if (!v) return 0;
			return 1 + max(heightHelper(v->left), heightHelper(v->right));
		}
		
		//destroy left and right, then current
		void destructorHelper(node* v) {
			if (v) {
				destructorHelper(v->left);
				destructorHelper(v->right);
				delete v;
			}
		}
		
		node* _root;
		
		//number of nodes in tree
		int n;
};