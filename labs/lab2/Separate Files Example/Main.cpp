#include <iostream>
#include "Entity.h"
using namespace std;
/*
To add a class to your program, you need to include it.
Notice that you use a "" instead of a <>. This means the
target class (Entity) is found in the same directory/folder
as this Main.cpp, instead of from the Standard C Library path.
*/

//Try out various ways to instantiate Entity objects.
int main()
{
	Entity AttackDog;

	cout << AttackDog.Get_ID() << endl;

	string Name = "";

	cout << "Enter Name:";
	cin >> Name;
	AttackDog.Set_ID(Name);

	cout << AttackDog << endl;

	return 0;
}