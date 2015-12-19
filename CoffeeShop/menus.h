#ifndef _MANUS_H_
#define _MANUS_H_

struct menu_options {
    int size;
	char * title;
    char **strings;
    int  *prices;    
};

int prices1 [4]= {3, 2, 1, 10};
int prices2[3] = {100, 200, 300};
int prices3[5] = {0,0,0,0,0};

char *strings1[4] = {"Latte", "Esspresso", "Soy Milk", "Sandwich"};
char *strings2[3] = {"Nice  ", "Rabock", "Lea Keeper"};

menu_options options [3] = {
    {4, "Cafe", strings1 , prices1}, 
    {3, "Shoe Store", strings2, prices2}, 
};


#endif