#include "Queue.h"
#include <iostream>

// Add an event to the queue.
void Queue::enqueue(const std::string& event) {
    eventQueue.push(event);
}

// Process and display the first event in the queue.
void Queue::processEvent() {
    if (!eventQueue.empty()) {
        std::cout << "Event: " << eventQueue.front() << "\n";
        eventQueue.pop();
    }
    else {
        std::cout << "No more events to process.\n";
    }
}
