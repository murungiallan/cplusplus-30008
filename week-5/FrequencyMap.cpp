#include "FrequencyMap.h"

FrequencyMap::FrequencyMap(void) {

}

// initialize
FrequencyMap::FrequencyMap(char aChar, int aFrequency) {
	fChar = aChar;
	fFrequency = aFrequency;
}

// read-only getters
char FrequencyMap::getCharacter() const {
	return fChar;
}

// retrieve character
int FrequencyMap::getFrequency() const {
	return fFrequency;
}