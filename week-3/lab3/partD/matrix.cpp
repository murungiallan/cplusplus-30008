#include "Matrix.h"
#include <iostream>
using namespace std;

// Constructor
Matrix::Matrix() : arr1D(nullptr), arr2D(nullptr), size1D(0), rows2D(0), cols2D(0) {}

// Initialize 1D Array
void Matrix::init1DArray(int size) {
    size1D = size;
    arr1D = new int[size1D];
    for (int i = 0; i < size1D; ++i) {
        arr1D[i] = 0; // Initializing elements to 0
    }
}

// Initialize 2D Array
void Matrix::init2DArray(int rows, int cols) {
    rows2D = rows;
    cols2D = cols;
    arr2D = new int* [rows2D];
    for (int i = 0; i < rows2D; ++i) {
        arr2D[i] = new int[cols2D];
        for (int j = 0; j < cols2D; ++j) {
            arr2D[i][j] = 0; // Initialize each element to 0
        }
    }
}

// Set value in 1D array
void Matrix::set1DValue(int index, int value) {
    if (index >= 0 && index < size1D) {
        arr1D[index] = value;
    }
    else {
        cerr << "Index out of bounds for 1D array." << endl;
    }
}

// Set value in 2D array
void Matrix::set2DValue(int row, int col, int value) {
    if (row >= 0 && row < rows2D && col >= 0 && col < cols2D) {
        arr2D[row][col] = value;
    }
    else {
        cerr << "Index out of bounds for 2D array." << endl;
    }
}

// Print 1D array
void Matrix::print1DArray() {
    if (arr1D != nullptr) {
        for (int i = 0; i < size1D; ++i) {
            cout << arr1D[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "1D array not initialized." << endl;
    }
}

// Print 2D array
void Matrix::print2DArray() {
    if (arr2D != nullptr) {
        for (int i = 0; i < rows2D; ++i) {
            for (int j = 0; j < cols2D; ++j) {
                cout << arr2D[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "2D array not initialized." << endl;
    }
}

// Get size of 1D array
const int Matrix::get1DSize() const {
    return size1D;
}

// Get row count of 2D array
const int Matrix::get2DRows() const {
    return rows2D;
}

// Get column count of 2D array
const int Matrix::get2DColumns() const {
    return cols2D;
}

// Destructor to free dynamically allocated memory
Matrix::~Matrix() {
    if (arr1D != nullptr) {
        delete[] arr1D;
    }

    if (arr2D != nullptr) {
        for (int i = 0; i < rows2D; i++) {
            delete[] arr2D[i];
        }
        delete[] arr2D;
    }
}