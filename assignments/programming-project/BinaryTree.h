#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "PathNode.h" // Dependency: Node class used in the binary tree.
#include <vector>     // For potential future use in tree operations.
#include <queue>      // For breadth-first traversal (future scalability).
#include <stack>      // For depth-first traversal (future scalability).
#include <unordered_map> // storing metadata.
#include <list>       // Placeholder for list-based operations.

// BinaryTree class: Represents a binary tree structure with basic operations.
class BinaryTree {
private:
    PathNode* root; // Pointer to the root node of the tree.

public:
    BinaryTree(); // Constructor to initialize the tree.
    ~BinaryTree(); // Destructor to clean up resources.
    void addPaths(); // Adds predefined paths to the tree.
    void deleteTree(PathNode* node); // Recursively deletes all nodes in the tree.
    PathNode* getRoot() const { return root; } // Getter for the root node.
};

#endif