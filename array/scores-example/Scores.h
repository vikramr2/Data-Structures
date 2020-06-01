#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class Scores {
	public:
		struct GameEntry {
			string name;
			int score;
		};
		Scores(int maxEnt = 10);
		~Scores();
		void add(const GameEntry& e);
		GameEntry remove(int i) throw (out_of_range);
		void print();
	private:
		int maxEntries;
		int numEntries;
		GameEntry* entries;
};