// compile in debug settings

#include <stdio.h>

#include "menus.h"
#include <windows.h>
#include <stdlib.h>

COORD pos;
__declspec(noinline) void SaveCursor() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(screen, &bi);
    pos = bi.dwCursorPosition;
}
__declspec(noinline) void RevertCursor() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, pos);
}
__declspec(noinline) void clear_cursor () {
	RevertCursor();
        printf("                                                                                                                       \r\n");
        printf("                                                                                                                       ");
    RevertCursor();
}

int main(void)
{
    printf("Wellcome to the ShopManager2000!! \r\nPlease select items from the menu\r\n\r\n");
    size_t subtotal = 0;
	menu_options &current = options[0];
    printf ("%s:\r\n", current.title);
    for (int i = 0; i < current.size; ++i) {
		printf("\t%d: %s\t\t\t     | $%d   \r\n", i, current.strings[i], current.prices[i]);
    }  
    printf("\r\n\t%d: %s\r\n", 999, "Terminate");
      
    printf("Enter next choice: ");
    SaveCursor();
    int choice;
    do {
        RevertCursor();
        scanf("%d", &choice);
        clear_cursor();
        if (choice < current.size) {
           subtotal += current.prices[choice]; 
        } else if (choice != 999) {
            printf("\r\n Invalid Choice, try again");
        }
    } while (choice != 999);
    
    system("cls");
    
    printf("\r\n\r\n Thank you! subtotal was: %d", subtotal);
   return 0; 
}
