#include <iostream>
#include "Iterator.h"
using namespace std;

ArrayIterator::ArrayIterator(const string aArray[], const int aLength, int aStart) : fArrayElements(aArray), fLength(aLength) {
	fIndex = aStart;
}

// Dereference operator - returns the element the iterator is currently positioned on
const string& ArrayIterator::operator*() const {
	return fArrayElements[fIndex];
}

// Prefix increment - advances the iterator and returns a reference of this iterator
ArrayIterator& ArrayIterator::operator++() {
	fIndex++;
	return *this;
}
 // Postfix increment - advances the iterator and returns a copy of the old iterator
ArrayIterator& ArrayIterator::operator++(int) {
	ArrayIterator temp = *this;
	fIndex++;
	return temp;
}

// Iterator equivalence
bool ArrayIterator::operator==(const ArrayIterator& aOther) const {
	return(fIndex == aOther.fIndex) && (fArrayElements == aOther.fArrayElements);
}

// Iterator inequality
bool ArrayIterator::operator!=(const ArrayIterator& aOther) const {
	return !(*this == aOther);
}


// Auxilliary Methods

// First element
ArrayIterator ArrayIterator::begin() const {
	return ArrayIterator(fArrayElements, fLength);
}

// Past-the-end element
ArrayIterator ArrayIterator::end() const {
	return ArrayIterator(fArrayElements, fLength, fLength);
}