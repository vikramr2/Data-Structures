#include <string>
#include <iostream>

using namespace std;

class Person {
	private:
		string name;
	protected:
		string idNum;
	public:
		Person(const string& nm, const string& id);
		virtual void print();
		string getName();
		virtual ~Person();
};