#include "Character.h"
#include <iostream>

int main() {
    Character thePlayer("Allan");  // Create a character named Allan

    // Add skills to the character
    thePlayer.addSkill("Intimidation", 3);
    thePlayer.addSkill("Persuasion", 5);

    // Display all skills of the character
    thePlayer.displayCharacterInfo();

    // Test skill removal
    thePlayer.removeSkill("Intimidation");
    thePlayer.displayCharacterInfo();

    return 0;
}
