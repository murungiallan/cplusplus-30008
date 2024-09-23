#include "Weapon.h"
#include <iostream>
using namespace std;

Weapon::Weapon(const string& name, int damage)
    : name(name), damage(damage) {
}

string Weapon::GetName() const {
    return name;
}

int Weapon::GetDamage() const {
    return damage;
}

void Weapon::SetName(const string& name) {
    this->name = name;
}

void Weapon::SetDamage(int damage) {
    this->damage = damage;
}

Weapon::~Weapon() {
    cout << "Weapon " << name << " is destroyed." << endl;
}
