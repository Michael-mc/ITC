// This is a lib implementing the functionality of Game of Life.
// the students will have to reverse the library to understand its interface and use it to create a game.
// they should have an SLN provided with the .lib file compiled and a header file that has declarations of the functions they need to call.
// if the declarations actually match the parameters given is up to the teacher to decide.


#include "GOL.h"
#include <stdlib.h>
#include <memory.h>

#define STATIC_GAME_CELL_SIZE (0x100)
//static char cgc [STATIC_GAME_CELL_SIZE]; // current_game_cells 
//static char ngc [STATIC_GAME_CELL_SIZE]; //next_game_cells

static unsigned int gx, gy, gs; // game_size_x, game_size_y, gp1_size
static char *gp1, *gp2; // cur_game, next_step
static int flag = 0; // game_not_static


gol_error_e ex1(unsigned int size_x, unsigned int size_y, char *start_state) {
	if (!flag) return error_not_inititalized;
    if (size_x == 0 || size_y == 0) {
        return error_bad_input;
    }
    if (!start_state) return error_bad_input;
    gx = size_x;
    gy = size_y;
	gs = size_x * size_y;       
	
    gp1 = (char *)malloc(gs);
    if (!gp1) goto nomem;
    gp2 = (char *)malloc(gs);
    if (!gp2) {
        free(gp1);
        goto nomem;
    }
    flag = 1;
    
    memcpy(gp1, start_state, gs);
    return error_ok;
nomem:
	return error_no_mem;
}

static int hmm(unsigned int x, unsigned int y) {
    int out = 0;
    int up_index = y == 0 ? (gy - 1) : y - 1;
    int down_index = y == (gy - 1) ? 0 : y + 1;
    int left_index = x == 0 ? (gx - 1) : x - 1;
    int right_index = x == (gx - 1) ? 0 : x + 1;
    
	out += gp1[up_index * gx + left_index];
	out += gp1[up_index * gx + x];
	out += gp1[up_index * gx + right_index];
	out += gp1[y * gx + left_index];
	out += gp1[y * gx + right_index];
    out += gp1[down_index * gx + left_index];
	out += gp1[down_index * gx + x];
	out += gp1[down_index * gx + right_index];
	
    return out;
}


static __forceinline int gamee(int x, int y,  int living_neighbours) {
	unsigned int i = x + y* gx;
    if (gp1[i] == 1) // is alive
    {
        if ( (living_neighbours == 3) || (living_neighbours == 2) ) {
            gp2[i] = 1; // remains alive
            return 1;                
        }
    }
    else if (living_neighbours == 3) {
        gp2[i] = 1; // spawns
        return 1;
    }
        
    gp2[i] = 0;
    return 0;
}

gol_error_e ex3() {
    unsigned int i, j;
    int living_neighbours = 0;
    int living_cells = 0;
	char * temp ;	
	if (!flag) return error_not_inititalized;
	for(i = 0 ; i < gy; ++i) {
		for ( j = 0; j < gx; j++) {
			living_neighbours = hmm(j, i);
			living_cells += gamee(j, i,  living_neighbours);
		}
    }
    // this swaps the two, making it ready for the next round
    temp = gp1;
    gp1 = gp2;
    gp2 = temp;
    
    return living_cells != 0 ? error_ok : error_ended;
}

int ex_3(unsigned int times) {	
    int i;
	if (!flag) return error_not_inititalized;
    if (times == 0) return error_bad_input;
    for (i = 0; i < times; ++i) {
        if (error_ended == ex3()) break;
    }
    return i;
}

gol_error_e ex_() {
	
    if (flag) {
        free(gp1);
        free(gp2);
		gx = 0;
		gy = 0;	
		flag = 0;
		return error_ok;
    }
	return error_not_inititalized;
}

gol_error_e ex(unsigned int size, char *states) {
	if (!flag) return error_not_inititalized;
	if (size < gs) return error_bad_input;
	memcpy(states, gp1, gs);
	return error_ok;
}