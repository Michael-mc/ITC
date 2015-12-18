#ifndef _MENU_ITEM_H_
#defien  _MENU_ITEM_H_

#include <list>

using namespace std;
public class Menu {
    public class MenuItem {
        char *_text
        bool _interactive;
        Menu *next;
    }

    list<MenuItem> _items;    
    public:
        Menu(list<MenuItems> items);
        Menu *get_for_choice(int number);
        string toString();
} 


#endif