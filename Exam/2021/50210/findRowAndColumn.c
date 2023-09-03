#include <stddef.h>
#include <stdio.h>

void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol) {
	int idx = 0;
	while (ptr[idx] != NULL && start[idx] != NULL) {
		ansRow[idx] = (ptr[idx] - start[idx]) / Col[idx];
		ansCol[idx] = (ptr[idx] - start[idx]) % Col[idx];
		idx++;
	}
	return;
}
