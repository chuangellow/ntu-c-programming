#include <stdio.h>

void print_digits(int x) {
	if (x < 10) {
		printf("%d\n", x);
		return;
	}
	print_digits(x / 10);
	printf("%d\n", x % 10);
	return;
}

int main(void) {
	int x;
	scanf("%d", &x);
	print_digits(x);
	return 0;
}
