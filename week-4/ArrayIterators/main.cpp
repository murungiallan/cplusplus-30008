#include <iostream>
#include "Iterator.h"

using namespace std;

int main() {
	// Step 1: Create a sample array to act as our container
	const int sArrSize = 5;
	string sArr[sArrSize] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

	// Step 2: Forward Input Iterator. The iterator's life only exists within the For loop's scope.
	for (ArrayIterator iter(sArr, sArrSize); iter != iter.end(); iter++) {
		cout << *iter << endl;
	}

	// Step 3: Dynamic array of strings
	int sDynamicArraySize = 0;
	cout << endl << "Enter a preferred array size: ";
	cin >> sDynamicArraySize;

	string* sDynamicArray = new string[sDynamicArraySize];

	for (int a = 0; a < sDynamicArraySize; a++) {
		cout << "Enter value: ";
		cin >> sDynamicArray[a];
	}

	for (ArrayIterator iterator(sDynamicArray, sDynamicArraySize); iterator != iterator.end(); iterator++) {
		cout << *iterator << endl;
	}

	delete[] sDynamicArray; // Delete the whole dynamic array because it is in the heap

	return 0;
}