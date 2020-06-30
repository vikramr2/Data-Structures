#include "Trie.h"
#include <string>

using std::string;

int main() {
	Trie t;
	t.add("bear");
	t.add("bull");
	t.add("bell");
	t.add("bid");
	t.add("buy");
	t.add("sell");
	t.add("stock");
	t.add("stop");
	t.print();
}