#include <iostream>
#include "Flower.h"

using namespace std;

int main() {
	Flower f("Tulip", 4, 4.20f);
	cout << "Flower's Name: " << f.getName() << endl;
	cout << "Flower's Petals: " << f.getPetals() << endl;
	cout << "Flower's Price: " << f.getPrice() << endl;
	
	f.setName("Daffodil");
	f.setPetals(8);
	f.setPrice(5.20f);
	
	cout << "Flower's Name: " << f.getName() << endl;
	cout << "Flower's Petals: " << f.getPetals() << endl;
	cout << "Flower's Price: " << f.getPrice() << endl;
}