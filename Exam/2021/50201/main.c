#include <stdio.h>

#define MAX_R 600
#define MAX_C 600

enum {
	DOWN = 1,
	LEFT = 2,
	DIAG = 3,
};

void init_paper(int paper[MAX_R][MAX_C], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &(paper[i][j]));
		}
	}
	return;
}

void print_paper(int paper[MAX_R][MAX_C], int start_r, int r, int c, int end_c) {
	for (int i = start_r; i < r; i++) {
		for (int j = 0; j < end_c; j++) {
			printf("%d ", paper[i][j]);
		}
		printf("\n");
	}
	return;
}

void down_folding(int paper[MAX_R][MAX_C], int* start_r, int end_c, int k) {
	for (int s1 = 2*k-1, s2 = 0; s1 >=k; s1--, s2++) {
		for (int j = 0; j < end_c; j++) {
			paper[*start_r+s1][j] += paper[*start_r+s2][j];
		}
	}
	*start_r = *start_r + k;
	return;
}

void left_folding(int paper[MAX_R][MAX_C], int start_r, int* end_c, int r, int k) {
	for (int s1 = 2*k, s2 = 1; s1 > k; s1--, s2++) {
		for (int i = start_r; i < r; i++) {
			paper[i][*end_c-s1] += paper[i][*end_c-s2];
		}
	}
	*end_c = *end_c - k;
	return;
}

void diag_folding(int paper[MAX_R][MAX_C], int start_r, int end_c, int k) {
	int diag_i = start_r, diag_j = end_c - k;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i > j) {
				paper[i+start_r][diag_j+j] += paper[j+start_r][diag_j+i];
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (i < j) {
				paper[i+start_r][diag_j+j] = 0;
			}
		}
	}
	return;
}

int main(void) {
	int r, c;
	scanf("%d%d", &r, &c);
	int paper[MAX_R][MAX_C] = {{0}};
	init_paper(paper, r, c);
	int start_r = 0, end_c = c;
	int type, k;
	while (scanf("%d%d", &type, &k) != EOF) {
		switch (type) {
			case DOWN:
				down_folding(paper, &start_r, end_c, k);
				break;
			case LEFT:
				left_folding(paper, start_r, &end_c, r, k);
				break;
			case DIAG:
				diag_folding(paper, start_r, end_c, k);
				break;
			default:
				break;
		}
	}
	print_paper(paper, start_r, r, c, end_c);
	return 0;
}
