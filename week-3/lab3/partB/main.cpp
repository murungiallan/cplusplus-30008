#include <iostream>
using namespace std;

int main(){
    int* ptr; // create a pointer of type int
    int aNumber = -99; // create a variable aNumber of type int that stores a value -99

    cout << "aNumber: " << aNumber << endl; // print the variable aNumber

    ptr = &aNumber; // assign the pointer ptr to the actual value of aNumber and not a copy
    cout << "*ptr: " << *ptr << endl; // print where ptr points to, that is aNumber


    int fArray[10] = {1,2,3,4,5,6,7,8,9,10}; // create an array fArray of type int with an initialized capacity of 10 values

    cout << "fArray[9]: " << fArray[9] << endl;

    ptr = fArray;

    cout << "ptr[1]: " << ptr[1] << endl;

    return 0; // exit
}