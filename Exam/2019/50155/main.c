#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f, g;
	scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
	if (d == 0) {
		printf("0\n");
		return 0;
	}
	if (g >= c) g = c;
	int depth = (a * b * d + e * f * g) / (a * b);
	if (depth >= c) printf("%d\n", c);
	else printf("%d\n", depth);
	return 0;
}
