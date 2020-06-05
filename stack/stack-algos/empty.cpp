#include <stack>
#include <iostream>

using std::stack;
using std::cout;
using std::endl;

template<typename T>
void empty(stack<T>& S) {
	if (S.empty()) {
		return;
	}
	S.pop();
	empty(S);
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.empty() << endl;
	empty(s);
	cout << s.empty() << endl;
}