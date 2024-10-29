#ifndef SCORE_ITERATOR_H
#define SCORE_ITERATOR_H

class ScoreIterator {
private:
    int* ptr;
public:
    ScoreIterator(int* p);

    // Dereference operator
    int& operator*();

    // Increment operators
    ScoreIterator& operator++(); // prefix ++
    ScoreIterator operator++(int); // postfix ++

    // Comparison operators
    bool operator==(const ScoreIterator& other) const;
    bool operator!=(const ScoreIterator& other) const;
};

#endif // SCORE_ITERATOR_H
