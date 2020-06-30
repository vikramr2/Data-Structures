#include <iostream>
#include <algorithm>

using std::swap;
using std::cout;
using std::endl;

/*This is a red black tree: Each node is red or black. The rules are as follows
	- No 2 red nodes can be adjacent
	- Each path from the root to a leaf should traverse the same number of black nodes*/
template <typename T>
class RB {
	public:
		//Colors to assign the nodes. RED=0, BLACK=1.
		enum Color {RED, BLACK};
		struct Node {
			T data;
			Node* left;
			Node* right;
			Node* parent;
			Color color;
		
			T operator*() { return data; }
		
			//this operator is to get an inorder successor
			Node* operator++() {
				//move right
				Node* curr = right;
				
				//and move as far left as possible
				while (curr && curr->left) {
					curr = curr->left;
				}
				
				return curr;
			}
			
			//By default, we construct nodes to be red. But recoloring makes them black if need be.
			Node(T e) {
				data = e;
				left = NULL;
				right = NULL;
				parent = NULL;
				color = RED;
			}
		};
	public:
		RB() : root(NULL) {}
		
		void insert(T e) {
			Node* n = new Node(e);
			if (!root) {
				root = n;
				return;
			}
			insertHelper(n, root);
			
			//recursively fix any red red violation fron inserted node
			fixViolation(n);
		}
		
		Node* find(T e) { return findHelper(e, root); }
		
		void inorder() {
			inorderHelper(root);
			cout << endl;
		}
		
		void preorder() {
			preorderHelper(root);
			cout << endl;
		}
		
		//This was solely for testing black uncle
		/*void testSetup(T e) {
			find(e)->color = RED;
			fixViolation(find(e)->right);
		}*/
	private:
		Node* root;
	
		Node* findHelper(T e, Node* n) {
			if (!n) return NULL;
			if (n->data == e) return n;
			if (e < n->data) return findHelper(e, n->left);
			if (e > n->data) return findHelper(e, n->right);
		}
	
		//Print both the key and the color <key, 0/1>
		void inorderHelper(Node* n) {
			if (!n) return;
			inorderHelper(n->left);
			cout << '<' << n->data << ", " << n->color << "> ";
			inorderHelper(n->right);
		}
		
		//Print root, left, right
		void preorderHelper(Node* n) {
			if (!n) return;
			cout << '<' << n->data << ", " << n->color << "> ";
			inorderHelper(n->left);
			inorderHelper(n->right);
		}
			
		void insertHelper(Node* e, Node* n) { 
			if (e->data < n->data) {
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
		
		//Works the same way as Left, Right AVL Rotation
		void rotateLeft(Node *&root, Node *&pt) 
		{ 
			Node *pt_right = pt->right; 
		  
			pt->right = pt_right->left; 
		  
			if (pt->right != NULL) 
				pt->right->parent = pt; 
		  
			pt_right->parent = pt->parent; 
		  
			if (pt->parent == NULL) 
				root = pt_right; 
		  
			else if (pt == pt->parent->left) 
				pt->parent->left = pt_right; 
		  
			else
				pt->parent->right = pt_right; 
		  
			pt_right->left = pt; 
			pt->parent = pt_right; 
		} 
		  
		void rotateRight(Node *&root, Node *&pt) 
		{ 
			Node *pt_left = pt->left; 
		  
			pt->left = pt_left->right; 
		  
			if (pt->left != NULL) 
				pt->left->parent = pt; 
		  
			pt_left->parent = pt->parent; 
		  
			if (pt->parent == NULL) 
				root = pt_left; 
		  
			else if (pt == pt->parent->left) 
				pt->parent->left = pt_left; 
		  
			else
				pt->parent->right = pt_left; 
		  
			pt_left->right = pt; 
			pt->parent = pt_left; 
		} 
		
		// This function fixes violations caused by BST insertion 
		void fixViolation(Node *&n) 
		{ 
			//make sure root is always black
			root->color = BLACK;
			
			if (n == root) return;
			
			//in these cases, the node can be left alone
			if (n->color == BLACK || n->parent == root) return;
			
			//if the parent is black then you can leave the node red
			Node* p = n->parent;
			if (p->color == BLACK) return;
			
			//get uncle
			Node* g = p->parent;
			Node* uncle = (g->left == p) ? g->right : g->left;
			
			/*NOTE: This is open for suggestion, 2 if statements here have the same body
				- !uncle and uncle->color==BLACK
				- This was to prevent segfaults with a nonexistent uncle*/
			
			//if the uncle doesnt exist, rotate and swap colors
			if (!uncle) {
				/*if you are parent's left child 
				  if parent is grandparent's left child respectively*/
				bool p_l = (p->left == n);
				bool g_l = (g->left == p);
				
				/*If subtree is structured:
					N
					 \
					  N
					   \
					    N*/
				if (!p_l && !g_l) {
					rotateLeft(root, g);
					swap(p->color, g->color);
					return;
				}
				
				/*N
				   \
				    N
				   /
				  N*/
				if (p_l && !g_l) {
					rotateRight(root, p);
					rotateLeft(root, g);
					swap(n->color, g->color);
					return;
				}
				/*  N 
				   /
				  N
				 /
				N*/
				if (p_l && g_l) {
					rotateRight(root, g);
					swap(p->color, g->color);
					return;
				}
				
				/*N
				 /
			    N
				 \
				  N*/
				if (!p_l && g_l) {
					rotateLeft(root, p);
					rotateRight(root, g);
					swap(n->color, g->color);
					return;
				}
			}
			
			//if uncle is red: no rotations!
			if (uncle->color == RED) {
				p->color = BLACK;
				uncle->color = BLACK;
				g->color = RED;
				fixViolation(g);
				return;
			}
			
			//if uncle is black: rotations exist
			if (uncle->color == BLACK) {
				bool p_l = (p->left == n);
				bool g_l = (g->left == p);
				
				if (!p_l && !g_l) {
					rotateLeft(root, g);
					swap(p->color, g->color);
					return;
				}
				
				if (p_l && !g_l) {
					rotateRight(root, p);
					rotateLeft(root, g);
					swap(n->color, g->color);
					return;
				}
				
				if (p_l && g_l) {
					rotateRight(root, g);
					swap(p->color, g->color);
					return;
				}
				
				if (!p_l && g_l) {
					rotateLeft(root, p);
					rotateRight(root, g);
					swap(n->color, g->color);
					return;
				}
			}
		} 
};