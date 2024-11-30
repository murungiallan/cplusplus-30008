#include "BinaryTree.h"

// Constructor: Initializes the binary tree with a root node and calls the addPaths method to create the tree structure.
BinaryTree::BinaryTree() {
    root = new PathNode("Forest Entrance");
    addPaths();
}

// Destructor: Ensures all dynamically allocated nodes are properly deleted to prevent memory leaks.
BinaryTree::~BinaryTree() {
    deleteTree(root);
}

// Recursive function to delete all nodes in the tree starting from a given node.
void BinaryTree::deleteTree(PathNode* node) {
    if (!node) return; // Base case: Stop if the node is null.
    deleteTree(node->left); // Recursively delete left subtree.
    deleteTree(node->right); // Recursively delete right subtree.
    delete node; // Delete the current node.
}

// Creates and links nodes to construct the binary tree with predefined paths.
void BinaryTree::addPaths() {
    root = new PathNode("Forest Entrance"); // Entry point of the binary tree.

    // Add left and right subtrees for the root.
    root->left = new PathNode("Misty Meadow"); // Left path from the entrance.
    root->right = new PathNode("Sunny Glade"); // Right path from the entrance.

    // Additional nodes for subsequent levels in the tree.
    root->left->left = new PathNode("Shaded Grove"); // Left path from Misty Meadow.
    root->left->right = new PathNode("Hidden Brook"); // Right path from Misty Meadow.
    root->right->left = new PathNode("Golden Clearing"); // Left path from Sunny Glade.
    root->right->right = new PathNode("Ancient Oak"); // Right path from Sunny Glade.

    // Expand further with additional nodes.
    root->left->left->left = new PathNode("Whispering Hollow"); // Deeper left path from Shaded Grove.
    root->left->left->right = new PathNode("Silent Pool"); // Deeper right path from Shaded Grove.
    root->left->right->left = new PathNode("Fern Pathway"); // Left path from Hidden Brook.
    root->left->right->right = new PathNode("Twilight Bridge"); // Right path from Hidden Brook.

    root->right->left->left = new PathNode("Crimson Field"); // Left path from Golden Clearing.
    root->right->left->right = new PathNode("Amber Woods"); // Right path from Golden Clearing.
    root->right->right->left = new PathNode("Sapphire Stream"); // Left path from Ancient Oak.
    root->right->right->right = new PathNode("Emerald Ridge"); // Right path from Ancient Oak.

    // Final level of nodes in the tree.
    root->left->left->left->left = new PathNode("Crystal Cavern"); // Deep left from Whispering Hollow.
    root->left->left->left->right = new PathNode("Moonlit Rock"); // Deep right from Whispering Hollow.
    root->right->right->right->left = new PathNode("Firefly Grove"); // Left path from Emerald Ridge.
    root->right->right->right->right = new PathNode("Starfall Peak"); // Right path from Emerald Ridge.
    root->left->right->left->left = new PathNode("Shadow Pass"); // Deep left path from Fern Pathway.
    root->left->right->left->right = new PathNode("Sunrise Plateau"); // Deep right path from Fern Pathway.
}