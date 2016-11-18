// compile this using release settings!


// This here is an ugly implementation of a maze, with a character moving according to the input given via stdin ( as numbers )
// there are a couple of objectives here. One is to win, the other is to understand why there are 2 winning messages (one for just escaping 
// the the "CAR" constant, the other is for doing so while gathering more than a certain ammount of money)




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

#define ROWS 10
#define COLS 10

#define GMONEY 5
#define IN_BOARD(row,col) if (!inBoard(row,col)) return OUTOFBOARD;
#define CHECK_STEP(x) if (((x) & 0x80000000) != 0) return WALL;\
					  if (((x) == 'CAR\0')) return WIN; \
						*money += ((x) & 0x000F0000) >> 16;\
						*money -= ((x) & 0x00F00000) >> 20;
#define MAKEWALL(c)  	for (i = 0; i < ROWS ; i++) array[i][c] = array[i][c] | 0xf0000000;
#define MAKESTOP()  	for (i = 0; i < ROWS-1 ; i++) array[i][8] = 0;
#define MAKEJUMP(row,c)  	array[row][c] = 3;
#define MAKECOIN(i,j,x)  	array[i][j] |=  (x << 16);
#define MAKEFEE(i,j,x)  	array[i][j] |=  (x << 20);

typedef enum {
	NOTHING=0,RIGHT=1, LEFT=2, UP=3,DOWN=4
} MOVE;
typedef enum {
	SUCCESS, OUTOFBOARD, WALL, WIN
} doMoveErrors;

struct Pos {
	int row;
	int col;
};

// challanges:
//		figure out that the CAR is the target.
//		figure out that the fastest route is 7 words long (using the jumpers) - 4111114
//		figure out that money can and should be collected - get high score - 4114114123223133113114244134444

int array[ROWS][COLS] = {
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x000f0000, 0x000f0000, 0x000f0000,
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000f0000,
	'$'       , 0xf0000000, 0x00000000, 0x00000000, 0xf0000000, 0x00000000, 0xf0000000, 0xf0000000, 0x00000000, 0x000f0002,
	0x00000000, 0x00000000, 0x00000000, 0x00000002, 0xf0000000, 0x00000000, 0x00000002, 0xf0000000, 0x00000000, 0x000f0000,
	0xf0000000, 0xf0000000, 0x00500000, 0x00000000, 0x00000000, 0xf0000000, 0x00000000, 0xf0000000, 0xf0000000, 'CAR\0',
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x00000000, 0x000f0000, 0x00000000, 0x00000000, 0xf0000000, 0x00000000,
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x00000000, 0x00000000, 0xf0000000, 0x00000000, 0xf0000000, 0x00000000,
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x00000000, 0xf0000000, 0x00000000,
	0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0xf0000000, 0x00000000, 0x00500000, 0x00000000,
};



__declspec(noinline) bool inBoard(int row, int col) {
	if ((row < ROWS) && (col < COLS) && (row>=0) && (col>=0))
		return true;
	return false;
}

__declspec(noinline) doMoveErrors doMove(int array[ROWS][COLS] , struct Pos *pos , MOVE move,int * money) {
	int next = 0;
	int i = 0;
	int row = pos->row;
	int col = pos->col;
	*money = 0;
	switch (move) {
		case RIGHT:
			IN_BOARD(row,col+1)
			CHECK_STEP(array[row][col+1])
			array[row][col] = 0;
			next = array[row][++col] & 0xFFFF;;
			array[row][col] = '$';
			++pos->col;
			for (i =1; i <= next ; i++) {
				IN_BOARD(row,col+i)
				//printf("<%x>",array[row][col+i]); DEBUG
			}
			//IN_BOARD(row,col+next)
			if (next >= 1) { 
				CHECK_STEP(array[row][col+next]) 
				array[row][col] = 0;
				array[row][col+next] = '$';
				pos->col += next;
			}			
			break;
		case LEFT:
			IN_BOARD(row,col-1)
			CHECK_STEP(array[row][col-1])
			array[row][col] = 0;
			next = array[row][--col] & 0xFFFF;;
			array[row][col] = '$';			
			--pos->col;
			for (i =1; i <= next ; i++) {
				IN_BOARD(row,col-i)
			}
			//IN_BOARD(row,col-next)
			if (next >= 1) { CHECK_STEP(array[row][col-next]) 
				array[row][col] = 0;
				array[row][col-next] = '$';
				pos->col -= next;
			}			
			break;
		case DOWN:
			IN_BOARD(row+1,col)
			CHECK_STEP(array[row+1][col])
			array[row][col] = 0;
			next = array[++row][col] & 0xFFFF;;
			array[row][col] = '$';
			++pos->row;
			for (i =1; i <= next ; i++) {
				IN_BOARD(row+i,col)
			}
			//IN_BOARD(row+next,col)
			if (next >= 1) { 
				CHECK_STEP(array[row+next][col]) 
				array[row][col] = 0;
				array[row+next][col] = '$';
				pos->row += next;
			}
			break;
		case UP:
			IN_BOARD(row-1,col)
			CHECK_STEP(array[row-1][col])
			array[row][col] = 0;
			next = array[--row][col] & 0xFFFF;
			array[row][col] = '$';
			--pos->row;
			for (i =1; i <= next ; i++) {
				IN_BOARD(row-i,col)
			}
			//IN_BOARD(row-next,col)
			if (next >= 1) { 
				CHECK_STEP(array[row-next][col]) 
				array[row][col] = 0;
				array[row-next][col] = '$';
				pos->row -= next;
			}
			break;
	}
	return SUCCESS;
}

void wrong() {
	printf("Wrong Password, try again.\n");
}

void success(int score) { 
	if(score < 5 * 0xf) {printf("Good Game!\n"); }
	else {printf("You win! great score!\n");}
}

__declspec(noinline) int get_input(char * input) {
	int len;
	int i;
	char c;
	scanf("%s",input);
	len = strlen(input);
	for (i = 0; i < len; i++) {
		if (!isdigit( input[i]))
			return -1;	
	}
	return len;
}

int main() {
	char input[256];
	int i = 0;
	int tmoney = 0;
	int money = 0;
	int len = 0;
	char c;
	doMoveErrors err;
	struct Pos pos;
	pos.col = 0;
	pos.row = 3;
	
	printf("Enter password:");
	len = get_input(input);
	if (-1 == len) {
		printf("Numbers Only!");
		return ;
	}

	for (i = 0; i < len; i++) {
		c = input[i];
		//printf("try:%c" , c); // DEBUG
		err = doMove(array,&pos,c-'0',&money);
		
		switch(err) {
		case SUCCESS:
			tmoney += money;
			//printf(" ( success, you are in [%d,%d] with %d) \n",pos.row,pos.col,tmoney); // DEBUG
			continue;
			break;
		case OUTOFBOARD:
			//printf("out"); // DEBUG
			wrong();
			return;
			break;
		case WALL:
			//printf("wall"); // DEBUG
			wrong();
			return;
			break;
		case WIN:
			success(tmoney);
			return ;
		}
		
	}
	wrong();
}
