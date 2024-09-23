#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int id, const string& name, int stamina, int speed, Position position, int maxHP, int currentHP, int attack, Weapon* weapon, int xp)
    : Entity(id, name, stamina, speed, position, maxHP, currentHP, attack, weapon), experiencePoints(xp) {
    cout << "Player " << name << " has been created." << endl;
}

void Player::GainExperience(int xp) {
    experiencePoints += xp;
    cout << fName << " gained " << xp << " experience points." << endl;
}

void Player::LevelUp() {
    if (experiencePoints >= 100) {
        fMaxHP += 10;
        fAttack += 5;
        experiencePoints = 0;
        cout << fName << " has leveled up! New Max HP: " << fMaxHP << ", Attack: " << fAttack << endl;
    }
}

Player::~Player() {
    cout << "Player " << fName << " has been destroyed." << endl;
}
