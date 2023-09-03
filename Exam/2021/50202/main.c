#include <stdio.h>

#define MAX_H 200
#define MAX_W 200
#define MAX_K 50

void init_mat(int mat[MAX_H][MAX_W], int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &(mat[i][j]));
		}
	}
	return;
}

void print_mat(int mat[MAX_H][MAX_W], int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return;
}

int compute_diamond(int mat[MAX_H][MAX_W], int h, int w, int k, int i, int j) {
	int left = j - k + 1;
	int right = j + k - 1;
	int up = i - k + 1;
	int down = i + k - 1;
	if (left < 0 || right >= w || up < 0 || down >= h) {
		return -1;
	}
	int sum = 0;
	for (int s = 1; s < k; s++) {
		sum += mat[i-s][left+s];
	}
	for (int s = 1; s < k; s++) {
		sum += mat[up+s][j+s];
	}
	for (int s = 1; s < k; s++) {
		sum += mat[i+s][right-s];
	}
	for (int s = 1; s < k; s++) {
		sum += mat[down-s][j-s];
	}
	return sum;
}

int main(void) {
	int h, w, k;
	scanf("%d%d%d", &h, &w, &k);
	int mat[MAX_H][MAX_W];
	init_mat(mat, h, w);
	int max = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int value = compute_diamond(mat, h, w, k, i, j);
			if (value > max) {
				max = value;
			}
		}
	}
	printf("%d", max);
	return 0;
}
