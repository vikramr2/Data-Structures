#include <string>
#include <iostream>

#include "Person.h"

using namespace std;

class Student : public Person {
	private:
		string major;
		int year;
	public:
		Student(const string& nm, const string& id, const string& maj, int yr);
		virtual void print();
		void changeMajor(const string& newMajor);
		void printID();
};