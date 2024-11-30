#pragma once

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

template<class T>
class List
{
private:
    typedef DoublyLinkedNode<T> Node;
    Node* last;  // Only keeping track of the last node
    Node* first; // keeping track of the first node on the list
    int count;

public:
    typedef DoublyLinkedNodeIterator<T> Iterator;

    List() : last(&(Node::NIL)), count(0) {}
    List(Node* lastNode) : last(lastNode), count(1) {}

    ~List()
    {
        Iterator it = getIterator();
        while (it != it.end())
        {
            Node* toDelete = it.getCurrent();
            ++it;
            toDelete->remove();
        }
    }

    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (first != &(Node::NIL)) {
            first->prepend(newNode);
        }
        first = newNode;
        ++count;
    }

    void pushBack(const T& value)
    {
        Node* newNode = new Node(value);
        if (last != &(Node::NIL))
        {
            last->append(newNode);
        }
        last = newNode;
        ++count;
    }

    const T popFront()
    {
        T savedValue;
        if (first != &(Node::NIL))
        {
            Node* toDelete = first;
            first = first->getPrevious();

            if (first == &(Node::NIL))
            {
                last = &(Node::NIL);
            }
            savedValue = toDelete->getValue();
            toDelete->remove();
            --count;
        }
        return savedValue;
    }

    const T popBack()
    {
        T savedValue;
        if (last != &(Node::NIL))
        {
            Node* toDelete = last;
            last = last->getPrevious();

            if (last == &(Node::NIL))
            {
                first = &(Node::NIL);
            }
            savedValue = toDelete->getValue();
            toDelete->remove();
            --count;
        }
        return savedValue;
    }

    // Helper Functions
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    Iterator getIterator() const { return Iterator(last); }
};