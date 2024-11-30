#include "Player.h"
#include <iostream>

// Constructor: Initializes the player with a name, health, and default values for attributes.
Player::Player(const std::string& name, int health)
    : name(name), health(health), baseAttack(10), defenseBoost(0), temporaryDefenseBoost(0) {}

// Add an item to the player's inventory.
void Player::addItem(const std::string& item, int quantity) {
    inventory.addItem(item, quantity);
}

// Display the player's inventory.
void Player::showInventory() const {
    std::cout << "\n--- Inventory of " << name << " ---\n";
    inventory.displayInventory();
}

// Interaction with an NPC offering a Health Potion.
void Player::interactWithNPC(const std::string& npcName) {
    std::cout << npcName << ": \"The forest is dangerous. Would you like a Health Potion? (y/n)\"\n";
    std::cout << "Enter choice: ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        addItem("Health Potion", 1);
        std::cout << "You received a Health Potion.\n";
    }
    else {
        std::cout << "You declined the offer.\n";
    }
}

// Simulate an attack by the player.
void Player::attackEnemy() {
    std::cout << name << " attacks the enemy!\n";
}

// Restore health to the player.
void Player::restoreHealth(int amount) {
    health += amount;
    std::cout << name << " restores " << amount << " health points. Health: " << health << "\n";
}

// Check if the player is still alive.
bool Player::isAlive() const {
    return health > 0;
}

// Attack using a specified weapon and damage.
void Player::attackWithWeapon(const std::string& weapon, int damage) {
    if (weapon == "Sword") {
        std::cout << getName() << " swings the Sword, dealing " << damage << " damage!\n";
    }
    else {
        std::cout << getName() << " attacks with " << weapon << " for " << damage << " damage.\n";
    }
}

// Defend using a specified weapon and defense points.
void Player::defendWithWeapon(const std::string& weapon, int defensePoints) {
    if (weapon == "Shield") {
        std::cout << getName() << " raises the Shield, reducing incoming damage by " << defensePoints << " points!\n";
        temporaryDefenseBoost = defensePoints;
    }
    else {
        std::cout << getName() << " defends with " << weapon << ", gaining a temporary defense.\n";
    }
}

// Handle damage taken by the player, factoring in a defense boost.
void Player::takeDamage(int damage, int defenseBoost) {
    if (defenseBoost > 0) {
        damage -= defenseBoost;
        std::cout << name << " used a defense boost of " << defenseBoost << ", reducing incoming damage.\n";
    }
    damage = (damage > 0) ? damage : 0;
    health -= damage;
    std::cout << name << " takes " << damage << " damage. Remaining health: " << health << "\n";
    if (health < 0) health = 0;
}

// Overload the << operator to display player details.
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.name << "\nHealth: " << player.health << "\nInventory:\n";
    player.inventory.displayInventory();
    return os;
}
