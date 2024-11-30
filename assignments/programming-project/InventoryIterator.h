#ifndef INVENTORY_ITERATOR_H
#define INVENTORY_ITERATOR_H

#include "Inventory.h"
#include "DoublyLinkedNode.h"
#include <utility>
#include <string>

// Iterator class to traverse the player's inventory.
class InventoryIterator {
private:
    const Inventory& inventory; // Reference to the inventory being traversed
    DoublyLinkedNode* currentNode; // Pointer to the current node in the inventory

public:
    InventoryIterator(const Inventory& inv);           // Constructor to initialize the iterator
    bool hasNext() const;                              // Check if there are more items
    void next();                                       // Move to the next item
    std::pair<std::string, int> currentItem() const;   // Get the current item's name and quantity
};

#endif