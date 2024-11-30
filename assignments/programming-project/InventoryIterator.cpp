#include "InventoryIterator.h"

// Constructor: Initializes the iterator with the first node of the inventory.
InventoryIterator::InventoryIterator(const Inventory& inv)
    : inventory(inv), currentNode(inv.head) {}

// Check if there is another node in the inventory.
bool InventoryIterator::hasNext() const {
    return currentNode != nullptr;
}

// Move to the next node in the inventory.
void InventoryIterator::next() {
    if (hasNext()) currentNode = currentNode->next;
}

// Get the current item's name and quantity as a pair.
std::pair<std::string, int> InventoryIterator::currentItem() const {
    if (currentNode) {
        return { currentNode->itemName, currentNode->quantity };
    }
    return { "", 0 }; // Return default value if no current node
}