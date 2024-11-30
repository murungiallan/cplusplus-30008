#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"
#include <string>
#include <iostream>

// Represents a player in the game.
class Player {
private:
    std::string name;             // Player's name
    int health;                   // Player's health
    Inventory inventory;          // Player's inventory
    int baseAttack = 10;          // Default attack value
    int defenseBoost = 0;         // Persistent defense boost
    int temporaryDefenseBoost;    // Temporary defense boost for specific actions

public:
    Player(const std::string& name, int health); // Constructor

    // Inventory management
    void addItem(const std::string& item, int quantity);
    void showInventory() const;

    // NPC interaction and combat
    void interactWithNPC(const std::string& npcName);
    void attackEnemy();
    void takeDamage(int damage, int defenseBoost = 0);
    void restoreHealth(int amount); // Heal the player
    bool isAlive() const;           // Check if the player is alive
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    Inventory& getInventory() { return inventory; }

    // Weapon-specific actions
    void attackWithWeapon(const std::string& weapon, int damage);
    void defendWithWeapon(const std::string& weapon, int defensePoints);

    // Overloaded operator for displaying player details
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};

#endif
