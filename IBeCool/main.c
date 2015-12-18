#include <stdio.h>
#include <stdlib.h>
int main()
{
    char input [256] = {0};
	do {       
        printf("Enter Key:\n");
        scanf("%s", input);
    } while(strcmp(input, "MightAsWellBeCool"));
    printf("Thanks!\n");
    getch();
	return 1;
}
