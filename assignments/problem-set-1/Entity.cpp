#include "Entity.h"
using namespace std;

Entity::Entity()
	: fID(0), fName("June"), fStamina(99), fSpeed(1), fPosition({ 0.0f, 0.0f }),
	fMaxHP(99), fCurrentHP(99), fAttack(99), fWeapon(nullptr) {
	for (int i = 0; i < 10; i++) {
		equipment[i] = Equipment();
	}
	cout << "Default Entity has been created." << endl;
}

Entity::Entity(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon)
	: fID(id), fName(name), fStamina(stamina), fSpeed(speed), fPosition(position),
	fMaxHP(maxHP), fCurrentHP(currentHP), fAttack(attack), fWeapon(weapon) {
	cout << "Entity " << fID << " has been created." << endl;
}

// Getters
int Entity::GetID() const {
	return fID;
}

string Entity::GetName() const {
	return fName;
}

int Entity::GetStamina() const {
	return fStamina;
}

int Entity::GetSpeed() const {
	return fSpeed;
}

Position Entity::GetPosition() const {
	return fPosition;
}

int Entity::GetMaxHP() const {
	return fMaxHP;
}

int Entity::GetCurrentHP() const {
	return fCurrentHP;
}

int Entity::GetAttack() const {
	return fAttack;
}

Weapon* Entity::GetWeapon() const {
	return fWeapon;
}

string Entity::GetMessage() const {
	return fMessage;
}

string Entity::PrintStat() const {
	string stats = "ID: " + to_string(fID) + "\n"
		+ "Name: " + fName + "\n"
		+ "Stamina: " + to_string(fStamina) + "\n"
		+ "Speed: " + to_string(fSpeed) + "\n"
		+ "Position: (" + to_string(fPosition.x) + ", " + to_string(fPosition.y) + ")\n"
		+ "Max HP: " + to_string(fMaxHP) + "\n"
		+ "Current HP: " + to_string(fCurrentHP) + "\n"
		+ "Attack: " + to_string(fAttack) + "\n"
		+ "Message: " + fMessage + "\n";
	return stats;
}

// Setters
void Entity::SetfID(int id) 
{ 
	fID = id; 
}

void Entity::SetfName(const string& name) 
{ 
	fName = name; 
}

void Entity::SetfStamina(int stamina) 
{ 
	fStamina = stamina; 
}

void Entity::SetfSpeed(int speed) 
{ 
	fSpeed = speed; 
}

void Entity::SetfPosition(Position position) { 
	fPosition = position; 
}

void Entity::SetfMaxHP(int maxHP) 
{ 
	fMaxHP = maxHP; 
}

void Entity::SetfCurrentHP(int currentHP) 
{
	if (currentHP >= 0 && currentHP <= fMaxHP) {
		fCurrentHP = currentHP;
	}
	else {
		cout << "Invalid HP value!" << endl;
	}
}

void Entity::SetfAttack(int attack) 
{ 
	fAttack = attack; 
}

void Entity::SetfWeapon(Weapon* weapon) 
{ 
	fWeapon = weapon; 
}

void Entity::SetMessage(const string& message) // Set message
{ 
	fMessage = message; 
}


// Movement method
void Entity::Move(int deltaX, int deltaY) {
	fPosition.x += deltaX * fSpeed;
	fPosition.y += deltaY * fSpeed;
	cout << fName << " moved to (" << fPosition.x << ", " << fPosition.y << ")." << endl;
}

// Attack method
void Entity::Attack(Entity& target) {
	if (fWeapon) {
		cout << fName << " attacks " << target.GetName() << " with " << fWeapon->GetName() << endl;
		target.SetfCurrentHP(target.GetCurrentHP() - fWeapon->GetDamage());
		cout << target.GetName() << " now has " << target.GetCurrentHP() << " HP left." << endl;
	}
	else {
		cout << fName << " has no weapon to attack with!" << endl;
	}
}

// Die method
void Entity::Die() {
	cout << fName << " has died." << endl;
}

// Destructor
Entity::~Entity() {
	cout << "Entity Destructor called." << endl;
}

// Operator Overloading for Output (<<)
ostream& operator<<(ostream& aOStream, Entity& entity) {
	aOStream << "ID: " << entity.GetID() << "\n"
		<< "Name: " << entity.GetName() << "\n"
		<< "Stamina: " << entity.GetStamina() << "\n"
		<< "Speed: " << entity.GetSpeed() << "\n"
		<< "Position: (" << entity.GetPosition().x << ", " << entity.GetPosition().y << ")\n"
		<< "Max HP: " << entity.GetMaxHP() << "\n"
		<< "Current HP: " << entity.GetCurrentHP() << "\n"
		<< "Attack: " << entity.GetAttack() << "\n"
		<< "Message: " << entity.GetMessage() << "\n";
	return aOStream;
}


// Operator Overloading for Input (>>)
istream& operator>>(istream& aIStream, Entity& entity) {
	cout << "Enter ID: ";
	aIStream >> entity.fID;

	cout << "Enter Name: ";
	aIStream >> entity.fName;

	cout << "Enter Stamina: ";
	aIStream >> entity.fStamina;

	cout << "Enter Speed: ";
	aIStream >> entity.fSpeed;

	cout << "Enter Position (x y): ";
	aIStream >> entity.fPosition.x >> entity.fPosition.y;

	cout << "Enter Max HP: ";
	aIStream >> entity.fMaxHP;

	cout << "Enter Current HP: ";
	aIStream >> entity.fCurrentHP;

	cout << "Enter Attack Power: ";
	aIStream >> entity.fAttack;

	cout << "Enter Last Message: ";
	aIStream.ignore(); // Ignore newline character
	getline(aIStream, entity.fMessage);

	return aIStream;
}
