#pragma once
#include <string>
#include <iostream>

using namespace std;

class Iterator1D {
private:
	int size;
	int index;
	string* array;

public:
	// constructor
	Iterator1D(string* array, int size) {
		this->size = size;
		this->index = 0;
		this->array = array;
	}

	// Destructor
	~Iterator1D() {
		delete[] array;
		cout << "Iterator1D destructor executed." << endl;
	}

	Iterator1D& operator++() {
		(index < size - 1) ? index++ : index;
		return *this;
	}

	Iterator1D& operator--() {
		(index > 0) ? index-- : index;
		return *this;
	}

	string operator*() const {
		return array[index];
	}

	bool operator==(const Iterator1D& copyIterator1D) const {
		return index == copyIterator1D.index;
	}

	bool operator!=(const Iterator1D& copyIterator1D) const {
		return index != copyIterator1D.index;
	}

	friend std::ostream& operator<<(std::ostream& aOstream, const Iterator1D& iterator) {
		if (iterator.index >= 0 && iterator.index < iterator.size) {
			aOstream << "Bag is at index " << iterator.index << "(" << iterator.array[iterator.index] << ")";
		}
		else {
			aOstream << "out of bounds";
		}
		return aOstream;
	}

};
