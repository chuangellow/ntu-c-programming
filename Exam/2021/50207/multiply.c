#include "multiply.h"
#include <stddef.h>

void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC) {
	int idx = 0;
	while (arrayA[idx] != NULL && arrayB[idx] != NULL) {
		A* matrixA = (A*) arrayA[idx];
		B* matrixB = (B*) arrayB[idx];
		C* matrixC = (C*) arrayC[idx];
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < ROW; j++) {
				(*matrixC)[i][j] = 0;
				for (int k = 0; k < COL; k++) {
					(*matrixC)[i][j] += (*matrixA)[i][k] * (*matrixB)[k][j];
				}
			}
		}
		idx++;
	}
	return;
}
