#pragma once
#include "Entity.h"
using namespace std;

class Player : public Entity {
private:
    int experiencePoints;

public:
    // Constructor
    Player(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon, int xp);

    // Player-specific methods
    void GainExperience(int xp);
    void LevelUp();

    // Destructor
    virtual ~Player();
};
