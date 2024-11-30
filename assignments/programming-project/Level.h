#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>

// Represents a level in the game, implemented as a singly linked list node.
struct Level {
    std::string description; // Description of the level
    Level* next;             // Pointer to the next level
    Level* prev;             // Pointer to the previous level

    Level(const std::string& desc) : description(desc), next(nullptr), prev(nullptr) {} // Constructor
};

// Functions for managing levels
void addLevel(Level*& head, const std::string& desc); // Add a level to the list
void displayLevels(Level* head);                      // Display all levels in the list

#endif