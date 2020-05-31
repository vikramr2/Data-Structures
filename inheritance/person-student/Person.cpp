#include "Person.h"

Person::Person(const string& nm, const string& id) : name(nm), idNum(id) {}

void Person::print() {
	cout << "Name :  " << name << endl;
	cout << "ID   :  " << idNum << endl;
}

string Person::getName() {
	return name;
}

Person::~Person() {
}