#include "Game.h"
#include "Inventory.h"
#include "InventoryIterator.h"
#include "Enemy.h"
#include "Player.h"
#include <windows.h>
#include <iostream>       // For input/output operations
#include <fstream>        // For file operations (save/load)
#include <cstdlib>        // For random number generation
#include <ctime>          // For seeding random number generator
#include <thread>         // For adding delays (immersion)
#include <chrono>         // For handling time durations
#include <unordered_map>  // For mapping paths to events

// Constructor: Initializes the game with default settings, characters, and paths.
Game::Game()
    : hero("Hero", 100), warrior("Warrior", 120), monster("Stalker", 50), enemyDifficulty(1), pathsExplored(0) {
    currentPlayer = &hero;                // Set the default player to the hero
    currentLevel = nullptr;               // No level assigned at the start
    currentPath = nullptr;                // No path selected at the start
    levelHead = nullptr;                  // Initialize level linked list to null
    forestPaths.addPaths();               // Populate the forest path binary tree
}

// Purpose was for debugging the audio directory
void printWorkingDirectory() {
    char buffer[MAX_PATH]; // Use a char buffer for ANSI
    if (GetCurrentDirectoryA(MAX_PATH, buffer)) { // Use GetCurrentDirectoryA for ANSI
        std::cout << "Current Working Directory: " << buffer << "\n";
    }
    else {
        std::cerr << "Failed to get current directory.\n";
    }
}

// Initialize the game by setting up items, paths, and story elements.
void Game::initializeGame() {
    //printWorkingDirectory();
    loadAudio(); // Load audio files
    backgroundMusic.play(); // Start background music
    backgroundMusic.setVolume(20); // Adjust volume

    displayStoryline();                   // Show the game’s introductory storyline
    checkpoints.push(forestPaths.getRoot()); // Set the starting checkpoint
    events.enqueue("A sudden chill fills the air..."); // Add initial events
    addLevel(levelHead, "1: Enchanted Meadow (easy)"); // Add levels to linked list
    addLevel(levelHead, "2: Dark Cave");
    addLevel(levelHead, "3: Ancient Forest");
    addLevel(levelHead, "4: Final Challenge");
    //displayLevels(levelHead);
    hero.addItem("Health Potion", 10);   // Add starting items to the hero’s inventory
    currentPlayer = &hero;               // Ensure the hero is the starting character
    locations = { "Dark Forest", "Abandoned Village", "Ancient Ruins", "Haunted Cave" }; // Define exploration locations
}
// load audio function-
void Game::loadAudio() {
    // Load background music
    if (!backgroundMusic.openFromFile("audio/background.wav")) {
        std::cerr << "Error loading background music\n";
    }

    // Load sound buffers
    if (!congratulationsBuffer.loadFromFile("audio/test.wav")) {
        std::cerr << "Error loading congratulations sound\n";
    }
    if (!explorationBuffer.loadFromFile("audio/exploration.wav")) {
        std::cerr << "Error loading exploration sound\n";
    }
    if (!combatBuffer.loadFromFile("audio/combat.wav")) {
        std::cerr << "Error loading combat sound\n";
    }
    if (!itemBuffer.loadFromFile("audio/item.wav")) {
        std::cerr << "Error loading item sound\n";
    }

    // Set sound buffers
    congratulationsSound.setBuffer(congratulationsBuffer);
    explorationSound.setBuffer(explorationBuffer);
    combatSound.setBuffer(combatBuffer);
    itemSound.setBuffer(itemBuffer);

    // Set loop for background music
    backgroundMusic.setLoop(true);
}

