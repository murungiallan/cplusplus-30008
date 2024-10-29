#include "Student.h"

// Default constructors (everything set to 0)
Student::Student() : name(""), age(0), numScores(0) {
    for (int i = 0; i < 5; i++) {
        scores[i] = 0;
    }
}

// Parameterized constructor (accepting a list of scores)
Student::Student(const std::string& n, int a, const int s[], int size) : name(n), age(a), numScores(size) {
    for (int i = 0; i < size; ++i) {
        scores[i] = s[i];
    }
}

// Getter methods
std::string Student::getName() const { return name; }

int Student::getAge() const { return age; }

int* Student::getScores() { return scores; }

int Student::getNumScores() const { return numScores; }

// Find the start of the containers.
ScoreIterator Student::begin() { return ScoreIterator(scores); }

// Find past-the-end of the container.
ScoreIterator Student::end() { return ScoreIterator(scores + numScores); }
