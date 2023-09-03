#include <stdio.h>

int main(void) {
	int n = 6;
	int num[n];
	int perimeter = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &(num[i]));
		perimeter += num[i];
	}
	perimeter *= 2;
	int area = 0;
	int length = 0;
	for (int i = 1; i < n; i+=2) {
		length += num[i];
	}
	for (int i = 0; i < n; i+=2) {
		area += num[i] * length;
		if (i+1 < n) length -= num[i+1];
	}

	printf("%d\n%d\n", perimeter, area);
	return 0;
}
