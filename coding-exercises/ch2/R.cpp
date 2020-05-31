#include <iostream>
#include <string>

using namespace std;

int numVowels(string s) {
	int ret = 0;
	string vowels = "aAeEiIoOuU";
	for (string::size_type i = 0; i < s.size(); i++) {
		for (string::size_type j = 0; j < vowels.size(); j++) {
			if (s[i] == vowels[j]) {
				ret++;
			}
		}
	}
	return ret;
}

void removePunctuation(string& s) {
	string punctuation = ";.!?:\",'";
	bool pass = true;
	string ret = "";
	for (string::size_type i = 0; i < s.size(); i++) {
		pass = true;
		for (string::size_type j = 0; j < punctuation.size(); j++) {
			if (s[i] == punctuation[j]) {
				pass = false;
			}
		}
		if (pass) {
			ret = ret + s[i];
		}
	}
	s = ret;
}

void arithIn() {
	cout << "Enter 3 Integers: ";
	int a, b, c;
	cin >> a >> b >> c;
	
	bool a1 = (a + b == c);
	bool a2 = (a + c == b);
	bool a3 = (b + c == a);
	
	bool s1 = (a - b == c);
	bool s2 = (b - a == c);
	bool s3 = (a - c == b);
	bool s4 = (c - a == b);
	bool s5 = (b - c == a);
	bool s6 = (c - b == a);
	
	bool m1 = (a * b == c);
	bool m2 = (a * c == b);
	bool m3 = (b * c == a);
	
	bool d1 = (double(a) / b == c);
	bool d2 = (double(b) / a == c);
	bool d3 = (double(a) / c == b);
	bool d4 = (double(c) / a == b);
	bool d5 = (double(b) / c == a);
	bool d6 = (double(c) / b == a);
	
	cout << endl;
	
	if (a1 || a2 || a3) {
		cout << "Additive Relationship!" << endl;
	}
	
	if (s1 || s2 || s3 || s4 || s5 || s6) {
		cout << "Subtractive Relationship!" << endl;
	}
	
	if (m1 || m2 || m3) {
		cout << "Multiplicative Relationship!" << endl;
	} 
	
	if (d1 || d2 || d3 || d4 || d5 || d6) {
		cout << "Divisive Relationship!" << endl;
	}
}

int main() {
	cout << numVowels("Vikram") << endl;
	cout << numVowels("Supercalifragilistic Expialidocious") << endl;
	string s = "Oh hi, Mark! How are you today? Y'know, I think you're \"swell\"";
	removePunctuation(s);
	cout << s << endl;
	arithIn();
}