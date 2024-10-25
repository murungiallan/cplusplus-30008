#pragma once
#include <iostream>

class Matrix {
    private:
        int* arr1D ; // a 1D array requires a single pointer
        int** arr2D; // a 2D array requires a double pointer
        int size1D; // size of the 1D array
        int rows2D; // row size for the 2D array
        int cols2D; // column size for the 2D array

    public:
        Matrix(); // initial constructor

        // Initializing the 1D array
        void init1DArray(int size);

        // Initializing the 2D array
        void init2DArray(int rows, int cols);

        // Set values for 1D array
        void set1DValue(int index, int value);

        // Set values for 2D array
        void set2DValue(int row, int col, int value);

        // Print 1D array
        void print1DArray();

        // print 2D array
        void print2DArray();

        // Getters (only return values without modifying)
        const int get1DSize() const;
        const int get2DRows() const;
        const int get2DColumns() const;

        // Destructor to free dynamically allocated memory
        ~Matrix();

};