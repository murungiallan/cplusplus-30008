#include <iostream>

using namespace std;

void printArray(int* Arr, int size){
    for (int i = 0; i < size; i++){
        cout << Arr[i] << endl;
    }
}

int main(){

    // create a pointer and an aNumber of types int
    int* ptr;
    int aNumber = -99;

    // assign the pointer to aNumber's real value, and pass it into printArray with a size 1
    ptr = &aNumber;
    printArray(ptr, 1);

    // create a fArray of size 10, initialize it and assign pointer ptr to it. Then pass in the pointer with the size 10 to printArray
    int fArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    ptr = fArray;
    printArray(ptr, 10);

    return 0;
}