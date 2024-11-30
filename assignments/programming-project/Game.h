#ifndef GAME_H
#define GAME_H

// Game-specific class headers
#include "Player.h"               // Defines the Player class, representing the main playable character.
#include "Enemy.h"                // Defines the Enemy class, representing adversaries encountered during gameplay.
#include "InventoryIterator.h"    // Provides an iterator for traversing the player's inventory.
#include "BinaryTree.h"           // Manages the binary tree structure for navigating the game's map.
#include "Stack.h"                // Implements a stack for managing checkpoints in the game.
#include "Queue.h"                // Implements a queue for handling in-game events.
#include "Level.h"                // Manages the linked list structure for game levels.

// Standard library headers
#include <stack>                  // Provides the stack container for LIFO operations (used in the Stack class).
#include <unordered_map>          // Implements a hash map for fast key-value pair lookups (e.g., path events, item descriptions).
#include <queue>                  // Provides the queue container for FIFO operations (used in the Queue class).
#include <list>                   // Provides the doubly linked list container for sequential operations (e.g., path logs).
#include <string>                 // Supports string operations for player names, item names, and descriptions.
#include <vector>                 // Provides a dynamic array container for storing exploration locations.
#include <functional>             // Enables the use of function objects and callbacks for event handling.

// External library headers
#include <SFML/Audio.hpp>         // Adds audio functionality, including background music and sound effects.


class Game {
private:
    sf::Music backgroundMusic;          // Background music
    sf::Sound explorationSound;         // Sound for exploration
    sf::Sound combatSound;              // Sound for combat
    sf::Sound itemSound;                // Sound for item usage
    sf::Sound congratulationsSound;     // Sound for congratulations
    sf::SoundBuffer congratulationsBuffer;  // Buffer for congratulations
    sf::SoundBuffer explorationBuffer;  // Buffer for exploration sound
    sf::SoundBuffer combatBuffer;       // Buffer for combat sound
    sf::SoundBuffer itemBuffer;         // Buffer for item usage

    // Game entities and player management
    Player hero;                           // Main player character
    Player warrior;                        // Alternative player character
    Player* currentPlayer;                 // Pointer to the currently active player
    Enemy monster;                         // Generic enemy for encounters
    int enemyDifficulty;                   // Difficulty level for scaling enemy strength

    // Inventory and items
    Inventory inventory;
    std::vector<std::string> locations;    // List of exploration locations

    // Path and level management
    int pathsExplored;                     // Count of paths explored to track progress
    BinaryTree forestPaths;                // Binary tree structure for forest paths
    PathNode* currentPath;                 // Pointer to the current path node in the binary tree
    std::stack<PathNode*> checkpoints;     // Stack to manage checkpoints
    Queue events;                          // Queue for in-game events
    Level* currentLevel;                   // Current level node for linked list of levels
    Level* levelHead;                      // Head of the level linked list

    // Navigation and history tracking
    std::stack<PathNode*> previousPaths;   // Stack for backtracking to previous paths
    std::unordered_map<std::string, bool> visitedPaths;  // Map to track visited paths
    std::queue<PathNode*> upcomingPaths;   // Queue for upcoming paths for player navigation
    std::list<std::string> pathLog;        // List to log the player's path history
    std::unordered_map<std::string, std::function<void()>> pathEvents; // Map specific paths to events

    // Private helper methods
    void move();                           // Navigate paths in the forest
    void backtrack();                      // Move back to previous paths
    void displayPathLog() const;           // Display the path log history
    void respawnAtCheckpoint();            // Respawn the player at the last checkpoint
    void advanceLevel();                   // Handle level progression logic

    // Combat and encounters
    void encounterEnemy();                 // Encounter and fight enemies

    // NPC interaction
    void interactWithNPC();                // Handles NPC interaction during exploration

    void loadAudio(); // Load audio files

public:
    // Constructor
    Game();

    // Destructor
    ~Game();

    // Initialization and storyline
    void initializeGame();                 // Set up the game environment and initial items
    void displayStoryline();               // Display the game's storyline and objective

    // Main gameplay loop
    void playGame();                       // Main game loop with menu options
    void showMenu();                       // Display the main menu for player choices

    // Inventory management
    void showCurrentPlayerInventory() const;   // Display the current player's inventory
    void addItemToCurrentPlayerInventory(const std::string& item, int quantity); // Add item to player's inventory
    void displayInventoryWithIterator() const; // Display inventory items using an iterator
    void chooseItemFromInventory(Enemy& enemy); // Choose an item from the inventory to use

    // Exploration
    void explore();                        // Explore locations and encounter items/enemies

    // Character management
    void switchCharacter();                // Switch between hero and warrior characters

    // Save and load game
    void saveGame();                       // Save the current game state to a file
    void loadGame();                       // Load the game state from a file

    // Helper functions
    std::string getItemDescription(const std::string& item); // Get descriptions for inventory items
    void addItemToInventory(const std::string& item);        // Add an item with a prompt for description

    // Checkpoint management
    void addCheckpoint(PathNode* checkpoint);  // Add a checkpoint at the current path
    void displayCheckpoints() const;           // Display the checkpoints stack
    PathNode* getLastCheckpoint() const;       // Get the last checkpoint from the stack
};

#endif // GAME_H