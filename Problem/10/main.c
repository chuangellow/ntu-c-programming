#include <stdio.h>

int power(int n, int i) {
	if (i == 0) return 1;
	return n * power(n, i - 1);
}

int main(void) {
	int n, i;
	scanf("%d%d", &n, &i);
	printf("%d\n", power(n, i));
	return 0;
}
