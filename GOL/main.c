#include "GOL.h"
#include <stdlib.h>
#include <memory.h>

#define STATIC_GAME_CELL_SIZE (0x100)
char cgc [STATIC_GAME_CELL_SIZE]; // current_game_cells 
char ngc [STATIC_GAME_CELL_SIZE]; //next_game_cells

unsigned int gx, gy, gs; // game_size_x, game_size_y, gp1_size
char *gp1, *gp2; // cur_game, next_step
int flag = 0; // game_not_static


gol_error_e q5651(unsigned int size_x, unsigned int size_y, char *start_state) {
    if (size_x == 0 || size_y == 0) {
        return error_bad_input;
    }
    if (!start_state) return error_bad_input;
    gx = size_x;
    gy = size_y;
	gs = size_x * size_y;
    if (gs <= STATIC_GAME_CELL_SIZE) {
		flag = 0;
        gp1 = cgc;
        gp2 = ngc;
    }
    else {
		flag = 1;
        gp1 = (char *)malloc(gs);
        if (!gp1) return error_no_mem;
        gp2 = (char *)malloc(gs);
        if (!gp2) {
            free(gp1);
            return error_no_mem;
        }
    }
    
    memcpy(gp1, start_state, gs);
    return error_ok;
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

gol_error_e x56554() {
    unsigned int i, j;
    int living_neighbours = 0;
    int living_cells = 0;
	char * temp ;
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

int rs51336(unsigned int times) {	
    int i;
    if (times == 0) return error_bad_input;
    for (i = 0; i < times; ++i) {
        if (error_ended == x56554()) break;
    }
    return i;
}

void dit6213() {
    if (flag) {
        free(gp1);
        free(gp2);
    }
    gx = 0;
    gy = 0;
}

gol_error_e tt66612(unsigned int size, char *states) {
	if (size < gs) return error_bad_input;
	memcpy(states, gp1, gs);
	return error_ok;
}