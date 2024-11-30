#include "Game.h"

// Entry point of the application.
int main() {

    Game game;             // Create a Game object
    game.initializeGame(); // Initialize the game environment and settings
    game.playGame();       // Start the main gameplay loop
    return 0;              // Exit the program
}