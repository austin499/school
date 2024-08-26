#include "Menu.h"
#include "Management.h"
#include "Search.h"
#include "List.h"
#include "MenuOptions.h"
#include "Quit.h"

#include <iostream>
using namespace std;


// create menu and options
Menu::Menu() {

    // find inventory and load
    m_inventoryMap = loadFile();
    makeBackup(m_inventoryMap);

    m_menuItems = {
        new Search(1, m_inventoryMap),
        new List(2, m_inventoryMap),
        new MenuOptions(3, m_inventoryMap),
        new Quit(4, m_inventoryMap)
    };
}

// deletes menu options and inventory map
Menu::~Menu() {
    delete m_inventoryMap;

    for (MenuItem* menuItem : m_menuItems) {
        delete menuItem;
    }
}

// output menu options
void Menu::Print() const {
    cout << "Type a character to select a menu option:" << endl;
    for (MenuItem* menuItem : m_menuItems) {
        menuItem->Print();
    }
    cout << endl;
}

// read user input for options
void Menu::InputHotkey() {
    string userInput;
    bool isMatch;
    unsigned int menuLength = m_menuItems.size();

    getline(cin, userInput);

    // check for valid answers
    for (unsigned int i = 0; i <= menuLength; i++) {
        if (i < menuLength) {
            isMatch = m_menuItems.at(i)->Check(userInput);

            // if valid answer found, select it
            if (isMatch) {
                cout << endl;
                m_menuItems.at(i)->Select();
                cout << endl << endl;

                // stop searching
                break;
            }
        }
        else {
            cout << "Input does not match a menu item. Enter a menu option number or the first letter corresponding to a menu option.";
            cout << endl << endl;
        }
    }
}