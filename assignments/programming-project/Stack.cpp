#include "Stack.h"

// Add a new checkpoint to the stack.
void Stack::addCheckpoint(const std::string& checkpoint) {
    checkpoints.push(checkpoint); // Push the checkpoint string onto the stack
}

// Remove the most recent checkpoint from the stack.
void Stack::removeCheckpoint() {
    if (!checkpoints.empty()) // Check if the stack is not empty
        checkpoints.pop();    // Remove the top checkpoint from the stack
}

// Get the current (most recent) checkpoint without removing it.
std::string Stack::currentCheckpoint() const {
    return checkpoints.empty() ? "No checkpoints available" : checkpoints.top();
    // If the stack is empty, return a message indicating no checkpoints
    // Otherwise, return the checkpoint at the top of the stack
}