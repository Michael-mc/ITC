#include <stdio.h>
#include <stdlib.h>

//
// compile with tcc for best result
// simply request input until the requested string is given.
//
int main()
{
    char input [256] = {0};
	do {       
        printf("Enter Key:\n");
        scanf("%s", input);
    } while(strcmp(input, "MightAsWellBeCool"));
    printf("Thanks!\n");
    getc(stdin);	
	getc(stdin);
	return 1;
}
