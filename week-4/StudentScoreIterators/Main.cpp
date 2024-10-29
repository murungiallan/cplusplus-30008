#include <iostream>
#include "Student.h"

int main() {
    // Creating scores arrays, intended for 2 different students
    int scores1[] = { 90, 85, 88, 80, 82 };
    int scores2[] = { 78, 92, 87, 85, 89 };

    /*
     * Creating the students on the Stack.
     * Take note of how the arrays are passed to the constructors.
    */
    Student s1("John", 20, scores1, 5);
    Student s2("Jane", 21, scores2, 5);

    /*
     * Creating an array of custom data types (Student objects).
    */
    Student students[] = { s1, s2 };

    /*
     * Iterating through the students.
     * Do you see how we use the "auto" keyword in C++ to auto-detect the data types?
     * Also, note that the students are accessed by reference.
    */
    for (auto& student : students) {
        std::cout << "Name: " << student.getName()
            << "\nAge: " << student.getAge()
            << "\nScores: ";
        /*
         * Iterating through each student's scores using the forward iterator.
         * Note the overloaded behaviour of the !=, ++, and * operators.
        */
        for (ScoreIterator it = student.begin(); it != student.end(); ++it) {
            std::cout << *it << " ";
        }
        // Separate each student details with an empty line.
        std::cout << "\n" << std::endl;
    }

    return 0;
}
