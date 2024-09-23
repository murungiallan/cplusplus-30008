#pragma once
#include "Entity.h"
using namespace std;

class BossZombie : public Entity {
private:
    int specialAttackPower; // Additional attack power for special moves

public:
    // Constructor
    BossZombie(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon, int specialAttackPower);

    // Special attack method
    void SpecialAttack(Entity& target);

    // Taunt method
    void Taunt();

    // Destructor
    virtual ~BossZombie();
};