// Display the game's storyline and objectives to the player.
void Game::displayStoryline() {
    std::cout << "Hello Soldier!!\n\nWelcome to The Haunted Forest Adventure, the world of shadows and mystery...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Pause for dramatic effect
    std::cout << "You find yourself in a dark, uncharted forest, shrouded in an eerie fog that seems to move with a life of its own.\nThe air is heavy, carrying whispers of the unknown, and the faint glow of the moon barely pierces the canopy above.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "This forest is no ordinary place. Legends speak of those who entered seeking treasures and secrets but never returned.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Your goal is clear: survive the horrors that lie ahead and uncover the truth behind this haunted domain. \nBut beware—the deeper you go, the stronger the presence of an ancient evil becomes. \nThe forest has guardians—powerful entities bound to protect its secrets at any cost. Their eyes watch you from the \nshadows, and their whispers echo in your ears, urging you to turn back while you still can.\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "There are four levels to this treacherous journey, each more dangerous than the last:\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "\tThe first is the 'Enchanted Meadow' - deceptively calm and serene, but hiding its own perils.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\tBeyond that lies the 'Dark Cave,' where darkness reigns, and every sound feels like a predator closing in.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\tFurther still is the 'Ancient Forest,' a place of forgotten magic and unspeakable horrors. \n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\tAnd at the very end of your journey, the 'Final Challenge' awaits—a realm where the true master of \n\tthis cursed land resides, guarding the forest's ultimate secret.\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "You must rely on your wits, your weapons, and your instincts to navigate this nightmare. Along the way, \nyou may find tools and treasures to aid you, but use them wisely, as they could mean the difference between life and death. Remember, not everything in the forest is what it seems. Stay vigilant, for \ntraps and deceptions await the careless.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "The forest is alive, watching, waiting... and now it knows you are here. Time is of the essence. Steel \nyourself, adventurer. The road ahead is fraught with danger, but glory and answers await those brave enough to face the darkness. Good luck, and may the light guide you in this realm of shadows...\n\n";
}


// Main game loop: Continuously process player actions until the game ends.
void Game::playGame() {
    bool gameRunning = true;             // Control variable for the game loop
    while (gameRunning) {
        showMenu();                      // Display the main menu
        int choice;
        std::cin >> choice;              // Get player's choice

        // Process player input and execute corresponding actions
        switch (choice) {
        case 1:
            std::cout << "\n" << *currentPlayer << std::endl; // Show current player status
            break;
        case 2:
            showCurrentPlayerInventory(); // Show player's inventory
            break;
        case 3:
            move();                       // Navigate through paths
            break;
        case 4:
            switchCharacter();            // Switch between hero and warrior
            break;
        case 5:
            saveGame();                   // Save the current game state
            break;
        case 6:
            loadGame();                   // Load a previously saved game
            break;
        case 7:
            displayPathLog();             // Display the player's path history
            break;
        case 8:
            backtrack();                  // Backtrack to a previous path
            break;
        case 9:
            addCheckpoint(currentPath);   // Set a new checkpoint
            break;
        case 10:
            events.processEvent();        // Process the next event in the queue
            break;
        case 11:
            displayLevels(levelHead);     // Display all levels
            break;
        case 12:
            if (currentLevel)
                std::cout << "\nYou are currently at level: " << currentLevel->description << "\n";
            else
                std::cout << "\nYou are at the starting point.\n";
            break;
        case 0:
            gameRunning = false;          // Exit the game loop
            std::cout << "\nExiting game. Goodbye!\n";
            break;
        default:
            std::cout << "\nInvalid choice. Please try again.\n";
            break;
        }
    }
}

