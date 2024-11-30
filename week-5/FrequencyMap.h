#pragma once

class FrequencyMap {
private:
	char fChar;
	int fFrequency;

public:
	// default constructor
	FrequencyMap();

	// initialize
	FrequencyMap(char aChar, int aFrequency);

	// read-only getters
	char getCharacter() const;

	// retrieve character
	int getFrequency() const;
};
