#pragma once
#include <iostream>
#include <string>
#include "Weapon.h"
#include "Equipment.h"

using namespace std;

struct Position {
    float x;
    float y;
};

class Entity {
private:
    string fMessage; // store the last message sent

protected:
    int fID; // unique identifier for this Entity
    string fName; // Entity's name
    int fStamina; // Entity's stamina during the game
    int fSpeed; // Entity's speed while moving
    Position fPosition; // Entity's position in the game
    int fMaxHP; // Entity's maximum health
    int fCurrentHP; // Entity's current health
    int fAttack; // Entity's attack damage
    Weapon* fWeapon; // Pointer to Weapon class
    Equipment equipment[10]; // Array of Equipment

public:
    // Default constructor
    Entity();

    // Entity and its attributes
    Entity(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon);

    // Getters
    int GetID() const;
    string GetName() const;
    int GetStamina() const;
    int GetSpeed() const;
    Position GetPosition() const;
    int GetMaxHP() const;
    int GetCurrentHP() const;
    int GetAttack() const;
    Weapon* GetWeapon() const;
    string GetMessage() const;

    // Setters
    void SetfID(int id);
    void SetfName(const string& name);
    void SetfStamina(int stamina);
    void SetfSpeed(int speed);
    void SetfPosition(Position position);
    void SetfMaxHP(int maxHP);
    void SetfCurrentHP(int currentHP);
    void SetfAttack(int attack);
    void SetfWeapon(Weapon* weapon);
    void SetMessage(const string& message);

    // Methods
    void Move(int deltaX, int deltaY);
    void Attack(Entity& target);
    void Die();

    // Function to print stats
    string PrintStat() const; // Marked const

    // Friend operators for input and output
    friend ostream& operator<<(ostream& aOStream, const Entity& entity);
    friend istream& operator>>(istream& aIStream, Entity& entity);

    // Destructor
    virtual ~Entity();
};