// Handle player movement along the paths in the binary tree.
void Game::move() {
    if (!currentPath)
        currentPath = forestPaths.getRoot(); // Start at the root if no path is active

    pathsExplored++; // Increment the explored path count
    std::cout << "\nPath #" << pathsExplored << " - You are at: " << currentPath->name << "\n";

    visitedPaths[currentPath->name] = true; // Mark the path as visited
    pathLog.push_back(currentPath->name);  // Log the current path
    previousPaths.push(currentPath);       // Add the current path to the backtracking stack

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for immersion

    // Guarantee Hermit on specific paths
    if (currentPath->name == "Misty Meadow" || currentPath->name == "Hidden Brook") {
        interactWithNPC();
    }
    else {
        advanceLevel(); // Check if the player advances to a new level
    }

    // Random event: Monster encounter
    if (std::rand() % 100 < 50) { // 50% chance of encountering a monster
        encounterEnemy();
    }
    else {
        std::cout << "The path is quiet... but something feels off.\n";
    }

    // Display available path options to the player
    std::cout << "\nChoose a path:\n";
    if (currentPath->left)
        std::cout << "1. " << currentPath->left->name << "\n";
    if (currentPath->right)
        std::cout << "2. " << currentPath->right->name << "\n";

    int choice;
    std::cout << "\nEnter choice (1 or 2, or 0 to backtrack): ";
    std::cin >> choice;

    // Update the current path based on the player's choice
    if (choice == 1 && currentPath->left) {
        currentPath = currentPath->left;
    }
    else if (choice == 2 && currentPath->right) {
        currentPath = currentPath->right;
    }
    else if (choice == 0) {
        backtrack(); // Backtrack to the previous path
    }
    else {
        std::cout << "\nInvalid choice. Try again.\n";
    }
}

// Advance to the next level if the player meets certain milestones.
void Game::advanceLevel() {
    if (!currentLevel) {
        // Initialize to the first level
        currentLevel = levelHead;
        if (currentLevel) {
            std::cout << "You have advanced to the first level: " << currentLevel->description << "!\n";
        }
        else {
            std::cerr << "Error: Level list is empty.\n";
        }
    }
    else if (currentLevel->next) {
        // Move to the next level
        currentLevel = currentLevel->next;
        std::cout << "You have advanced to a new level: " << currentLevel->description << "!\n";
    }
    else {
        // No more levels to advance to
        std::cout << "You have reached the final level: " << currentLevel->description << ".\n";
    }
}

// Respawn at the last checkpoint
void Game::respawnAtCheckpoint() {
    if (!checkpoints.empty()) {
        currentPath = checkpoints.top();
        currentPlayer->restoreHealth(100);
        std::cout << "Respawning at checkpoint: " << currentPath->name << "\n";
    }
}

// Backtrack functionality
void Game::backtrack() {
    if (previousPaths.empty()) {
        std::cout << "\nNo paths to backtrack to.\n";
        return;
    }

    previousPaths.pop();
    currentPath = previousPaths.empty() ? nullptr : previousPaths.top();
    if (currentPath)
        std::cout << "Backtracked to: " << currentPath->name << "\n";
    else
        std::cout << "You are back at the starting point.\n";
}

// Display the path log history
void Game::displayPathLog() const {
    if (pathLog.empty()) {
        std::cout << "You haven't moved yet.\n";
        return;
    }

    std::cout << "\n--- Path Log ---\n";

    for (const auto& path : pathLog) {
        std::cout << path << "\n";
    }
    std::cout << "-----------------\n";
}

// Add a new checkpoint to the stack of checkpoints
void Game::addCheckpoint(PathNode* checkpoint) {
    if (checkpoint) { // Check if the checkpoint is not null
        checkpoints.push(checkpoint); // Add the checkpoint to the stack
        std::cout << "Checkpoint set at: " << checkpoint->name << "\n"; // Notify the player
        displayCheckpoints();
    }
}

// Display all the checkpoints in the stack
void Game::displayCheckpoints() const {
    if (checkpoints.empty()) { // Check if there are no checkpoints
        std::cout << "No checkpoints set yet.\n"; // Notify the player
        return; // Exit the function
    }

    // Print a header for the checkpoint list
    std::cout << "\n--- Checkpoints ---\n";
    auto tempStack = checkpoints; // Create a copy of the stack to avoid modifying the original
    while (!tempStack.empty()) { // Loop until the temporary stack is empty
        std::cout << tempStack.top()->name << "\n"; // Print the name of the top checkpoint
        tempStack.pop(); // Remove the top checkpoint from the temporary stack
    }
    std::cout << "-----------------\n"; // Print a footer for the checkpoint list
}

