#ifndef PATHNODE_H
#define PATHNODE_H

#include <string>

// Represents a node in a binary tree structure for game paths.
class PathNode {
public:
    std::string name; // Name of the path
    PathNode* left;   // Pointer to the left child (left path)
    PathNode* right;  // Pointer to the right child (right path)

    PathNode(const std::string& name) : name(name), left(nullptr), right(nullptr) {} // Constructor
};

#endif