#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 5

typedef struct side {
	int left;
	int top;
	int right;
	int bottom;
} SIDE;

void read_squares(SIDE *squares, int n) {
	for (int i = 0; i < n*n; i++) {
		scanf("%d%d%d%d", &(squares[i]).left, &(squares[i]).top, &(squares[i]).right, &(squares[i]).bottom);
	}
	return;
}

void init_placement(int *placement, int n) {
	for (int i = 0; i < n*n; i++) {
		placement[i] = -1;
	}
}

void print_matrix(int *matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", matrix[i*n+j]);
		}
		printf("\n");
	}
	return;
}

bool check_valid(SIDE *squares, int *placement, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (squares[placement[i*n+j]].right != squares[placement[i*n+j+1]].left) {
				return false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (squares[placement[j*n+i]].bottom != squares[placement[(j+1)*n+i]].top) {
				return false;
			}
		}
	}
	return true;
}

bool place_square(SIDE *squares, int *placement, int *used_placement, int n, int square_index) {
	if (square_index == n*n) {
		if (check_valid(squares, placement, n)) {
			print_matrix(placement, n);
			return true;
		}
		else {
			return false;
		}
	}
	for (int i = 0; i < n*n; i++) {
		int row = square_index / n;
		int col = square_index % n;
		if (used_placement[i] == -1) {
			if (row > 0 && squares[placement[(row-1)*n+col]].bottom != squares[i].top) continue;
			if (col > 0 && squares[placement[row*n+col-1]].right != squares[i].left) continue;
			used_placement[i] = 1;
			placement[square_index] = i;
			bool ret = place_square(squares, placement, used_placement, n, square_index+1);
			if (ret) return true;
			used_placement[i] = -1;
			placement[square_index] = -1;
		}
	}
	return false;
}


void solve(SIDE* squares, int n) {
	int *placement = malloc(sizeof(int)*n*n);
	int *used_placement = malloc(sizeof(int)*n*n);
	init_placement(placement, n);
	init_placement(used_placement, n);
	bool ret = place_square(squares, placement, used_placement, n, 0);
	if (!ret) {
		printf("no solution\n");
	}
	free(placement);
	free(used_placement);
	return;
}

int main(void) {
	int n;
	while (scanf("%d", &n) != EOF) {
		SIDE *squares = malloc(sizeof(SIDE)*n*n);
		read_squares(squares, n);
		solve(squares, n);
		free(squares);
	}
	return 0;
}
