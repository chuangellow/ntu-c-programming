#include <stdio.h>

enum {
	R = 0,
	UR = 1,
	UL = 2,
	L = 3,
	BL = 4,
	BR = 5,
};

typedef struct vec {
	int i;
	int j;
} VEC;

void finger_vec(int mov, VEC *fig_vec) {
	switch (mov) {
		case R:
			fig_vec->i = 0;
			fig_vec->j = 1;
			break;
		case UR:
			fig_vec->i = -1;
			fig_vec->j = 1;
			break;
		case UL:
			fig_vec->i = -1;
			fig_vec->j = 0;
			break;
		case L:
			fig_vec->i = 0;
			fig_vec->j = -1;
			break;
		case BL:
			fig_vec->i = 1;
			fig_vec->j = -1;
			break;
		case BR:
			fig_vec->i = 1;
			fig_vec->j = 0;
			break;
		default:
			break;
	}
}

void find_pos(char keyboard[3][15], char init_char, VEC *init) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 15; j++) {
			if (keyboard[i][j] == init_char) {
				init->i = i;
				init->j = j;
			}
		}
	}
	return;
}

void print_key(char keyboard[3][15], VEC *next_pos, VEC fig_vec) {
	if ((next_pos->i >= 0 && next_pos->i < 3) && (next_pos->j >= 0 && next_pos->j < 15)) {
		char next_char = keyboard[next_pos->i][next_pos->j];
		if (next_char != '\0') {
			printf("%c\n", next_char);
		}
		else {
			next_pos->i = next_pos->i - fig_vec.i;
			next_pos->j = next_pos->j - fig_vec.j;
		}
	}
	else {
		next_pos->i = next_pos->i - fig_vec.i;
		next_pos->j = next_pos->j - fig_vec.j;
	}
}

int main(void) {
	char keyboard[3][15] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
	char init_char;
	scanf("%c", &init_char);
	printf("%c\n", init_char);
	VEC init_pos = {0, 0};
	find_pos(keyboard, init_char, &(init_pos));
	int mov;
	scanf("%d", &mov);
	VEC fig_vec = {0, 0};
	finger_vec(mov, &fig_vec);
	VEC next_pos = {init_pos.i + fig_vec.i, init_pos.j + fig_vec.j};
	print_key(keyboard, &next_pos, fig_vec);
	while (scanf("%d", &mov) != EOF) {
		finger_vec(mov, &fig_vec);
		next_pos.i = next_pos.i + fig_vec.i;
		next_pos.j = next_pos.j + fig_vec.j;
		print_key(keyboard, &next_pos, fig_vec);
	}
	return 0;
}
