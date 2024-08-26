#include "List.h"

#include <iostream>
#include <iomanip>
using namespace std;


List::List()
	: MenuItem("List Inventory") {}

List::List(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("List Inventory", t_menuPosition, t_inventoryMap) {}

// output list of inventory, formatted
void List::Select() {

	// print headers
	cout << setw(14) << left << "Item" << "Amount" << endl << endl;

	// for each item print name of item and number in stock
	cout << setfill('.');
	for (const pair<const string, unsigned int> item : (*m_inventoryMap))
	{
		cout << setw(16) << left << item.first;
		cout << setw(4) << right << item.second << endl;
	}
	cout << setfill(' ');

}