#include <iostream>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#include "List.h"
using namespace std;

int main() {
	List<int> TheList;

	cout << "Testing the Improved List - From the Back" << endl;

	TheList.pushBack(1);
	TheList.pushBack(2);
	TheList.pushBack(3);

	while (!TheList.isEmpty()) {
		cout << "Popped from the Back : " << TheList.popBack() << endl;
	}

	cout << "Testing the Improved List - From the Front" << endl;

	TheList.pushFront(4);
	TheList.pushFront(5);
	TheList.pushFront(6);

	while (!TheList.isEmpty()) {
		cout << "Popped from teh Back: " << TheList.popFront() << endl;
	}

	return 0;
}