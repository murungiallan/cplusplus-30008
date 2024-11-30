#include <iostream>
#include "Node.h"
#include "NodeIterator.h"
using namespace std;

void insertMiddle(Node* prevNode, int value) {
	if (prevNode == (Node*)0) {
		cout << "The given previous node cannot be a null Node pointer";
		return;
	}
	Node* newNode = new Node(value);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void displayList(Node* head) {
	for (NodeIterator it(head); it != it.end(); ++it) {
		cout << *it << " -> ";
	}
	cout << "End" << endl;
}

//void removeNode(Node* prevNode) {
//	Node* temp = prevNode->next;
//	prevNode->next = prevNode->next->next;
//	delete temp;
//}

int main() {
	int arr[] = { 1, 2, 2, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	Node* head = (Node*)0; // Null node pointer (i.e. empty list)

	// Populate the Linked List (from the Head)

	for (int i = 0; i < size; i++) {
		// Adding nodes to the head
		/*Node* newNode = new Node(arr[i]);
		newNode->next = head;
		head = newNode;*/ // newNode is the new head of the list

		// Adding nodes to the tail
		Node* newNode = new Node(arr[i]);
		newNode->next = (Node*)0;

		if (head == (Node*)0) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next != (Node*)0) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}

	Node* ptr = head; // Make an Alias of the front of the list

	ptr = head->next->next->next;
	insertMiddle(ptr, 99);

	ptr = head;

	while (ptr != (Node*)0) {
		cout << ptr->value << endl; // prints out the value of the node
		ptr = ptr->next;
	}

	displayList(head);

	ptr = head; // Reset the Alias back to the head of the list

	while (ptr != (Node*)0) {
		Node* temp = ptr;
		ptr = ptr->next; // points to the next node
		delete temp;
	}

	return 0;
}