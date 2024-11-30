#include "CharacterCounterIterator.h"
#include "CharacterCounter.h"
#include "FrequencyMap.h"
#include <iostream>

using namespace std;

CharacterCounterIterator::CharacterCounterIterator(CharacterCounter& aCounter) {
	fIndex = 0;
	for (int i = fIndex; i < 256; i++) {
		fMaps[i] = FrequencyMap(i, aCounter[i]);
	}

	for (int i = fIndex; i < 256; i++) {
		if (fMaps[i].getFrequency() > 0) {
			fIndex = 1;
			break;
		}
	}

}

CharacterCounterIterator::CharacterCounterIterator(CharacterCounterIterator& aCounterIt, int aIndex) {
	for (int i = aIndex; i < 256; i++) {
		fMaps[i] = aCounterIt.fMaps[i];
	}
	fIndex = aIndex;
}

const FrequencyMap& CharacterCounterIterator::operator*() const {
	return fMaps[fIndex];
}

CharacterCounterIterator& CharacterCounterIterator::operator++() {
	fIndex++;
	while (fMaps[fIndex].getFrequency() == 0)
		fIndex++;

	return *this;
} //prefix

CharacterCounterIterator& CharacterCounterIterator::operator++(int) {
	CharacterCounterIterator temp = *this;
	++(*this);
	return temp;
} // postfix

bool CharacterCounterIterator::operator==(const CharacterCounterIterator& aOther) const {
	return (fIndex == aOther.fIndex);

}

bool CharacterCounterIterator::operator!=(const CharacterCounterIterator& aOther) const {
	return !(*this == aOther);

}

CharacterCounterIterator CharacterCounterIterator::begin() const {
	for (int i = 0; i < 256; i++)
	{
		if (fMaps[i].getFrequency() > 0) {
			return CharacterCounterIterator(*this, i);
		}
		return *this;
	}

}

CharacterCounterIterator CharacterCounterIterator::end() const {
	return CharacterCounterIterator(*this, i);
}