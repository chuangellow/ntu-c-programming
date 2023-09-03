#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool solve_witchcraft(int D, int a, int b, int c, const int A, const int B, const int C) {
	if (D == 0) return true;
	else if (D < 0) return false;
	if ((a < 0) || (b < 0) || (c < 0)) return false;
	bool result = false;
	if (a > 0) result |= solve_witchcraft(D-A, a-1, b, c, A, B, C);
	if (result) return result;
	if (b > 0) result |= solve_witchcraft(D-B, a, b-1, c, A, B, C);
	if (result) return result;
	if (c > 0) result |= solve_witchcraft(D-C, a, b, c-1, A, B, C);
	if (result) return result;
	return result;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int D, a, b, c, A, B, C;
		scanf("%d%d%d%d%d%d%d", &D, &a, &b, &c, &A, &B, &C);
		bool result = solve_witchcraft(D, a, b, c, A, B, C);
		printf((result)? "yes\n": "no\n");
	}
	return 0;
}
