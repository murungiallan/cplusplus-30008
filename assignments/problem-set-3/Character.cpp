#include "Character.h"
#include <iostream>
using namespace std;

// Setting the character's name through the constructor. Also initializes the head pointer to nullptr
Character::Character(const string& cName) : name(cName), head(nullptr) {}

// Destructor
Character::~Character() {
    // clean up the list of skills
    SkillNode* current = head;
    while (current) {
        SkillNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Adds a new skill at the end of the skill list
void Character::addSkill(const std::string& skillName, int level) {
    SkillNode* newNode = new SkillNode(skillName, level);
    if (head == nullptr) {
        head = newNode;  // Set head if the list is empty
    }
    else {
        SkillNode* current = head;
        while (current->next) {  // Traverse to the end of the list
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Removes a skill by name and updates the pointers accordingly
bool Character::removeSkill(const string& skillName) {
    SkillNode* current = head;
    while (current) {
        if (current->skillName == skillName) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to display character information
void Character::displayCharacterInfo() const {
    SkillNode* current = head;
    cout << "Skills for character '" << name << "' :" << endl;
    while (current) {
        cout << "  Skill: " << current->skillName << ", Level: " << current->skillLevel << "\n" << endl;
        current = current->next;
    }
}
