#include <iostream>
#include "Matrix.h"

using namespace std;

int main(){
    // Create a Matrix Object on the Stack
    Matrix container;
    // Initializing and setting values for the 1D array (size 5)
    container.init1DArray(5);

    for (int i = 0; i < container.get1DSize(); i++){
        container.set1DValue(i, i + 1);
    }
    cout << "Printing the 1D array's values:\n" << endl;
    container.print1DArray();

    // Initializing and setting values for 2D array (4x3 size)
    container.init2DArray(4, 3);

    int value = 1;

    for (int i = 0; i < container.get2DRows(); i++) {
        for (int j = 0; j < container.get2DColumns(); j++) {
            container.set2DValue(i, j, value++);
        }
    }
    cout << "\nPrinting the 2D array's values:\n" << endl;
    container.print2DArray();

    return 0;
}