#ifndef ENTITY_H
#define ENTITY_H

#include <string>   // For entity names
#include <iostream> // For output operations

// Abstract base class representing a generic entity.
class Entity {
protected:
    int health;           // Entity's health value
    std::string name;     // Entity's name

public:
    Entity(const std::string& n, int h); // Constructor
    virtual ~Entity();                   // Virtual destructor for polymorphism

    virtual void update() = 0;           // Pure virtual function for custom behavior

    bool isAlive() const;                // Check if the entity is alive
    void takeDamage(int amount);         // Apply damage to the entity

    std::string getName() const;         // Retrieve the entity's name
    int getHealth() const;               // Retrieve the entity's health

    friend std::ostream& operator<<(std::ostream& os, const Entity& entity); // Overloaded << operator
};

#endif