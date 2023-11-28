# Variables and Types

A variable is a portion of memory to store a value. Each variable needs a name that identifies it and distinguishes it from the other

## Identifiers

- A valid identifier is a sequence of one or more letters, digits or underscore characters(_)
- Identifiers shall always begin with a letter or an underscore, but such identifiers are - on most cases - considered reserved for compiler-specific keywords
- To Note: C++ is a case-sensitive language.

## Declaring Variables

- C++ requires every variable to be declared with its type before its first use.

```cpp
// operating with variables

#include <iostream>
using namespace std;

int main() {
    // declare variables
    int a, b;
    int result;

    // process
    a = 5;
    b = 2;
    a = a + 1;
    result = a - b;

    // print out result
    cout << result;

    // terminate program
    return 0;
}
```

## Initialization of variables

- When variables are declared, they have an undetermined value until they are assigned a value for the first time.
- A variable can have a specific value from the moment it is declared. This is called initializing.

```cpp
/* c-like initialization
 type identifier = initial_value; */
int x = 0;

/* constructor initialization
type identifier (initial_value); */
int y (0);

/*uniform initialization
type identifier {initial_value}; */
int z {0};
```

## Type deduction

```cpp
int foo = 0;
auto bar = foo; // the same as: int bar = foo;

int foo = 0;
decltype(foo) bar; // the same as: int bar;
```

- auto and decltype improve code readability.

## Introduction to strings

- string class is an example of a compound type that is able to store sequences of characters, such as words or sentences.
- the first difference with fundamental data types is that in order to declare and use objects (variables) of this type, the program needs to include the header where the type is defined within the standard library (header ```<string>```)

```cpp
// my first string
#include <iostream>
#include <string>
using namespace std;

int main(){
    string mystring;
    mystring = "This is a string";
    cout << mystring;
    return 0;
}
```
