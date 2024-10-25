#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Iterator2D {
private:
    int row, col;
    vector<vector<string>>* array2D;
    int rowCount, colCount;

public:
    Iterator2D(vector<vector<string>>& array2D) {
        this->array2D = &array2D;
        this->row = 0;
        this->col = 0;
        this->rowCount = array2D.size();
        this->colCount = array2D.empty() ? 0 : array2D[0].size();
    }

    Iterator2D& operator++() {
        if (col < colCount - 1) {
            col++;
        }
        else if (row < rowCount - 1) {
            row++;
            col = 0;
        }
        return *this;
    }

    Iterator2D& operator--() {
        if (col > 0) {
            col--;
        }
        else if (row > 0) {
            row--;
            col = colCount - 1;
        }
        return *this;
    }

    string operator*() const {
        return (*array2D)[row][col];
    }

    friend ostream& operator<<(ostream& aOstream, const Iterator2D& it) {
        if (it.row >= 0 && it.row < it.rowCount && it.col >= 0 && it.col < it.colCount) {
            aOstream << "Bag is at index [" << it.row << "][" << it.col << "]: " << (*it.array2D)[it.row][it.col];
        }
        else {
            aOstream << "out of bounds";
        }
        return aOstream;
    }
};