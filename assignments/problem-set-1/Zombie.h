#pragma once
#include "Entity.h"
using namespace std;

class Zombie : public Entity {
public:
    // Constructor
    Zombie(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon);

    // Zombie-specific method
    void Growl();

    // Destructor
    virtual ~Zombie();
};
