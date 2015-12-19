#include "..\GOL\gol.h"
#include <stdio.h>

char initial_state[28] = {
		0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1,
		0, 1, 0, 1, 1, 0, 1,
		0, 0, 0, 0, 0, 0, 0,
};
void main (void) {
	gol_error_e a ;
	initialize_gol(7, 4, initial_state);
	do{
		a = run_game();
		get_state(28, initial_state);
	}
	while (a != error_ended) ;
	printf("done");
}