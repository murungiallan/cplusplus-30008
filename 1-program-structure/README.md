# Structure of a Program

## What is C++

- General-purpose programming language created by Bjarne Stroustrup as an extension of C.
- Provides OOP features such as classes and inheritance.
- Widely used in various applications such as game development, system programming, embedded systems and high-perf computing
- Statically typed language
- Has an extensive library called the C++ Standard Library which provides a rich set of functions, algorithms and data structures.
- Most C programs can be compiled and run with a C++ compiler

## Why C++?

- High performance and efficiency
- Allows you to write portable code that runs on various platforms without making major modifications
- Allows you to design programs using classes and objects, leading to better code organization and reusability
- Supports both low-level (memory manipulation) and high-level (STL library and OOP)
- Extensive libraries e.g., Standard Template Library, Boost and Qt
- Can be combined with C
- Has an active community of users

## First Program in C++

### Hello, World

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

- ‘#include <iostream>’ is a preprocessor directive that tells the compiler to include the header file ‘iostream’. Header files provide function and class declarations.
- ‘main()’ function serves as an entry point to your program and should only be called once. IT MUST RETURN AN INTEGER.
- To output text, we use the ‘std::cout’ (standard character output) object and the insertion operator. ‘std::endl’ inserts a newline character and flushes the output buffer
- return 0; informs the OS that the program executed successfully.

## Comments

- Comments provide an important tool to document directly within the source code what the program does and how it operates
- A line comment is a one-liner while a block comment may include multiple lines

```cpp
// line comment
/* block comment */
```

## Using namespace std

- cout is part of the standard library, and all the elements in the standard C++ library are declared within a namespace.

```cpp
using namespace std;

// ...
cout << "Hello, world!";
```
