#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H

#include <string>

// Struct representing a node in a doubly linked list.
struct DoublyLinkedNode {
    std::string itemName; // Name of the item stored in the node.
    int quantity;         // Quantity of the item.
    DoublyLinkedNode* prev; // Pointer to the previous node in the list.
    DoublyLinkedNode* next; // Pointer to the next node in the list.

    // Constructor: Initializes a node with a given name and quantity.
    DoublyLinkedNode(const std::string& name, int qty)
        : itemName(name), quantity(qty), prev(nullptr), next(nullptr) {}
};

#endif