#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

int main() {
	Person person("Mary", "12-345");
	Student student("Bob", "98-764", "Bio", 2020);
	
	cout << student.getName() << endl;
	person.print();
	student.print();
	//person.changeMajor("Chem"); ERROR, not a student
	student.changeMajor("Music");
	student.print();
	student.printID();
	
	//Constructs in order Person then student
	Person* p = new Student("Vik", "69-420", "Math & CS", 2023); // Static/Dynamic Binding
	
	p->print(); //Calls Person::print() but with virtual, calls Student::print
	
	//p->changeMajor("Psych"); //ERROR: Declared type isnt Student though
	Student* s = dynamic_cast<Student*>(p);
	s->changeMajor("Psych"); //Now this works since we used Dynamic Casting
	s->print();
	
	
	//NOTE: Without virtual, will destruct Student, then Student
	delete p; //Virtual Destructor: removes extra allocated memory in child class
}