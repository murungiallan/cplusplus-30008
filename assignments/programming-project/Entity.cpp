#include "Entity.h"

// Constructor: Initializes the entity's name and health attributes.
Entity::Entity(const std::string& n, int h) : name(n), health(h) {}

// Virtual destructor: Ensures proper cleanup for derived classes.
Entity::~Entity() {}

// Check if the entity is alive (health > 0).
bool Entity::isAlive() const {
    return health > 0;
}

// Apply damage to the entity, ensuring health does not drop below zero.
void Entity::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0; // Ensure health is not negative
}

// Getter: Retrieve the entity's name.
std::string Entity::getName() const {
    return name;
}

// Getter: Retrieve the entity's health value.
int Entity::getHealth() const {
    return health;
}

// Overloaded << operator: Output entity details in a formatted way.
std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    os << "Entity Name: " << entity.name << ", Health: " << entity.health;
    return os;
}