#include <stdio.h>

#define MAX_H 500
#define MAX_W 500

enum {
	ROCK = 0,
	QUEEN = 1,
	BISHOP = 2,
	ROOK = 3,
};

void place_rock(int board[MAX_H][MAX_W], int row, int col, int h, int w) {
	board[row][col] = 1;
	return;
}

void place_bishop(int board[MAX_H][MAX_W], int row, int col, int h, int w) {
	board[row][col] = 1;
	int row_s = 1, col_s = 1;
	while (row - row_s >= 0 && col - col_s >= 0 && board[row - row_s][col - col_s] != 1) {
		board[row - row_s][col - col_s] = 1;
		row_s++;
		col_s++;
	}
	row_s = 1;
	col_s = 1;
	while (row - row_s >= 0 && col + col_s < w && board[row - row_s][col + col_s] != 1) {
		board[row - row_s][col + col_s] = 1;
		row_s++;
		col_s++;
	}
	row_s = 1;
	col_s = 1;
	while (row + row_s < h && col - col_s >= 0 && board[row + row_s][col - col_s] != 1) {
		board[row + row_s][col - col_s] = 1;
		row_s++;
		col_s++;
	}
	row_s = 1;
	col_s = 1;
	while (row + row_s < h && col + col_s < w && board[row + row_s][col + col_s] != 1) {
		board[row + row_s][col + col_s] = 1;
		row_s++;
		col_s++;
	}
	return;
}

void place_rook(int board[MAX_H][MAX_W], int row, int col, int h, int w) {
	board[row][col] = 1;
	int right = h - row;
	int left = row + 1;
	int down = w - col;
	int up = col + 1;
	for (int i = 1; i < left && board[row-i][col] != 1; i++) {
		board[row-i][col] = 1;
	}
	for (int i = 1; i < right && board[row+i][col] != 1; i++) {
		board[row+i][col] = 1;
	}
	for (int j = 1; j < up && board[row][col-j] != 1; j++) {
		board[row][col-j] = 1;
	}
	for (int j = 1; j < down && board[row][col+j] != 1; j++) {
		board[row][col+j] = 1;
	}
	return;
}

void place_queen(int board[MAX_H][MAX_W], int row, int col, int h, int w) {
	board[row][col] = 1;
	place_rook(board, row, col, h, w);
	place_bishop(board, row, col, h, w);
	return;
}

void print_board(int board[MAX_H][MAX_W], int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return;
}

int main(void) {
	int h, w;
	scanf("%d%d", &h, &w);
	int board[MAX_H][MAX_W] = {0};
	int type, col, row;
	while (scanf("%d%d%d", &type, &col, &row) != EOF) {
		switch (type) {
			case ROCK:
				place_rock(board, row, col, h, w);
				break;
			case QUEEN:
				place_queen(board, row, col, h, w);
				break;
			case BISHOP:
				place_bishop(board, row, col, h, w);
				break;
			case ROOK:
				place_rook(board, row, col, h, w);
				break;
			default:
				break;
		}
	}
	print_board(board, h, w);
	return 0;
}
