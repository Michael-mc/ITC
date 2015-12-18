#include <stdio.h>

#include <menus.h>
#include <windows.h>
#include <stdlib.h>

COORD pos;
void SaveCursor() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(screen, &bi);
    pos = bi.dwCursorPosition;
}
void RevertCursor() {
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, pos);
}

int main(void)
{
    printf("Wellcome to the ShopManager2000!! \r\nPlease select items from the menu\r\n\r\n");
    size_t subtotal = 0;
    char ** current = options[2].strings;
    int * prices = options[2].prices;
    char size = options[2].size;

    for (int i = 0; i < size; ++i) {
        printf("\t%d: %s\t\t\t     | $%d   \r\n", i, current[i], prices[i]);
    }  
    printf("\r\n\t%d: %s\r\n", 999, "Terminate");
      
    printf("Enter next choice: ");
    SaveCursor();
    int choice;
    do {
        RevertCursor();
        scanf("%d", &choice);
        RevertCursor();
        printf("                                                                                                                       \r\n");
        printf("                                                                                                                       ");
        RevertCursor();
        if (choice < size) {
           subtotal += prices[choice]; 
        } else if (choice != 999) {
            printf("\r\n Invalid Choice, try again");
        }
    } while (choice != 999);
    
    system("cls");
    
    printf("\r\n\r\n Thank you! subtotal was: %d", subtotal);
   return 0; 
}
