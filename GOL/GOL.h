#ifndef _GOL_H_
#define _GOL_H_

typedef enum {
    error_ok = 0,
    error_bad_input,
    error_no_mem,
    error_ended,
} gol_error_e;

#define STATIC_GAME_CELL_SIZE (0x100)
char cur_game_cells [STATIC_GAME_CELL_SIZE];
char next_game_cells [STATIC_GAME_CELL_SIZE];

unsigned int game_size_x, game_size_y;
char *cur_game, *next_step;
int game_not_static = 0;

gol_error_e initialize_gol(unsigned int size_x, unsigned int size_y, char *start_state);
gol_error_e get_state(unsigned int size_x, unsigned int size_y, char *state_mat);

gol_error_e run_game();
int run_times(unsigned int times);

void destroy_game();


#endif
