#include <stack>
#include <vector>
#include <iostream>

using std::vector;
using std::stack;
using std::cout;
using std::endl;

template<typename T>
void reverse(vector<T>& V) {
	stack<T> S;
	for (int i = 0; i < V.size(); i++) {
		S.push(V[i]);
	}
	for (int i = 0; i < V.size(); i++) {
		V[i] = S.top();
		S.pop();
	}
}

template<typename T>
void print(vector<T> V) {
	cout << '[' << V[0];
	for (int i = 1; i < V.size(); i++) {
		cout << ", " << V[i];
	}
	cout << ']' << endl;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	print(v);
	reverse(v);
	print(v);
}