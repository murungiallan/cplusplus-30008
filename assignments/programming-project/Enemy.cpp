#include "Enemy.h"
#include <iostream>

// Constructor: Initializes an enemy with a given name and health value.
Enemy::Enemy(const std::string& name, int health)
    : name(name), health(health) {}

// Method to apply damage to the enemy and reduce its health.
void Enemy::takeDamage(int amount) {
    health -= amount; // Subtract the damage from health.
    if (health < 0) health = 0; // Ensure health doesn't go negative.
    std::cout << name << " takes " << amount << " damage! Health: " << health << "\n";
}

// Method to check if the enemy is still alive.
bool Enemy::isAlive() const {
    return health > 0;
}