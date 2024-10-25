#include <iostream>
using namespace std;

class Entity
{
protected:
	string ID;
public:
	Entity()
	{
		ID = "Default";
	}

	void SetID(string ID)
	{
		this->ID = ID;
	}

	string GetID()
	{
		return ID;
	}
};

class Character : Entity
{
private:
	string Profession;

public:
	Character(string Identity, string Prof)
	{
		ID = Identity;
		this->Profession = Prof;
	}

	void SetProfession(string Profession)
	{
		this->Profession = Profession;
	}

	string GetProfession()
	{
		return Profession;
	}

	string GetID() {
		return Entity::ID;
	}

	friend istream& operator>>(istream& aIstream, Character& aCharacter)
	{
		aIstream >> aCharacter.ID >> aCharacter.Profession;
		return aIstream;
	}

	friend ostream& operator<<(ostream& aOstream, Character& aCharacter)
	{
		aOstream << "ID:" << aCharacter.ID << " Profession:" << aCharacter.Profession;
		return aOstream;
	}
};

int main(int argc, char* argv[]) 
{
	Entity Something;

	string Name;
	cout << "Enter a name for this Object:";
	cin >> Name;

	Something.SetID(Name);

	cout << Something.GetID() << endl;

	Character Guy("Sam", "Hobbit");

	cout << Guy.GetProfession() << endl;
	cout << Guy.GetID() << endl; // Find out how to make this work instead of adding another string function in the derived class

	cin >> Guy;
	cout << Guy;

	return 0;
}