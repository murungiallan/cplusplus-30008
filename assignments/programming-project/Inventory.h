#ifndef INVENTORY_H
#define INVENTORY_H

#include "DoublyLinkedNode.h" // Node structure for the doubly linked list
#include <string>             // For item names and descriptions
#include <iostream>           // For input/output operations

class InventoryIterator;      // Forward declaration for iterator functionality

// Inventory class: Represents a doubly linked list of items.
class Inventory {
private:
    DoublyLinkedNode* head;  // Pointer to the first node in the list
    DoublyLinkedNode* tail;  // Pointer to the last node in the list
    int size;                // Current number of items in the inventory

public:
    Inventory();                            // Default constructor
    Inventory(const Inventory& other);      // Copy constructor for deep copy
    Inventory& operator=(const Inventory& other); // Copy assignment operator
    ~Inventory();                           // Destructor to clean up memory

    void addItem(const std::string& itemName, int quantity); // Add or update an item
    void removeItem(const std::string& itemName);            // Remove an item by name
    void displayInventory() const;                          // Display all inventory items
    int getItemCount(const std::string& itemName) const;     // Get the quantity of an item
    DoublyLinkedNode* getItemAt(int position) const;         // Retrieve an item by its position

    int getSize() const { return size; }     // Get the number of items in the inventory
    bool isEmpty() const { return size == 0; } // Check if the inventory is empty

    friend class InventoryIterator;         // Grant InventoryIterator access to private members
};

#endif