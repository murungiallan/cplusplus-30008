#pragma once
#include <string>
#include "Iterator1D.h"
using namespace std;

class Entity {

private:
	int fEntityID;
	std::string fName;
	int fHP;
	Iterator1D* iterator1D;

public:
	// constructor
	Entity(int fEntityID, string fName, int fHP) {
		this->fEntityID = fEntityID;
		this->fName = fName;
		this->fHP = fHP;
	}

	// getters
	int GetID() const {
		return fEntityID;
	}

	int GetHP() const {
		return fHP;
	}

	string GetName() const {
		return fName;
	}

	// setters
	void SetID(int fEntityID) {
		this->fEntityID = fEntityID;
	}

	void SetHP(int fHP) {
		this->fHP = fHP;
	}

	void SetName(string fName) {
		this->fName = fName;
	}

	void Print() const {
		cout << "Entity ID: " << fEntityID << "\nEntity Name: " << fName << "\nEntity's HP: " << fHP << endl;
	}

	void GrabIterator(Iterator1D* iterator) {
		iterator1D = iterator;
	}

	void InventoryNext() {
		// confirming if iterator 1D is not null therefore target the next element in the array
		(iterator1D != nullptr) ? ++(*iterator1D) : *iterator1D;
	}

	void InventoryPrev() {
		// confirming if iterator 1D is not null therefore target the previous element in the array
		(iterator1D != nullptr) ? --(*iterator1D) : *iterator1D;
	}

	void InventoryGet() {
		cout << "Current item in the bag: " << *(*iterator1D) << endl;
	}

};