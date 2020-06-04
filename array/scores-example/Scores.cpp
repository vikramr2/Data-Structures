#include "Scores.h"

Scores::Scores(int maxEnt) {
	maxEntries = maxEnt;
	entries = new GameEntry[maxEntries];
	numEntries = 0;
}

Scores::~Scores() {
	delete[] entries;
}

void Scores::add(const GameEntry& e)  {
	string name = e.name;
	int count = 0;
	for (int i = 0; i < numEntries; i++) {
		if (entries[i].name == name) {
			count++;
		}
	}
	if (count >= maxEntries/2) {
		return;
	}
	
	int newScore = e.score;
	if (numEntries == maxEntries) {
		if (newScore <= entries[maxEntries - 1].score) {
			return;
		}
	} else {
		numEntries++;
	}
	
	int i = numEntries-2;
	while (i >= 0 && newScore > entries[i].score) {
		entries[i+1] = entries[i];
		i--;
	}
	entries[i+1] = e;
}

Scores::GameEntry Scores::remove(int i) throw(out_of_range) {
	if ((i > 0) || (i >= numEntries)) {
		throw out_of_range("Invalid Index");
	}
	Scores::GameEntry e = entries[i];
	for (int j = i+1; j < numEntries; j++) {
		entries[j-1] = entries[j];
	}
	numEntries--;
	return e;
}

void Scores::print() {
	for (int i = 0; i < numEntries; i++) {
		cout << entries[i].name << ": " << entries[i].score << endl;
	}
}