#include <iostream>
using namespace std;

class Animal {
protected:
	int numberOfLegs; //it's protected so that derived class can access this freely
public:
	//virtual means that if the derived class has overridden this
	//it will use the derived class' version of the function instead
	//if it is not overridden, the base class' version will be used
	virtual void move(){
		cout << "An animal can move." << endl;
	} 

	//a virtual function becomes pure when it has no body, 
	//instead it has a =0;
	//it has no implementation of its own 
	//and derived classes must override it
	//[NOTE: When a class has a pure virtual function,
	// it becomes an abstract class]
	virtual void call()=0;
};

class Cat : public Animal {
public:
	void move() {
		numberOfLegs = 4;
		cout << "A cat moves on " << numberOfLegs
			<< " legs." << endl;
	}

	void call() {
		cout << "A cat meows." << endl;
	}
};

class Bird : public Animal {
public:
	void move() {
		numberOfLegs = 2;
		cout << "A bird moves on " << numberOfLegs
			<< " legs." << endl;
	}

	void call() {
		cout << "A bird chirps." << endl;
	}
};


int main() {
	Cat cat;
	Bird bird;

	Animal *animal1 = &cat;
	Animal *animal2 = &bird;

	cout << "Using Direct calls: " << endl;

	cat.move();
	cat.call();
	bird.move();
	bird.call();

	cout << "\nUsing Animal pointers: " << endl;

	animal1->move();
	animal1->call();
	animal2->move();
	animal2->call();

}