#pragma once
#include "SkillNode.h"
#include <string>

using namespace std;

class Character {
private:
    string name;  // Character name
    SkillNode* head; 

public:
    // Constructor - Initializes the character with a name
    Character(const string& name);

    // Destructor - cleanup
    ~Character();

    // Add a new skill to the character's existing skills
    void addSkill(const string& skillName, int level);

    // Remove a skill from the character's list of skills
    bool removeSkill(const string& skillName);

    // Display character information
    void displayCharacterInfo() const;
};

