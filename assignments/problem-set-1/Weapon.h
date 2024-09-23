#pragma once
#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int damage;

public:
    // Constructor
    Weapon(const string& name = "Default Weapon", int damage = 10);

    // Getters
    string GetName() const;
    int GetDamage() const;

    // Setters
    void SetName(const string& name);
    void SetDamage(int damage);

    // Destructor
    ~Weapon();
};

