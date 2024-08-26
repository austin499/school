#ifndef CORNER_GROCER_APP_MENUITEM_SEARCH_OPTION_H_
#define CORNER_GROCER_APP_MENUITEM_SEARCH_OPTION_H_

#include <string>
#include <map>

#include "MenuItem.h"


class Search : public MenuItem {
public:
    Search();
    Search(int t_menuPosition, std::map<std::string, unsigned int>* t_inventoryMap);
    std::string ProperCase(std::string t_input);
    void Select();
};

#endif // CORNER_GROCER_APP_MENUITEM_SEARCH_OPTION_H_