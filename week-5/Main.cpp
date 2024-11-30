#include <iostream>
#include "CharacterCounter.h"
#include "CharacterCounterIterator.h"

using namespace std;

int main() {
	CharacterCounter lCounter;
	unsigned char lChar;
	while (lInput >> lChar) {
		lCounter.count(lChar);
	}

	lOutput << lCounter;

	// test iterator
	cout << "The frequencies: " < , endl;
	for (CharacterCounterIterator iter(lCounter); iter != iter.end(); iter++) {
		cout << (*iter).getCharacter() << ": " << (*iter).getFrequency() << endl;
	}
}