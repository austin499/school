#ifndef CORNER_GROCER_APP_MENUITEM_LIST_OPTION_H_
#define CORNER_GROCER_APP_MENUITEM_LIST_OPTION_H_

#include <string>
#include <map>

#include "MenuItem.h"


class List : public MenuItem {
public:
    List();
    List(int t_menuPosition, std::map<std::string, unsigned int>* t_inventoryMap);
    void Select();
};

#endif // CORNER_GROCER_APP_MENUITEM_LIST_OPTION_H_