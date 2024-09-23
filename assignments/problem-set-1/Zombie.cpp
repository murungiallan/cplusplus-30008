#include "Zombie.h"
#include <iostream>
using namespace std;

Zombie::Zombie(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon)
    : Entity(id, name, stamina, speed, position, maxHP, currentHP, attack, weapon) {
    cout << "Zombie " << name << " has been created." << endl;
}

void Zombie::Growl() {
    cout << fName << " growls menacingly." << endl;
}

Zombie::~Zombie() {
    cout << "Zombie " << fName << " has been destroyed." << endl;
}