// Retrieve the last checkpoint from the stack
PathNode* Game::getLastCheckpoint() const {
    return checkpoints.empty() ? nullptr : checkpoints.top(); // Return the top of the stack or null if empty
}

// Display the main menu for the game
void Game::showMenu() {
    std::cout << "\n--- Main Menu ---\n";
    std::cout << "1. Check Status\n";
    std::cout << "2. Show Inventory\n";
    std::cout << "3. Move (Explore Paths)\n";
    std::cout << "4. Switch Character\n";
    std::cout << "5. Save Game\n";
    std::cout << "6. Load Game\n";
    std::cout << "7. Display Path Log\n";
    std::cout << "8. Backtrack\n";
    std::cout << "9. Add Checkpoint\n";
    std::cout << "10. Process Event\n";
    std::cout << "11. Display Levels\n";
    std::cout << "12. Display Current Level\n";
    std::cout << "0. Exit Game\n";
    std::cout << "Enter your choice: ";
}

// NPC's dialogues and interaction
void Game::interactWithNPC() {
    std::cout << "\nAn old hermit appears...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "NPC: \"The forest is dangerous. Take this Health Potion to stay safe.\"\n";
    currentPlayer->addItem("Health Potion", 1);
    std::cout << "You received a Health Potion.\n";

    if (currentPath->name == "Hidden Brook") {
        std::cout << "The Hermit offers you advice: \"Beware the creatures in the Final Challenge.\"\n";
    }
    else if (currentPath->name == "Misty Meadow") {
        std::cout << "The Hermit smiles and says: \"Use your Shield wisely.\"\n";
    }
}

// Encounter and handle combat with an enemy
void Game::encounterEnemy() {
    combatSound.play();
    combatSound.setVolume(20);

    std::string enemyName;
    int enemyHealth;
    std::vector<std::string> itemPool; // Pool of items to drop based on enemy toughness

    // Determine the enemy based on the current level
    if (currentLevel && currentLevel->description == "1: Enchanted Meadow (easy)") {
        enemyName = "Forest Goblin";
        enemyHealth = 30;
        itemPool = { "Health Potion", "Small Shield" }; // Easy items
    }
    else if (currentLevel && currentLevel->description == "2: Dark Cave") {
        enemyName = "Cave Spider";
        enemyHealth = 60;
        itemPool = { "Knight Sword", "Iron Shield" }; // Medium items
    }
    else if (currentLevel && currentLevel->description == "3: Ancient Forest") {
        enemyName = "Dark Wraith";
        enemyHealth = 90;
        itemPool = { "Flaming Sword", "Longsword" }; // Hard items
    }
    else if (currentLevel && currentLevel->description == "4: Final Challenge") {
        enemyName = "Final Boss";
        enemyHealth = 120;
        itemPool = { "Excalibur", "Dragon Shield" }; // Final items
        std::cout << "You have reached the final stage. Prepare to face the Final Boss!\n";
    }
    else {
        enemyName = "Stray Beast"; // Default monster for undefined levels
        enemyHealth = 40;
        itemPool = { "Health Potion", "Basic Sword" };
    }

    // Create the enemy
    Enemy enemy(enemyName, enemyHealth);
    std::cout << "\nYou encounter a " << enemy.getName() << " with " << enemy.getHealth() << " health!\n";
    backgroundMusic.pause();

    bool inCombat = true;
    while (inCombat && currentPlayer->isAlive() && enemy.isAlive()) {
        // Combat Menu
        std::cout << "\n--- Combat Menu ---\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Defend\n";
        std::cout << "3. Use Item\n";
        std::cout << "4. Run\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: // Attack
            std::cout << currentPlayer->getName() << " attacks the " << enemy.getName() << "!\n";
            enemy.takeDamage(20);
            if (!enemy.isAlive()) {
                combatSound.stop();
                std::cout << "You defeated the " << enemy.getName() << "!\n";

                // Drop Item
                if (!itemPool.empty()) {
                    std::string droppedItem = itemPool[std::rand() % itemPool.size()];
                    currentPlayer->addItem(droppedItem, 1);
                    std::cout << "You picked up: " << droppedItem << "!\n";
                    itemSound.play();
                }

                // Advance Level
                advanceLevel();

                // Check for Final Boss Victory
                if (enemyName == "Final Boss") {
                    backgroundMusic.stop();
                    combatSound.stop();
                    congratulationsSound.play();
                    congratulationsSound.setVolume(10);
                    std::cout << "\nCongratulations, brave adventurer! You have defeated the Final Boss and completed the game.\n";
                    std::cout << "Thank you for playing. Your journey through the haunted forest will be remembered.\n";
                    std::this_thread::sleep_for(std::chrono::seconds(10));
                    //backgroundMusic.stop();
                    congratulationsSound.stop();
                    explorationSound.stop();
                    //combatSound.stop();
                    itemSound.stop();
                    exit(0); // End the game
                }
                inCombat = false;
            }
            break;

        case 2: // Defend
            std::cout << "Defending against the next attack!\n";
            break;

        case 3: // Use Item
            chooseItemFromInventory(enemy);
            break;

        case 4: // Run
            std::cout << "You attempt to flee...\n";
            if (std::rand() % 2 == 0) {
                std::cout << "Successfully escaped!\n";
                inCombat = false;
            }
            else {
                std::cout << "Failed to escape!\n";
            }
            break;

        default:
            std::cout << "Invalid choice!\n";
            break;
        }

        // Enemy attacks if still alive
        if (enemy.isAlive()) {
            std::cout << enemy.getName() << " attacks!\n";
            currentPlayer->takeDamage(10);
        }
    }

    // Handle Player Defeat
    if (!currentPlayer->isAlive()) {
        std::cout << "You have been defeated...\n";
        currentPath = checkpoints.top();
        currentPlayer->restoreHealth(100);
        std::cout << "Respawning at checkpoint: " << currentPath->name << "\n";
    }

    backgroundMusic.play();
}

