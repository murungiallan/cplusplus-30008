#include <iostream> // pre-processor directive. Used to include header files with specific methods and elements
using namespace std; // used to set the namespace as standard for users to apply all standard methods in programs

string func(int n) {
	// returns if n is odd or even
	if (n % 2) {
		return "Given number is odd!";
	}
	else {
		return "Given number is even!";
	}
}

/*
class TutorialsPoint {
public:
	string tutorialspoint;

	void print() {
		cout << tutorialspoint << endl;
	}
};
*/

/*
struct TP {
	string tp;
	int grade;
};
*/

/*
union TP {
	int tp1, tp2;
};
*/

enum TP {
	C, Java, Python, Ruby, Kotlin, JavaScript, TypeScript, Others
};

int main() {
	enum TP course;
	cout << "Which course do you love the most? " << endl;

	course = Kotlin;
	cout << "I love the " << course + 1 << "th course!!";

	/*
	union TP t;
	t.tp1 = 2;
	cout << "The value of tp1 initially: " << t.tp1 << endl;

	t.tp2 = 4;
	cout << "When we change tp2, the value of tp1 becomes: " << t.tp1 << endl;
	*/

	/*
	TP object;
	object.tp = "I love tutorialspoint!";
	object.grade = 10;

	cout << object.tp << endl;
	cout << "How much would you rate it? : " << object.grade << endl;
	*/

	/*
	TutorialsPoint object;

	object.tutorialspoint = "I love tutorialspoint!";
	object.print();
	*/

	/*
	int c = 11;
	int& refer = c;

	cout << "Initially value of c is: " << c << endl;
	refer = 12;
	cout << "The changed value of c is: " << c << endl;
	*/

	/*
	int a = 20;
	int *p = &a; // assign pointer to a

	cout << "Address of variable a: " << p << endl;
	cout << "Value of variable a: " << *p << endl;
	*/

	/*
	int arr[5] = { 1,2,3,4,5 };

	for (auto it : arr) {
		cout << it << " ";
	}
	*/

	/*
	int a;
	cout << "Enter a number: ";
	cin >> a;
	cout << func(a);
	*/


	/*
	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of long int: " << sizeof(long int) << endl;
	cout << "Size of short int: " << sizeof(short int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;
	cout << "Size of double: " << sizeof(double) << endl;
	cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;

	// << passes multiple values out to the screen
	// endl inserts a new character after every line
	*/
	return 0;
}

// Pre-defined Data Types

/*
1. Function
---------------------

A function includes a return type, a function name and input parameters

return_type function_name(input_param1, input_param2){
	<function_body>
}
*/

/*
2. Array
----------------

An array is a series of elements of same data type

data_type array_name[array_size];
*/

/*
3. Pointer
-----------------

A pointer is a reference to an element defined previously. The value of the pointer returns the address location of the element which is associated with it

data_type *pointer_name = & variable_name

*/

/*
4. Reference variable
----------------------

A reference variable is used to create a copy of a variable with the same reference. Hence, changes made to the reference variable also reflect on the original variable

data_type& reference_name = variable_name;
*/

// User-defined Data Types
/*
1. Class
-----------

Defined in OOP as a custom data type which is used to construct an object. It is the framework of an object, and it can include constructors, methods and OOP concepts such as Polymorphism, Inheritance etc.

class Class_name {
	<class_body>

	class_name(parameters){
		<constructor_body>
	}

	return_type method_name(parameters){
		<method_body>
	}
}
*/

/*
2. Struct
------------------

In struct data type, the user can introduce multiple primitive data types inside the struct body

struct struct_name{
	data_type1 var_name1;
	data_type2 var_name2;
	...
}
*/

/*
3. Union
-------------

Union is similar to a structure. In this, the memory location of all variables is the same, and all variables share the same reference. Hence, a change in one value means a change in all the other values.

union union_name {
	data_type var_name1;
	data_type var_name2;
};
*/

/*
4. Enumeration (enum)
----------------------

Enumeration is a user-defined data type that is used to give name to integer constants in a program. This increases the user-readability of the program

enum enum_name{
	var_name1, var_2 ....
}
*/