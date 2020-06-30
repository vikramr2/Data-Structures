#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

/*
This is a tree that isnt limited to having any number of nodes per parent.
i.e. its not an n-ary tree, but an "infinite-ary" tree if you will.
*/
template <typename T>
class Tree {
	public:
		//single node in tree
		struct node {
			T elem;
			node* parent;
			list<node*> children;
			  
			//operator to get node value
			T& operator*() { return elem; }
		};
	public:
		//default constructor
		Tree() : _root(NULL), n(0) {}
		
		//destructor uses recursive call for remove from root
		~Tree() { remove(_root); }
		
		int size() const { return n; }
		bool empty() const { return (n == 0); }
		node* root() const { return _root; }
		
		//adds root to empty tree
		void addRoot(T e) {
			if (!empty()) return;
			list<node*> l;
			_root = new node{e, NULL, l};
			n = 1;
		}
		
		//adds child of given node
		void addChild(node* n, T e) {
			for (typename list<node*>::iterator it = n->children.begin(); it != n->children.end(); ++it) {
				if ((*it)->elem == e) { return; }
			}
			list<node*> l;
			node* c = new node{e, n, l};
			n->children.push_back(c);
		}
		
		//deletes given node and its subtree
		void remove(node* n) {
			if (n) {
				for (typename list<node*>::iterator i = n->children.begin(); i != n->children.end(); ++i) {
					remove(*i);
				}
				delete n;
			}
		}
		
		//root, left->right
		void preorder() { preorderHelper(_root, 0); }
		
		//recurse from root
		int height() { return height(_root); }
	private:
		node* _root;
		int n;
		
		//recursive helper for preorder
		void preorderHelper(node* v, int level) {
			if (!v) return;
			for (int i = 0; i < level; i++) {
				cout << '\t';
			}
			cout << *(*v) << endl;
			for (typename list<node*>::iterator i = v->children.begin(); i != v->children.end(); ++i) {
				preorderHelper(*i, level + 1);
			}
		}
		
		//recursive height algo
		int height(node* v) {
			if (!v) return 0;
			
			//get 1 + max height of subtrees
			int max = 1;
			for (typename list<node*>::iterator i = v->children.begin(); i != v->children.end(); ++i) {
				if (1 + height(*i) > max) {
					max = 1 + height(*i);
				}
			}
			return max;
		}
};