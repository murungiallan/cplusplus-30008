#pragma once
#include "Node.h"

class NodeIterator {
private:
	Node* current;

public:
	NodeIterator(Node* startNode);
	int& operator*();

	NodeIterator& operator++();

	bool operator!=(const NodeIterator& other) const;
	bool operator==(const NodeIterator& other) const;
	NodeIterator end() const;
};