#pragma once
#include "FrequencyMap.h"
#include <iostream>

class CharacterCounter {
private:
	int fTotalNumberOfCharacters;
	int fCharacterCounts[256];

public:
	CharacterCounter();
	void count(unsigned char aCharacter);

	friend std::ostream& operator<<(std::ostream& aOstream, const CharacterCounter& aCharacterCounter);

	int operator[](unsigned char aCharacter) const;
};
