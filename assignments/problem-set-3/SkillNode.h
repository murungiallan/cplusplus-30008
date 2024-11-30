#pragma once
#include <string>
using namespace std;

// A class representing a skill node in a doubly linked list
class SkillNode {
public:
    string skillName;  // Name of the skill
    int skillLevel;    // Level of the skill
    SkillNode* next;   // Pointer to the next skill node
    SkillNode* prev;   // Pointer to the previous skill node

    // Constructor to initialize the skill with a name and level
    SkillNode(const std::string& name, int level);

    // Destructor
    ~SkillNode();
};

