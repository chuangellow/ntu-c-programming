#include <stdio.h>

#define MAX_N 100000

enum {
	TYPE_0 = 0,
	TYPE_1 = 1,
	TYPE_2 = 2,
	TYPE_3 = 3,
};

void fall_type_0(int height[MAX_N], int lft_col, int n) {
	int max_idx = 0;
	int max = height[lft_col];
	for (int i = 1; i < 3; i++) {
		if (height[lft_col+i] >= max) {
			max = height[lft_col+i];
			max_idx = i;
		}
	}
	if (max_idx == 0) {
		height[lft_col] = max + 1;
		height[lft_col+1] = max + 1;
		height[lft_col+2] = max;
	}
	else {
		height[lft_col] = max + 2;
		height[lft_col+1] = max + 2;
		height[lft_col+2] = max + 1;
	}
	return;
}

void fall_type_1(int height[MAX_N], int lft_col, int n) {
	int max_idx = 0;
	int max = height[lft_col];
	for (int i = 1; i < 3; i++) {
		if (height[lft_col+i] > max) {
			max = height[lft_col+i];
			max_idx = i;
		}
	}
	if (max_idx == 2) {
		height[lft_col] = max;
		height[lft_col+1] = max + 1;
		height[lft_col+2] = max + 1;
	}
	else {
		height[lft_col] = max + 1;
		height[lft_col+1] = max + 2;
		height[lft_col+2] = max + 2;
	}
	return;
}

void fall_type_2(int height[MAX_N], int lft_col, int n) {
	int max = height[lft_col];
	for (int i = 1; i < 3; i++) {
		if (height[lft_col+i] >= max) {
			max = height[lft_col+i];
		}
	}
	height[lft_col] = max + 1;
	height[lft_col+1] = max + 2;
	height[lft_col+2] = max + 1;
	return;
}

void fall_type_3(int height[MAX_N], int lft_col, int n) {
	int max_idx = 0;
	int max = height[lft_col];
	for (int i = 1; i < 3; i++) {
		if (height[lft_col+i] > max) {
			max = height[lft_col+i];
			max_idx = i;
		}
	}
	if (max_idx == 1 || (max_idx == 0 && (height[lft_col] == height[lft_col+1]))) {
		height[lft_col] = max + 2;
		height[lft_col+1] = max + 2;
		height[lft_col+2] = max + 2;
	}
	else {
		height[lft_col] = max + 1;
		height[lft_col+1] = max + 1;
		height[lft_col+2] = max + 1;
	}
	return;
}

void print_height(int height[MAX_N], int n) {
	for (int i = 0; i < n; i++) {
		printf((i == n-1)? "%d": "%d ", height[i]);
	}
	return;
}

int main (void) {
	int n;
	scanf("%d", &n);
	int height[MAX_N] = {0};
	int left_most_col, type;
	while (scanf("%d%d", &left_most_col, &type) != EOF) {
		switch (type) {
			case TYPE_0:
				fall_type_0(height, left_most_col, n);
				break;
			case TYPE_1:
				fall_type_1(height, left_most_col, n);
				break;
			case TYPE_2:
				fall_type_2(height, left_most_col, n);
				break;
			case TYPE_3:
				fall_type_3(height, left_most_col, n);
				break;
			default:
				break;
		}
	}
	print_height(height, n);
	return 0;
}
