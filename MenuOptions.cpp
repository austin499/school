#include "MenuOptions.h"

#include <iostream>
#include <iomanip>
using namespace std;


MenuOptions::MenuOptions()
	: MenuItem("Histogram") {}

MenuOptions::MenuOptions(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("Histogram", t_menuPosition, t_inventoryMap) {}

// output list of inventory, formatted
void MenuOptions::Select() {

	// print headers
	cout << setw(16) << right << "Item" << "  Amount" << endl << endl;

	// print histogram, item followed by lines for the amount of items in stock
	for (const pair<const string, unsigned int> item : (*m_inventoryMap))
	{
		cout << setw(16) << right << item.first << "  ";
		cout << std::string(item.second, '|') << endl;
	}

}