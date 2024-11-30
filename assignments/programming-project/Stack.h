#ifndef STACK_H
#define STACK_H

#include <stack>
#include <string>

// Wrapper class for managing a stack of checkpoints.
class Stack {
private:
    std::stack<std::string> checkpoints; // Stack to store checkpoint strings

public:
    void addCheckpoint(const std::string& checkpoint); // Add a checkpoint to the stack
    void removeCheckpoint();                           // Remove the most recent checkpoint
    std::string currentCheckpoint() const;             // Get the current checkpoint
};

#endif