// Display the inventory of the currently active player
void Game::showCurrentPlayerInventory() const {
    currentPlayer->showInventory(); // Call the showInventory method of the active player
}

// Allow the player to explore a random location
void Game::explore() {
    explorationSound.play();
    explorationSound.setVolume(50);

    // Choose a random location index from the list of locations
    int locationIndex = std::rand() % locations.size();
    std::string location = locations[locationIndex]; // Get the location name based on the random index

    // Notify the player about the current exploration
    std::cout << "\nYou are exploring the " << location << "...\n";

    // Add a delay for immersion to simulate exploration time
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Generate a random number to determine the type of event
    int eventChance = std::rand() % 100;
    if (eventChance < 50) { // 50% chance of encountering an enemy
        encounterEnemy();
    }
    else if (eventChance < 80) { // 30% chance of finding a hidden item
        events.enqueue("You found a hidden item: Magic Potion!");
        addItemToInventory("Magic Potion"); // Add the Magic Potion to the inventory
    }
    else { // 20% chance of nothing significant happening
        events.enqueue("The " + location + " is quiet... for now.");
    }

    events.dequeue(); // Process and display the triggered event
}

// Display the contents of the current player's inventory using an iterator
void Game::displayInventoryWithIterator() const {
    const Inventory& inv = currentPlayer->getInventory(); // Get the current player's inventory

    // Check if the inventory is empty
    if (inv.isEmpty()) {
        std::cout << "Inventory is empty.\n"; // Notify the user if no items are present
        return; // Exit the function
    }

    InventoryIterator it(inv); // Create an iterator to traverse the inventory
    int index = 1;             // Index for displaying item numbers

    // Loop through the inventory items using the iterator
    while (it.hasNext()) {
        auto item = it.currentItem(); // Get the current item (name and quantity)
        std::cout << index++ << ". " << item.first << " x" << item.second << "\n"; // Display the item
        it.next(); // Move to the next item in the inventory
    }
}

