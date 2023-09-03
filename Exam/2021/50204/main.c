#include <stdio.h>

#define MAX_N 100

enum {
	GREEN = 0,
	BLUE = 1,
};

void init_cube(int cube[MAX_N][MAX_N][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cube[i][j][k] = i * n * n + j * n + k;
			}
		}
	}
}

void print_cube(int cube[MAX_N][MAX_N][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				printf("%d ", cube[i][j][k]);
			}
			printf("\n");
		}
	}
}

void g_rotate(int cube[MAX_N][MAX_N][MAX_N], int n, int layer) {
	int mat[MAX_N][MAX_N] = {{0}};
	for (int j = n-1, cube_i = 0; j >= 0; j--, cube_i++) {
		for (int i = n-1, cube_j = n-1; i >= 0; i--, cube_j--) {
			mat[i][j] = cube[layer][cube_i][cube_j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cube[layer][i][j] = mat[i][j];
		}
	}
	return;
}

void b_rotate(int cube[MAX_N][MAX_N][MAX_N], int n, int layer) {
	int mat[MAX_N][MAX_N] = {{0}};
	for (int j = n-1, cube_i = 0; j >= 0; j--, cube_i++) {
		for (int i = n-1, cube_j = n-1; i >= 0; i--, cube_j--) {
			mat[i][j] = cube[cube_i][cube_j][layer];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cube[i][j][layer] = mat[i][j];
		}
	}
	return;
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int cube[MAX_N][MAX_N][MAX_N] = {0};
	init_cube(cube, n);
	int type, layer;
	while (scanf("%d%d", &type, &layer) != EOF) {
		switch (type) {
			case GREEN:
				g_rotate(cube, n, layer);
				break;
			case BLUE:
				b_rotate(cube, n, layer);
				break;
			default:
				break;
		}
	}
	print_cube(cube, n);
	return 0;
}
