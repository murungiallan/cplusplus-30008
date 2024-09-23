#include "Entity.h"
#include "Weapon.h"
#include "Equipment.h"
#include "BossZombie.h"
#include "Player.h"
#include "Zombie.h"

#include <iostream>

using namespace std;

int main() {
    // Create a Weapon object
    Weapon* weapon = new Weapon("Sword", 50);

    // Initialize Entity with default constructor
    Entity entity;

    // Use input to modify entity details
    cin >> entity;

    // Display entity stats using overloaded <<
    cout << entity;

    // Cleanup dynamically allocated memory
    delete weapon;

    return 0;
}
