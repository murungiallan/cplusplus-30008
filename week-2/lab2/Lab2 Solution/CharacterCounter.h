#pragma once
#include <iostream>
using namespace std;

class CharacterCounter
{
private:
	int fTotalNumberOfCharacters; //to store the total number of characters in the char array
	int fCharacterCounts[256];	// We count all 256 byte values

public:
	CharacterCounter(); //set everything to 0

	void count(char* str); //reset character counts, loop through char array to increase count

	//print out both fCharacterCounts and fTotalNumberOfCharacters
	friend ostream& operator<<(std::ostream& aOStream, 
		const CharacterCounter& aCharacterCounter);
};
