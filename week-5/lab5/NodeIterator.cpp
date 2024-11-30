#include <iostream>
#include "NodeIterator.h"

NodeIterator::NodeIterator(Node* startNode) : current(startNode) {}

int& NodeIterator::operator*() {
	return current->value;
}

NodeIterator& NodeIterator::operator++() {
	current = current->next;
	return *this;
}

bool NodeIterator::operator!=(const NodeIterator& other) const {
	return current != other.current;
}

bool NodeIterator::operator==(const NodeIterator& other) const {
	return current == other.current;
}

NodeIterator NodeIterator::end() const {
	return NodeIterator((Node*)0);
}