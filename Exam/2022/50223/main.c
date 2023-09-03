#include <stdio.h>

int main(void) {
	int w, a, b, c, d, e;
	scanf("%d%d%d%d%d%d", &w, &a, &b, &c, &d, &e);
	int result, length = 0;

	if (b > 0) {
		length = a + b + c + 2 * d + 2 * e + 2;
		result = w * w + length * length;
	}
	else {
		int big = (d > e) ? d: e;
		length = a + c + 2 * big + 2;
		result = w * w + length * length;
	}	

	printf("%d\n", result);

	return 0;
}
