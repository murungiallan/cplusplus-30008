#include "BossZombie.h"
#include <iostream>

using namespace std;

BossZombie::BossZombie(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon, int specialAttackPower)
    : Entity(id, name, stamina, speed, position, maxHP, currentHP, attack, weapon), specialAttackPower(specialAttackPower) {
    cout << "BossZombie " << name << " has been created." << endl;
}

void BossZombie::SpecialAttack(Entity& target) {
    int totalDamage = fAttack + specialAttackPower;
    cout << fName << " uses a special attack on " << target.GetName() << " causing " << totalDamage << " damage!" << endl;
    target.SetfCurrentHP(target.GetCurrentHP() - totalDamage);
    cout << target.GetName() << " now has " << target.GetCurrentHP() << " HP left." << endl;
}

void BossZombie::Taunt() {
    cout << fName << " taunts the enemies with a menacing laugh!" << endl;
}

BossZombie::~BossZombie() {
    cout << "BossZombie " << fName << " has been destroyed." << endl;
}
