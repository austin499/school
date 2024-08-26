#include "Quit.h"

#include <iostream>
using namespace std;


Quit::Quit()
    : MenuItem("Quit") {}

Quit::Quit(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
    : MenuItem("Quit", t_menuPosition, t_inventoryMap) {}

void Quit::Select() {
    cout << "Bye!" << endl;
    exit(0);
}