#include <stdio.h>

int main(void) {
	int height, width, depth;
	scanf("%d %d %d", &height, &width, &depth);
	printf("%d\n", 2 * (height * width + width * depth + depth * height));
	printf("%d\n", height * width * depth);
	return 0;
}
