#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "ScoreIterator.h" // Include the new header

class Student {
private:
    std::string name;
    int age;
    int scores[5]; // assuming a fixed size of 5 for simplicity
    int numScores;

public:
    // Constructors (default and parameterized)
    Student();
    Student(const std::string& n, int a, const int s[], int size);

    // Member functions to access private data (getters)
    std::string getName() const;
    int getAge() const;
    int* getScores();
    int getNumScores() const;

    // Functions to get iterators for scores
    ScoreIterator begin();
    ScoreIterator end();
};

#endif // STUDENT_H