// adds an item to the current player's inventory
void Game::addItemToCurrentPlayerInventory(const std::string& item, int quantity) {
    currentPlayer->addItem(item, quantity);
    std::cout << "Added " << quantity << " " << item << "(s) to " << currentPlayer->getName() << "'s inventory.\n";
}

void Game::addItemToInventory(const std::string& item) {
    std::string description = getItemDescription(item);
    std::cout << "You found a " << item << " (" << description << ").\n";
    std::cout << "Add to inventory? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        currentPlayer->addItem(item, 1);
        itemSound.play();
        itemSound.setVolume(60);
        std::cout << item << " added to inventory.\n";
    }
    else {
        std::cout << item << " discarded.\n";
    }
}

// Allow the player to select and use an item from their inventory during combat
void Game::chooseItemFromInventory(Enemy& enemy) {
    const Inventory& inv = currentPlayer->getInventory(); // Get the current player's inventory
    if (inv.isEmpty()) { // Check if the inventory is empty
        std::cout << "Your inventory is empty. Returning to the main menu.\n";
        return; // Exit the function if no items are available
    }

    displayInventoryWithIterator(); // Display the inventory contents using an iterator

    // Prompt the player to select an item or cancel
    std::cout << "Enter the number of the item you want to use, or 0 to cancel: ";
    int itemNumber;
    std::cin >> itemNumber;

    if (itemNumber == 0) { // Handle cancelation
        std::cout << "Cancelled item selection.\n";
        return;
    }

    // Validate the player's input
    if (itemNumber < 1 || itemNumber > inv.getSize()) {
        std::cout << "Invalid choice. Please select a valid item number.\n";
        return; // Exit the function for invalid input
    }

    InventoryIterator it(inv); // Create an iterator to traverse the inventory
    int currentPosition = 1;  // Start at the first item
    while (it.hasNext() && currentPosition < itemNumber) {
        it.next(); // Move the iterator to the selected item's position
        currentPosition++;
    }

    // Get the selected item's name and quantity
    auto selectedItem = it.currentItem();
    std::string itemName = selectedItem.first;
    int itemQuantity = selectedItem.second; // Quantity of the selected item
    std::cout << "You selected: " << itemName << " x" << itemQuantity << "\n";

    // Perform an action based on the selected item's name
    if (itemName == "Sword") {
        // Use the Sword to attack, scaling damage with quantity
        int baseSwordDamage = 25; // Base damage per Sword
        int totalDamage = baseSwordDamage * itemQuantity; // Total damage
        std::cout << "Using " << itemQuantity << " Sword(s) to attack!\n";
        enemy.takeDamage(totalDamage); // Apply damage to the enemy
        std::cout << "You dealt " << totalDamage << " damage to " << enemy.getName() << "!\n";
        std::cout << enemy.getName() << "'s remaining health: " << enemy.getHealth() << "\n";
        if (enemy.getHealth() == 0) // Check if the enemy is defeated
            std::cout << "Well done!! You conquered " << enemy.getName() << std::endl;
    }
    else if (itemName == "Shield") {
        // Use the Shield to boost defense, scaling with quantity
        int baseDefenseBoost = 15; // Base defense boost per Shield
        int totalDefenseBoost = baseDefenseBoost * itemQuantity; // Total defense boost
        currentPlayer->defendWithWeapon("Shield", totalDefenseBoost); // Apply the defense boost
        std::cout << "Using " << itemQuantity << " Shield(s) to defend!\n";
        std::cout << "The Shield reduces incoming damage by " << totalDefenseBoost << " points!\n";
    }
    else if (itemName == "Health Potion") {
        // Use Health Potions to restore health, scaling with quantity
        int healAmount = 20 * itemQuantity; // Total health restored
        currentPlayer->restoreHealth(healAmount); // Restore the player's health
        std::cout << "You restored " << healAmount << " health.\n";
    }
    else {
        // Handle other item types (not explicitly defined in the function)
        std::cout << "Using " << selectedItem.first << "...\n";
    }

    // Reduce the quantity of the used item in the inventory by 1
    currentPlayer->getInventory().addItem(itemName, -1);
}

