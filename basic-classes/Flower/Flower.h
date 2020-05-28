#include <string>

using namespace std;

class Flower {
	public:
		//Constructor
		Flower(string n, int p, float r);
		
		//getters
		string getName();
		int getPetals();
		float getPrice();
		
		//setters
		void setName(string n);
		void setPetals(int p);
		void setPrice(float r);
		
	private:
		//members
		string name;
		int petals;
		float price;
};