#pragma once
#include <iostream>
using namespace std;

/*
Notice, there is a boilerplate along with
an #include <iostream>, to make sure the basic
datatypes like "string" can be recognized.
*/

/*
Known as the Class Definition, this allows other
programmers to see what functions and attributes your
class has available. But how it works, is hidden.
*/
class Entity
{
private:

protected:
	string fID;

public:
	Entity();
	string Get_ID();
	void Set_ID(string aID);
	
	//A friend operator overload needs the "friend" keyword
	friend ostream& operator<<(ostream& aOut, Entity& aEnt);
};