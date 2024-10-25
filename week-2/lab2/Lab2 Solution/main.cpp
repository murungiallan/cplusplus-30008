#include "CharacterCounter.h"
#include <iostream>

using namespace std;

int main() {
	CharacterCounter lCounter;

	const int arraySize = 50;
	char str[arraySize]; //char array of size 50

	//output all 256 unsigned chars
	cout << "All 256 unsigned chars:" << endl;

	for (int i = 0; i < 256; i++)
	{
		cout << (unsigned char)i;
	}

	cout << "\n" << endl;

	//test CharacterCounter class
	cout << "Enter a string: ";
	
	//cin >> str; //okay for single words
	cin.getline(str, arraySize);

	cout << "You have entered: " << str << endl;

	lCounter.count(str);
	cout << lCounter;

	return 0;
}