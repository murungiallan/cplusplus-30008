#pragma once
#include <iostream>

using namespace std;

class ArrayIterator {
private:
	// The attributes here are meant to reference (not copy) a container
	const string* fArrayElements;
	const int fLength;

	// Keeping track of which element is currently selected
	int fIndex;

public:
	// Constructor: initialize the array pointer, size and starting element index
	//*int aStart = 0 helps assign a value by default
	ArrayIterator(const string aArray[], const int aLength, int aStart = 0);

	// Input Iterator Operators
	const string& operator*() const; // For accessing selected element's value
	ArrayIterator& operator++(); // Step forward - return new position
	ArrayIterator& operator++(int); // Step forward - return old position
	bool operator==(const ArrayIterator& aOther) const; // True if array and index match
	bool operator!=(const ArrayIterator& aOther) const; //False if array and index match

	ArrayIterator begin() const; // Return a copy of this iterator, index at the beginning
	ArrayIterator end() const; // Return a copy of this iterator, index at the end

};