#include <string>
#include "Tree.h"

using std::string;

/*A trie is a character tree that stores strings in a similar manner to a Webster's dictionary
	- each char index of a word is a level on the tree*/
class Trie {
	//redefining tree elements
	public:
		typedef typename Tree<char>::node node;
	public:
		//the tree will be rooted with an empty character
		Trie() : data(new Tree<char>) { data->addRoot(' '); }
		~Trie() { delete data; }
		
		//recurse downward with adding each character
		void add(string s) { addHelper(data->root(), s); }
		
		/*printing will just show a preorder traversal: 
		  itll properly illustrate the functionality of this Data Structure*/
		void print() { data->preorder(); }
	private:
		Tree<char>* data;
		
		//recursive adding
		void addHelper(node* n, string s) {
			//Base case: if the string is empty, theres nothing to add
			if (s.empty()) return;
			
			//add the first character
			data->addChild(n, s[0]);
			
			//find that character's node and recurse there with a substring
			for (typename list<node*>::iterator i = n->children.begin(); i != n->children.end(); ++i) {
				if ((*i)->elem == s[0]) {
					addHelper(*i, s.substr(1, s.length()-1));
					return;
				}
			}
		}
};