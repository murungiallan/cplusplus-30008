#include "CharacterCounter.h"
#include <iostream>

using namespace std;

CharacterCounter::CharacterCounter(void)
{
	fTotalNumberOfCharacters = 0;
	for (int i = 0; i < 256; i++)
	{
		fCharacterCounts[i] = 0;
	}
}

void CharacterCounter::count(char* str)
{
	for (int i = 0; i < 256; i++) { //resets character counts
		fCharacterCounts[i] = 0;
	}
	
	//the end of a c-string (zero-terminated char array) is always a '\0' char (value 0x00). 
	//You can use this knowledge to scroll though the chars in a string
	for (int i = 0; str[i] != '\0'; i++){
		fCharacterCounts[str[i]]++;
		fTotalNumberOfCharacters++;
	}

	/*
	//alternatively, you can go through a char array like this
	for (; *str; str++) {
		fCharacterCounts[*str]++;
		fTotalNumberOfCharacters++;
	}
	*/

}

ostream& operator<<(ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	for (int i = 0; i < 256; i++)
	{
		if (aCharacterCounter.fCharacterCounts[i] > 0)
		{
			aOStream << (unsigned char)i << ":\t" << aCharacterCounter.fCharacterCounts[i] << "\n";

		}
	}

	aOStream << "Total Number of Characters: " 
			<< aCharacterCounter.fTotalNumberOfCharacters << endl;

	return aOStream;
}