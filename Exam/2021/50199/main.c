#include <stdio.h>

#define MAX_R 500
#define MAX_C 500


void print_mat(int mat[MAX_R+4][MAX_C+4], int r, int c) {
	for (int i = 2; i < r+2; i++) {
		for (int j = 2; j < c+2; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return;
}

void check_row(int mat[MAX_R+4][MAX_C+4], int r, int c, int i, int j) {
	if (mat[i][j] == mat[i+1][j] && mat[i+1][j] == mat[i+2][j]) {
		for (int s = 0; s < 3; s++) {
			mat[i+s][j] = 0;
		}
	}
	return;
}
void check_col(int mat[MAX_R+4][MAX_C+4], int r, int c, int i, int j) {
	if (mat[i][j] == mat[i][j+1] && mat[i][j+1] == mat[i][j+2]) {
		for (int s = 0; s < 3; s++) {
			mat[i][j+s] = 0;
		}
	}
	return;
}

void check_l(int mat[MAX_R+4][MAX_C+4], int r, int c, int i, int j) {
	// upper left
	if (mat[i-1][j] == mat[i][j] && mat[i][j] == mat[i][j+1]) {
		mat[i-1][j] = 0;
		mat[i][j] = 0;
		mat[i][j+1] = 0;
	}
	// upper right
	if (mat[i+1][j] == mat[i][j] && mat[i][j] == mat[i][j+1]) {
		mat[i+1][j] = 0;
		mat[i][j] = 0;
		mat[i][j+1] = 0;
	}
	// lower left
	if (mat[i-1][j] == mat[i][j] && mat[i][j] == mat[i][j-1]) {
		mat[i-1][j] = 0;
		mat[i][j] = 0;
		mat[i][j-1] = 0;
	}
	// lower right
	if (mat[i+1][j] == mat[i][j] && mat[i][j] == mat[i][j-1]) {
		mat[i+1][j] = 0;
		mat[i][j] = 0;
		mat[i][j-1] = 0;
	}
	return;
}

void candy_crush(int mat[MAX_R+4][MAX_C+4], int r, int c) {
	for (int i = 2; i < r+2; i++) {
		for (int j = 2; j < c+2; j++) {
			check_row(mat, r, c, i, j);
			check_col(mat, r, c, i, j);
			check_l(mat, r, c, i, j);
		}
	}
	return;
}

int main(void) {
	int r, c;
	scanf("%d%d", &r, &c);
	int mat[MAX_R+4][MAX_C+4];
	for (int i = 2; i < r+2; i++) {
		for (int j = 2; j < c+2; j++) {
			scanf("%d", &(mat[i][j]));
		}
	}
#ifdef DEBUG
	print_mat(mat, r, c);
#endif
	candy_crush(mat, r, c);
	print_mat(mat, r, c);
	return 0;
}
