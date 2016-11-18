#ifndef _GOL_H_
#define _GOL_H_

typedef enum {
    error_not_inititalized = -1,
	error_ok = 0,
    error_bad_input,
    error_no_mem,
    error_ended,
	
} gol_error_e;


__declspec(dllexport) gol_error_e ex1(unsigned int size_x, unsigned int size_y, char *start_state);
__declspec(dllexport) gol_error_e ex(unsigned int size, char *state_mat);

__declspec(dllexport) gol_error_e ex3();
__declspec(dllexport) int ex_3(unsigned int times);

__declspec(dllexport) gol_error_e ex_();


#endif
