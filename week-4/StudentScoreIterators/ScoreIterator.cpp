#include "ScoreIterator.h"

ScoreIterator::ScoreIterator(int* p) : ptr(p) {}

/*
 * Overloading the behaviour of the operators.
*/

// Acting as deferencing
int& ScoreIterator::operator*() {
    return *ptr;
}

// Prefix increment
ScoreIterator& ScoreIterator::operator++() {
    ++ptr;
    return *this;
}

// Postfix increment
ScoreIterator ScoreIterator::operator++(int) {
    ScoreIterator temp = *this;
    ++ptr;
    return temp;
}

// Equality
bool ScoreIterator::operator==(const ScoreIterator& other) const {
    return ptr == other.ptr;
}

// Inequality
bool ScoreIterator::operator!=(const ScoreIterator& other) const {
    return ptr != other.ptr;
}
