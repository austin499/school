#include "Search.h"

#include <iostream>
using namespace std;


Search::Search()
	: MenuItem("Search") {}

Search::Search(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("Search", t_menuPosition, t_inventoryMap) {}

// autocorrects capitalization
string Search::ProperCase(string t_input) {
	for (int i = t_input.length() - 1; i >= 0; i--) {
		if ((i == 0) || (t_input[i - 1] == ' ')) {
			t_input[i] = toupper(t_input[i]);
		}
		else {
			t_input[i] = tolower(t_input[i]);
		}
	}
	return t_input;
}

// read user input, return valid output
void Search::Select() {
	string searchInput;

	cout << "Type the name of an inventory item:" << endl;

	// read uset input
	getline(cin, searchInput);

	// autocorrect input
	searchInput = ProperCase(searchInput);

	cout << endl;

	// check map item for valid inventory item
	if ((*m_inventoryMap).count(searchInput) > 0) {
		cout << "Item: " << searchInput << endl;
		cout << "Number in inventory: " << (*m_inventoryMap)[searchInput] << endl;
	}
	else {
		cout << searchInput << " not found in inventory." << endl;
	}
}