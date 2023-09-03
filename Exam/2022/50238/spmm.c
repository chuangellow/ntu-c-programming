#include <stddef.h>
#include <stdio.h>

void sparseMatrixMult(int** A, int** B) {
	int A_i = 0;
	while (*(A + A_i) != NULL) {
		int A_row_idx = *(*(A + A_i));
		int B_i = 0;
		while (*(B + B_i) != NULL) {
			int B_col_idx = *(*(B + B_i));
			int A_j = 1, B_j = 1;
			int sum = 0;
			while (*(*(A + A_i) + A_j) != -1 && *(*(B + B_i) + B_j) != -1) {
				int A_col_idx = *(*(A + A_i) + A_j);
				int A_value = *(*(A + A_i) + A_j + 1);
				int B_row_idx = *(*(B + B_i) + B_j);
				int B_value = *(*(B + B_i) + B_j + 1);
				if (A_col_idx < B_row_idx) {
					A_j+=2;
				}
				else if (A_col_idx > B_row_idx) {
					B_j+=2;
				}
				else {
					sum += A_value * B_value;
					A_j+=2;
					B_j+=2;
				}
			}
			if (sum > 0) {
				printf("%d %d %d\n", A_row_idx, B_col_idx, sum);
			}
			B_i++;
		}
		A_i++;
	}
	return;
}
