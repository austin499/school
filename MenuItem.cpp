#include "MenuItem.h"

#include <iostream>
using namespace std;


// constructor for inputs
MenuItem::MenuItem(string t_label, int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
    : m_menuLabel(t_label), m_inventoryMap(t_inventoryMap) {
    m_menuHotkey = to_string(t_menuPosition).at(0);
}

// default value for options
MenuItem::MenuItem(string t_label) {
    m_menuLabel = t_label;
    m_menuHotkey = t_label.at(0);
    m_inventoryMap = new map<string, unsigned int>;
}

// default value for menu options
MenuItem::MenuItem() : MenuItem("Menu Option") {}


bool MenuItem::Check(string t_userInput) const {
    // validate user input
    bool isMatch = (tolower(t_userInput.at(0)) == tolower(m_menuHotkey))
        || (tolower(t_userInput.at(0)) == tolower(m_menuLabel.at(0)));
    return isMatch;
}

void MenuItem::Print() const {
    cout << m_menuHotkey << ") " << m_menuLabel << endl;
}