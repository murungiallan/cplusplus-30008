#ifndef ENEMY_H
#define ENEMY_H

#include <string>

// Enemy class: Represents an enemy with a name and health attributes.
class Enemy {
private:
    std::string name; // Name of the enemy.
    int health;       // Health value of the enemy.

public:
    Enemy(const std::string& name, int health); // Constructor to initialize an enemy.

    void takeDamage(int amount); // Reduces health by a specified amount.
    bool isAlive() const;        // Checks if the enemy is alive.
    std::string getName() const { return name; } // Returns the enemy's name.
    int getHealth() const { return health; }    // Returns the enemy's health.
};

#endif