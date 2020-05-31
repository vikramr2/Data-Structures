#include <iostream>

using namespace std;

template<typename T, typename S>
class Pair {
	public:
		Pair(T a, S b) : one(a), two(b) {}
		T one;
		S two;
};

template<typename T, typename S>
ostream& operator<< (ostream &out, Pair<T, S> const& p)
{
  return out << "<" << p.one << ", " << p.two << ">";
}