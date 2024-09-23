#include <iostream>
#include "Animal.h"
#include "Cat.h"
using namespace std;

Cat::Cat()
{
	cout << "Cat constructor" << endl;
}

Cat::~Cat()
{
	cout << "Cat destructor" << endl;
}

