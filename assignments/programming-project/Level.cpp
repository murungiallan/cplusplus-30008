#include "Level.h"

// Add a new level to the linked list of levels.
void addLevel(Level*& head, const std::string& desc) {
    Level* newLevel = new Level(desc);
    if (!head) {
        head = newLevel; // Initialize the head if the list is empty
    }
    else {
        Level* temp = head;
        while (temp->next) temp = temp->next; // Traverse to the end
        temp->next = newLevel; // Link the new level to the end of the list
        newLevel->prev = temp; // Set the previous pointer of the new level
    }
}

// Display all levels in the linked list.
void displayLevels(Level* head) {
    Level* temp = head; // Start from the head of the list
    while (temp) { // Traverse through the levels
        std::cout << "Level " << temp->description << "\n"; // Print the description
        temp = temp->next; // Move to the next level
    }
}
