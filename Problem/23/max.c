#include <stdio.h>
int max(int *iptr[], int n) {
	int max = -100000;
	for (int i = 0; i < n; i++) {
		if (*iptr[i] > max) max = *iptr[i];
	}
	return max;
}
