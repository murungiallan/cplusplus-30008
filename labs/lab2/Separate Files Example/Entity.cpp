#include "Entity.h"
/*
This is the Entity's Class Implementation. We start by
including the Header File. Use the double-quotes "" to 
reference the file is in the same folder as this .cpp file.
Use the same name for both .cpp and .h file for a class.
*/

//For constructors and methods/functions, don't forget the 
//reference, so the compiler knows which class the Implementation
//belongs to.
Entity::Entity()
{
	fID = "";
}

//Notice the string type does not need the std:: namespace.
//This is because Iostream is included in the header file already, and
//"using namespace std;" is there too.
string Entity::Get_ID()
{
	return fID;
}

void Entity::Set_ID(string aID)
{
	fID = aID;
	return;
}


//Implementation of the friend operator overload for COUT object.
//Notice that we don't have to add the "friend" keyword.
//That is only required in the Class Definition.
ostream& operator<<(ostream& aOut, Entity& aEnt)
{
	aOut << "ID:" << aEnt.fID << endl;
	return aOut;
}