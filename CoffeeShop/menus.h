#ifndef _MANUS_H_
#define _MANUS_H_

struct menu_options {
    int size;
    char **strings;
    int  *prices;    
};

int prices1 [3]= {1,2,3};
int prices2[2] = {4,5};
int prices3[5] = {0,0,0,0,0};

char *strings1[3] = {"a", "b", "c"};
char *strings2[2] = {"e", "d"};
char *strings3[5] = {"","","","",""};

menu_options options [3] = {
    {3, strings1 , prices1}, 
    {2, strings2, prices2}, 
    {5, strings3 , prices3}
};
 


#endif