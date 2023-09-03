#include <stdio.h>

int count_diff_digit(int x) {
	int occ[10] = {0};
	int count = 0;
	while (x > 0) {
		int d = x % 10;
		if (occ[d] == 0) {
			occ[d]++;
			count++;
		}
		x /= 10;
	}
	return count;
}

int main(void) {
	int a, b, x;
	while (scanf("%d%d%d", &a, &b, &x) != EOF) {
		while (count_diff_digit(x) > 2) {
			x = (a * x) % b;
		}
		printf("%d\n", x);
	}
	return 0;
}
