#include <iostream>
#include "Animal.h"
#include "Cat.h"
using namespace std;

Animal::Animal(){
	cout << "Animal constructor" << endl;
}

Animal::~Animal() {
	cout << "Animal destructor" << endl;
}

void Animal::sayName() {
	cout << "I am an animal." << endl;
}

void Animal::makeCall() {
	cout << "Animal makes a sound." << endl;
}

