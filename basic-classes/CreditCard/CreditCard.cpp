#include "CreditCard.h" // provides CreditCard

using namespace std; // make std:: accessible

// standard constructor
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal) { 
	number = no;
	name = nm;
	balance = bal;
	limit = lim;
} // make a charge

bool CreditCard::chargeIt(double price) { 
	if (price < 0) {
		cout << "Price must be positive" << endl;
		return false;
	}
	if (price + balance > double(limit)) {
		return false; // over limit
	}
	balance += price;
	return true; // the charge goes through
}

void CreditCard::makePayment(double payment, const Date& due, const Date& paydate) { // make a payment
	const double late = 10.0;
	const double interest = 0.1;
	if (payment < 0) {
		cout << "Payment must be positive" << endl;
	} else {
		balance -= payment * (1 + interest);
	}
	if (paydate.year > due.year) {
		balance -= late;
	} else if (paydate.month > due.month && paydate.year == due.year) {
		balance -= late;
	} else if (paydate.day > due.day && paydate.year == due.year && paydate.month == due.month) {
		balance -= late;
	}
} // print card information

ostream& operator<<(ostream& out, const CreditCard& c) { 
	out << "Number = " << c.getNumber() << "\n"
		<< "Name = " << c.getName() << "\n"
		<< "Balance = " << c.getBalance() << "\n"
		<< "Limit = " << c.getLimit() << "\n";
	return out;
}