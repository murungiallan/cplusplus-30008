#pragma once
#include <string>
using namespace std;

class Equipment {
private:
    string name;
    int durability;

public:
    // Constructor
    Equipment(const string& name = "Default", int durability = 100);

    // Getters
    string GetName() const;
    int GetDurability() const;

    // Setters
    void SetName(const string& name);
    void SetDurability(int durability);

    // Decrease durability method
    void DecreaseDurability(int amount);

    // Destructor
    ~Equipment();
};
