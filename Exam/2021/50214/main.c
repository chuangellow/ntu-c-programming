#include <stdio.h>
#define MAX_N 8

void init_mat(int mat[MAX_N][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &(mat[i][j]));
		}
	}
	return;
}

void print_mat(int mat[MAX_N][MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf((j == n - 1)? "%d\n": "%d ", mat[i][j]);
		}
	}
	return;
}

int determinant(int mat[MAX_N][MAX_N], int n) {
	print_mat(mat, n);
	if (n == 1) {
		return mat[0][0];
	}
	int ret = 0;
	int sign = 1;
	for (int k = 0; k < n; k++) {
		int temp[MAX_N][MAX_N];
		int count_i = 0, count_j = 0;
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				for (int j = 0; j < n; j++) {
					if (j != k) {
						temp[count_i][count_j] = mat[i][j];
						count_j++;
					}
				}
				count_i++;
				count_j = 0;
			}
		}
		ret += sign * mat[0][k] * determinant(temp, n-1);
		sign *= -1;
	}
	printf("determinant=%d\n", ret);
	return ret;
}

int main(void) {
	int n;
	scanf("%d", &n);
	int mat[MAX_N][MAX_N];
	init_mat(mat, n);
	determinant(mat, n);
	return 0;
}
