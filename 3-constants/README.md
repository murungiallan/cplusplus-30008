# Constants

- Constants are expressions with a fixed value

## Literals

- The most obvious kind of constants. Can be classified into integer, floating-point, characters, strings, Boolean, pointers, and user-defined literals.

```cpp
a = 5;
// 5 is considered as a literal constant
```

### Integer Numerals

- In addition to decimal numbers, C++ allows the use of octal numbers (base 8) and hexadecimal numbers (base 16) as literal constants.

```cpp
45 // decimal
0113 // octal - preceded with a 0
0x4b // hexadecimal - preceded by 0x
```

### Floating Point Numerals

- Can include either a decimal point, an e character (”by ten at the Xth height”), or both a decimal point and an e character.

```cpp
3.14159 // 3.14159
6.02e23 // 6.02 * 10^23
1.6e-19 // 1.6 * 10^-19
```

- The default type for floating-point literals is double. Floating-point literals of type ‘float’ or ‘long double’ can be specified by adding one of the following suffixes.

```cpp
3.14159L // long double
6.02e23f // float
```

- To Note: Any of the letters that can be part of a floating-point numerical constant (e, f, l) can be written using either lower or uppercase letters with no difference in meaning

### Character and string literals

- Character and string literals are enclosed in quotes.

```cpp
'z'; // single-character literal
"Hello World" // string literal
```

- They can also represent special characters known as escape codes. These special characters are preceded by a backslash character (\)

```cpp
/* A List Of the Single Character Escape Codes */

\n // newline
\r // carriage return
\t // tab
\v // vertical tab
\b // backspace
\f // form feed (page feed)
\a // alert (beep)
\' // single quote
\" // double quote
\? // question mark
\\ // backslash
```

- Some programmers use a trick to include long string literals in multiple lines: A backslash (\) at the end of the line is considered a line-continuation character that merges both that line and the next into a single line.

```cpp
x = "string expressed in \
two lines"
// same as:
x = "string expresses in two lines"
```

### Other Literals

- Three keyword literals exist in C++: true, false and nullptr
- true and false are the two possible values for variables of type bool
- nullptr is the null pointer value

```cpp
bool foo = true;
bool bar = false;
int* p = nullptr;
```

### Typed constant expressions

- It may be convenient to give a name to a constant value and use it instead of the literals they were defined to:

```cpp
// Typed constant expressions
#include <iostream>
using namespace std;

const double pi = 3.14159;
const char newline = '\n';

int main() {
    double r = 5.0;
    double circle;

    circle = 2 * pi * r;
    cout << circle;
    cout << newline;
}
```

### Preprocessor definitions (#define)

‘#define identifier replacement’

```cpp
#include <iostream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main ()
{
    double r=5.0;               // radius
    double circle;

    circle = 2 * PI * r;
    cout << circle;
    cout << NEWLINE;

}
```

- Since #define lines are preprocessor directives, they do not require semicolons at the end as the directive extends automatically until the end of the line.