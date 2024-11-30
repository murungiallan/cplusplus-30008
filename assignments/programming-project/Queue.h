#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <string>

// Represents a queue for managing in-game events.
class Queue {
private:
    std::queue<std::string> eventQueue; // Queue to store events

public:
    void enqueue(const std::string& event); // Add an event to the queue
    void processEvent();                    // Display and remove the first event
    void dequeue() { processEvent(); }      // Alias for processEvent
};

#endif
