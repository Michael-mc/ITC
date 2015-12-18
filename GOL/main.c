#include "GOL.h"
#include <stdlib.h>
#include <memory.h>

gol_error_e initialize_gol(unsigned int size_x, unsigned int size_y, char *start_state) {
    if (size_x == 0 || size_y == 0) {
        return error_bad_input;
    }
    if (!start_state) return error_bad_input;
    game_size_x = size_x;
    game_size_y = size_y;
    if (size_x * size_y <= STATIC_GAME_CELL_SIZE) {
		game_not_static = 0;
        cur_game = cur_game_cells;
        next_step = next_game_cells;
    }
    else {
		game_not_static = 1;
        cur_game = (char *)malloc(size_x * size_y);
        if (!cur_game) return error_no_mem;
        next_step = (char *)malloc(size_x * size_y);
        if (!next_step) {
            free(cur_game);
            return error_no_mem;
        }
    }
    
    memcpy(cur_game, start_state, size_x * size_y);
    return error_ok;
}

int determine_neighbours(unsigned int x, unsigned int y, unsigned int cur_spot) {
    int out = 0;
    int is_top = y == 0;
    int is_bottom = y == game_size_y - 1;
    int is_left = x == 0;
    int is_right = x == game_size_x - 1;
    
    if (!is_top) {
        out += cur_game[cur_spot - game_size_x ] != 0;
        if (!is_right) cur_game[cur_spot - 1 - game_size_x] != 0;
        if (!is_left) cur_game[cur_spot  +1 - game_size_x] != 0;
    }
    if (!is_bottom) {
        out += cur_game[cur_spot + game_size_x] != 0;
        if (!is_right) cur_game[cur_spot + game_size_x - 1] != 0;
        if (!is_left) cur_game[cur_spot + game_size_x + 1] != 0;
    }
    if (!is_right) cur_game[cur_spot - 1] != 0;
    if (!is_left) cur_game[cur_spot + 1] != 0;
    
    return out;
}


__forceinline int set_new_state(int i, int living_neighbours) {
    if (cur_game[i] == 1) // is alive
    {
        if ( (living_neighbours < 3) && (living_neighbours > 2) ) {
            next_step[i] = 1; // remains alive
            return 1;                
        }
    }
    else if (living_neighbours == 3) {
        next_step[i] = 1; // spawns
        return 1;
    }
        
    next_step[i] = 0;
    return 0;
}

gol_error_e run_game() {
    unsigned int i;
    int living_neighbours = 0;
    int living_cells = 0;
	char * temp ;
    for(i = 0 ; i < game_size_x * game_size_y; ++i) {
        living_neighbours = determine_neighbours(i % game_size_x, i / game_size_x, i);
        living_cells += set_new_state(i, living_neighbours);
    }
    // this swaps the two, making it ready for the next round
    temp = cur_game;
    cur_game = next_step;
    next_step = cur_game;
    
    return living_cells != 0 ? error_ok : error_ended;
}

int run_times(unsigned int times) {	
    int i;
    if (times == 0) return error_bad_input;
    for (i = 0; i < times; ++i) {
        if (error_ended == run_game()) break;
    }
    return i;
}

void destroy_game() {
    if (game_not_static) {
        free(cur_game);
        free(next_step);
    }
    game_size_x = 0;
    game_size_y = 0;
}