// bool data type
/*
#include <iostream>
using namespace std;

int main() {
	bool flag;
	flag = 1; // true
	cout << flag << endl;
	bool flag1 = true;
	cout << flag << " " << flag1 << endl;

	int count = 0;
	while (flag) {
		count++;
		if (count >= 3) flag = false;
	}

	cout << count << " " << flag << endl;

	if (flag1) cout << "True flag1" << endl;
	else cout << "False flag1" << endl;

	return 0;

	/*
	Implicit conversion of Bool variables
	--------------------------------------
	Boolean values can be added in form of integers to integral variables, using implicit conversion techniques. Hence, when we add a Boolean value to an integer, it gets incremented by 1 if the value is true, otherwise it remains same as false value corresponds to 0.
	*/

	// C++ program to demonstrate
	// bool data type
#include <iostream> 
using namespace std;

int main() {
	bool flag;
	flag = 1;//this is true
	bool flag1 = true;

	cout << flag << " " << flag1 << endl;

	int count = 0;
	int x = 12;
	float y = 35.45;
	bool k = count, k1 = x, k2 = y;
	int sum = x + flag + flag1;

	cout << k << " " << count << " " << k1 << " " << x << " " << k2 << " " << y << " " << endl;
	cout << "After adding Boolean and integer values : " << sum << endl;
	return 0;
}