void Game::switchCharacter() {
    if (currentPlayer == &hero) {
        currentPlayer = &warrior;
        std::cout << "Switched to Warrior.\n";
    }
    else {
        currentPlayer = &hero;
        std::cout << "Switched to Hero.\n";
    }
}

// Retrieve the description of an item based on its name
std::string Game::getItemDescription(const std::string& item) {
    // Static unordered map containing item names as keys and their descriptions as values
    static std::unordered_map<std::string, std::string> descriptions = {
        {"Magic Potion", "Restores significant health."},  // Description for Magic Potion
        {"Health Potion", "Restores small health."},       // Description for Health Potion
        {"Sword", "Increases attack."},                    // Description for Sword
        {"Shield", "Reduces damage when defending."},       // Description for Shield
        {"Flashlight", "Helps in dark areas."},            // Description for Flashlight
    };

    // Return the description for the given item name
    // If the item does not exist in the map, a string is returned
    return descriptions.count(item) ? descriptions[item] : "Item description not available.";
}

// Save the current game state to a file
void Game::saveGame() {
    std::ofstream saveFile("savegame.txt"); // Open a file for writing
    if (saveFile.is_open()) { // Check if the file was successfully opened
        // Save the hero's name and health
        saveFile << hero.getName() << "\n" << hero.getHealth() << "\n";

        // Save the size of the hero's inventory
        saveFile << hero.getInventory().getSize() << "\n";

        // Iterate through the hero's inventory and save each item's name and quantity
        InventoryIterator it(hero.getInventory());
        while (it.hasNext()) {
            auto item = it.currentItem(); // Get the current inventory item
            saveFile << item.first << " " << item.second << "\n"; // Write item name and quantity
            it.next(); // Move to the next item in the inventory
        }

        saveFile.close(); // Close the file after saving
        std::cout << "Game progress saved!\n"; // Notify the user of a successful save
    }
    else {
        // Notify the user if the file could not be opened
        std::cout << "Failed to save the game.\n";
    }
}

// Load a previously saved game state from a file
void Game::loadGame() {
    std::ifstream loadFile("savegame.txt"); // Open the file for reading
    if (loadFile.is_open()) { // Check if the file was successfully opened
        std::string name; // Variable to hold the hero's name
        int health;       // Variable to hold the hero's health
        loadFile >> name >> health; // Read the hero's name and health from the file

        hero = Player(name, health); // Reinitialize the hero with the loaded name and health

        int invSize; // Variable to hold the size of the inventory
        loadFile >> invSize; // Read the inventory size from the file

        // Loop to read each inventory item and its quantity
        for (int i = 0; i < invSize; ++i) {
            std::string itemName; // Variable to hold the item's name
            int quantity;         // Variable to hold the item's quantity
            loadFile >> itemName >> quantity; // Read the item's name and quantity from the file
            hero.addItem(itemName, quantity); // Add the item to the hero's inventory
        }

        loadFile.close(); // Close the file after loading
        std::cout << "Game loaded successfully!\n"; // Notify the user of a successful load
    }
    else {
        // Notify the user if the file could not be opened
        std::cout << "Failed to load the game.\n";
    }
}

Game::~Game() {
    pathLog.clear(); // Clear any list that may contain paths or strings
    previousPaths = std::stack<PathNode*>(); // Empty the stack
    upcomingPaths = std::queue<PathNode*>(); // Empty the queue

    backgroundMusic.stop();
    congratulationsSound.stop();
    explorationSound.stop();
    combatSound.stop();
    itemSound.stop();
}