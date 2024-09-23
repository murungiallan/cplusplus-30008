#include "Equipment.h"
#include <iostream>
using namespace std;

Equipment::Equipment(const string& name, int durability)
    : name(name), durability(durability) {
}

string Equipment::GetName() const {
    return name;
}

int Equipment::GetDurability() const {
    return durability;
}

void Equipment::SetName(const string& name) {
    this->name = name;
}

void Equipment::SetDurability(int durability) {
    this->durability = durability;
}

void Equipment::DecreaseDurability(int amount) {
    if (durability - amount >= 0) {
        durability -= amount;
    }
    else {
        durability = 0;
    }
}

Equipment::~Equipment() {
    cout << "Equipment " << name << " is destroyed." << endl;
}
