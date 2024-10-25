// INSTANTIATING ON THE STACK VS THE HEAP
#include <iostream>

using namespace std;

int main(){
    int SomeNumber = 100;
    cout << "This is the Int on the Stack: " << SomeNumber << endl;

    // Works with pointers too
    // The 'Int' block must be released from memory after use
    int *ptr = new int();
    *ptr = 100;

    cout << "This Int is dereferenced from Pointer: " << *ptr << endl;
    delete ptr;

    return 0;
}