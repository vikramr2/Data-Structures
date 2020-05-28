#include "Flower.h"

Flower::Flower(string n, int p, float r) {
	name = n;
	petals = p;
	price = r;
}

string Flower::getName() {
	return name;
}

int Flower::getPetals() {
	return petals;
}

float Flower::getPrice() {
	return price;
}

void Flower::setName(string n) {
	name = n;
}

void Flower::setPetals(int p) {
	petals = p;
}

void Flower::setPrice(float r) {
	price = r;
}