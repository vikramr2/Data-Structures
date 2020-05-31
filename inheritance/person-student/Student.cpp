#include "Student.h"

Student::Student(const string& nm, const string& id, const string& maj, int yr) 
	: Person(nm, id), major(maj), year(yr) {}

void Student::print() {
	Person::print();
	cout << "Major : " << major << endl;
	cout << "Year  : " << year << endl;
}

void Student::changeMajor(const string& newMajor) {
	major = newMajor;
}

void Student::printID() {
	cout << idNum << endl; //since idNum is protected, this child class has access
	//cout << Name << endl; //ERROR: This is private
}