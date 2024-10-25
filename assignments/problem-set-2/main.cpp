// 102760283 - Problem Set 2, Sem 2 2024
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Iterator1D.h"
#include "Iterator2D.h"

using namespace std;

int main() {
	while (true) {
		string userInput;
		cout << "Type start/quit:" << endl;
		cin >> userInput;

		if (userInput == "start" || userInput == "Start" || userInput == "START") {
			string bag1D[10] = { "Knife", "Shoes", "Torch", "Water", "Map", "Sword", "Sleeping Bag", "Snack", "Bow", "Arrow" };
			string bag1D2[10] = { "Socks", "Chocolate", "Ice cream", "Shower gel", "Rocks", "Meat", "Firewood", "Another Snack", "Another Bow", "Another Arrow" };
			vector<vector<string>> bag2D = {
				{ "Knife", "Shoes", "Torch" },
				{ "Water", "Map", "Sword" },
				{ "Sleeping Bag", "Snack", "Bow" },
				{ "Arrow", "Compass", "Tent" }
			};
			Iterator1D it(bag1D, 10);
			Iterator1D it1(bag1D2, 10);
			Iterator2D it2(bag2D);

			// Task 2: Basic Backpack and Iterator
			cout << "Task 2: Basic Backpack and Iterator" << endl;
			// iterator 1D
			cout << it << endl;
			it.operator++();
			cout << it << endl;
			it.operator--();
			cout << it << endl;

			// iterator 2D
			cout << it2 << endl;
			it2.operator++();
			cout << it2 << endl;
			it2.operator--();
			cout << it2 << "\n" << endl;

			Entity wolverine(1, "Wolverine", 99);
			Entity deadpool(2, "Deadpool", 90);
			
			// Task 1: Setting Up Environment
			cout << "Task 1: Setting Up Environment" << endl;
			wolverine.Print();
			deadpool.Print();
			cout << "\n" << endl;


			// Task 3: Integration 1D
			cout << "Task 3: Integration 1D" << endl;
			wolverine.GrabIterator(&it);
			deadpool.GrabIterator(&it1);

			// Testing Wolverine's ability to go through items in his bag using the iterator
			cout << "Wolverine's bag...\n" << endl;
			wolverine.InventoryGet();
			wolverine.InventoryNext();
			wolverine.InventoryGet();
			wolverine.InventoryPrev();
			wolverine.InventoryGet();

			// Switching bags
			cout << "\nDeadpool and Wolverine switch bags..." << endl;
			wolverine.GrabIterator(&it1);
			deadpool.GrabIterator(&it);

			cout << "\n";

			wolverine.InventoryGet();
			cout << "Wolverine and Deadpool switched bags. Can you tell in Wolverine's original bag there was no socks?";

			delete &it;
			delete &it1;
		} else {
			cout << "Exiting..";
			break;
		}
	}

	return 0;
}