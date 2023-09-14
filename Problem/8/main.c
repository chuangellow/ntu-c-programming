#include <stdio.h>

int is_triangle(int a, int b, int c) {
	if (a + b > c && a + c > b && b + c > a) {
		return 1;
	}
	return 0;
}

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", is_triangle(a, b, c));
	return 0;
}
