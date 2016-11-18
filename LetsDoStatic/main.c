#include <stdio.h>
#include <stdlib.h>

//
// note - build using tiny c compiler for best results.
// This is a demo exercise.
//


void main( int argc, char *argv []) {
	int number ;
	if (argc == 1) return;
	number = strtol (argv[1], 0, 0);
	if (number > 30) return;
	if (number > 10) number *= number;
	else if (number % 2) number <<= 1;
	else number <<= 2;
	printf("%d", number);
}