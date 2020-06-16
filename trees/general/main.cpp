#include <iostream>
#include <string>
#include "Tree.h"

using std::cout;
using std::endl;
using std::string;

/*
Let's implement the language tree in the image attached.
*/
int main() {
	//tree building from left to right, top to bottom
	Tree<string> t;
	t.addRoot("Proto-Indo-European");

	t.addChild(t.root(), "Balto-Slavic");
		t.addChild(t.root()->children.back(), "Baltic");
			t.addChild(t.root()->children.back()->children.back(), "Lithuanian");
			t.addChild(t.root()->children.back()->children.back(), "Latvian");
	
		t.addChild(t.root()->children.back(), "Slavic");
			t.addChild(t.root()->children.back()->children.back(), "West Slavic");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Polish");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Slovak");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Czech");
			t.addChild(t.root()->children.back()->children.back(), "South Slavic");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Bulgarian");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Macedonian");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Serbo-Croatian");
			t.addChild(t.root()->children.back()->children.back(), "East Slavic");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Ukranian");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Russian");
	
	t.addChild(t.root(), "Germanic");
		t.addChild(t.root()->children.back(), "North Germanic");
			t.addChild(t.root()->children.back()->children.back(), "Icelandic");
			t.addChild(t.root()->children.back()->children.back(), "Norwegian");
			t.addChild(t.root()->children.back()->children.back(), "Swedish");
			t.addChild(t.root()->children.back()->children.back(), "Danish");
		t.addChild(t.root()->children.back(), "West Germanic");
			t.addChild(t.root()->children.back()->children.back(), "English");
			t.addChild(t.root()->children.back()->children.back(), "Frisian");
			t.addChild(t.root()->children.back()->children.back(), "Dutch");
			t.addChild(t.root()->children.back()->children.back(), "Low/High German");
			t.addChild(t.root()->children.back()->children.back(), "Yiddish");
		t.addChild(t.root()->children.back(), "East Germanic");
			t.addChild(t.root()->children.back()->children.back(), "Gothic");
	
	t.addChild(t.root(), "Celtic");
		t.addChild(t.root()->children.back(), "Gaelic");
			t.addChild(t.root()->children.back()->children.back(), "Irish Gaelic");
			t.addChild(t.root()->children.back()->children.back(), "Scottish Gaelic");
		t.addChild(t.root()->children.back(), "Brythonic");
			t.addChild(t.root()->children.back()->children.back(), "Welsh");
			t.addChild(t.root()->children.back()->children.back(), "Breton");
	
	t.addChild(t.root(), "Italic");
		t.addChild(t.root()->children.back(), "Latin");
			t.addChild(t.root()->children.back()->children.back(), "Portuguese");
			t.addChild(t.root()->children.back()->children.back(), "Spanish");
			t.addChild(t.root()->children.back()->children.back(), "Catalan");
			t.addChild(t.root()->children.back()->children.back(), "French");
			t.addChild(t.root()->children.back()->children.back(), "Italian");
			t.addChild(t.root()->children.back()->children.back(), "Romanian");
	
	t.addChild(t.root(), "Hellenic");
		t.addChild(t.root()->children.back(), "Greek");
	
	t.addChild(t.root(), "Albanian");
	
	t.addChild(t.root(), "Anatolian");
		t.addChild(t.root()->children.back(), "Lycian");
		t.addChild(t.root()->children.back(), "Hittite");
		t.addChild(t.root()->children.back(), "Lydian");
	
	t.addChild(t.root(), "Armenian");
	
	t.addChild(t.root(), "Indo-Iranian");
		t.addChild(t.root()->children.back(), "Iranian");
			t.addChild(t.root()->children.back()->children.back(), "Persian");
			t.addChild(t.root()->children.back()->children.back(), "Pahlavi");
			t.addChild(t.root()->children.back()->children.back(), "Pashto");
			t.addChild(t.root()->children.back()->children.back(), "Baluchi");
			t.addChild(t.root()->children.back()->children.back(), "Kurdish");
		t.addChild(t.root()->children.back(), "Indic");
			t.addChild(t.root()->children.back()->children.back(), "Sanskrit");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Hindi");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Urdu");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Bengali");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Punjabi");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Gujurati");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Assamese");
				t.addChild(t.root()->children.back()->children.back()->children.back(), "Romany");
	
	t.addChild(t.root(), "Tocharian");
	
	//preorder with tabs
	t.preorder();
	
	cout << "\nHeight: " << t.height() << endl;
}