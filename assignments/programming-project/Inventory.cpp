#include "Inventory.h"

// Constructor: Initializes an empty inventory.
Inventory::Inventory() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor: Creates a deep copy of another inventory.
Inventory::Inventory(const Inventory& other) : head(nullptr), tail(nullptr), size(0) {
    DoublyLinkedNode* current = other.head;
    while (current) {
        addItem(current->itemName, current->quantity); // Copy each item
        current = current->next;
    }
}

// Copy assignment operator: Performs deep copy from another inventory.
Inventory& Inventory::operator=(const Inventory& other) {
    if (this == &other) return *this; // Self-assignment guard

    // Clear existing inventory
    DoublyLinkedNode* current = head;
    while (current != nullptr) {
        DoublyLinkedNode* next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    size = 0;

    // Copy items from the other inventory
    current = other.head;
    while (current) {
        addItem(current->itemName, current->quantity);
        current = current->next;
    }

    return *this;
}

// Destructor: Deallocates memory for all inventory nodes.
Inventory::~Inventory() {
    DoublyLinkedNode* current = head;
    while (current != nullptr) {
        DoublyLinkedNode* next = current->next;
        delete current;
        current = next;
    }
}

// Add an item to the inventory, updating quantity if it already exists.
void Inventory::addItem(const std::string& itemName, int quantity) {
    DoublyLinkedNode* current = head;
    while (current) {
        if (current->itemName == itemName) {
            current->quantity += quantity; // Update quantity
            if (current->quantity <= 0) {
                removeItem(itemName); // Remove item if quantity is zero or less
            }
            return;
        }
        current = current->next;
    }

    // Add new item if not found
    DoublyLinkedNode* newNode = new DoublyLinkedNode(itemName, quantity);
    if (!head) {
        head = tail = newNode; // Set as head if inventory is empty
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Remove an item from the inventory by its name.
void Inventory::removeItem(const std::string& itemName) {
    DoublyLinkedNode* current = head;
    while (current) {
        if (current->itemName == itemName) {
            if (current->prev) current->prev->next = current->next;
            else head = current->next; // Update head if first node is removed

            if (current->next) current->next->prev = current->prev;
            else tail = current->prev; // Update tail if last node is removed

            delete current; // Free memory
            size--;
            return;
        }
        current = current->next;
    }
}

// Get the quantity of a specific item by its name.
int Inventory::getItemCount(const std::string& itemName) const {
    DoublyLinkedNode* current = head;
    while (current) {
        if (current->itemName == itemName) return current->quantity; // Return quantity if found
        current = current->next;
    }
    return 0; // Item not found
}

// Display all items and their quantities in the inventory.
void Inventory::displayInventory() const {
    if (isEmpty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    DoublyLinkedNode* current = head;
    int index = 1;
    while (current) {
        std::cout << index++ << ". " << current->itemName << " x" << current->quantity << "\n";
        current = current->next;
    }
}

// Retrieve the node of an item at a specific position (1-based index).
DoublyLinkedNode* Inventory::getItemAt(int position) const {
    if (position < 1 || position > size) return nullptr; // Validate position
    DoublyLinkedNode* current = head;
    for (int i = 1; i < position; ++i) {
        current = current->next;
    }
    return current;
}