#include <stdio.h>

int main(void) {
	int A, B, C, D, E, F, G;
	scanf("%d%d%d%d%d%d%d", &A, &B, &C, &D, &E, &F, &G);
	int edge = A + B + C + D + A * E + B * E + C * E + C * F + D * F + E * G + G + F;
	printf("%d\n", edge);
	int path = A * E * G + B * E * G + C * E * G + C * F + D * F;
	printf("%d\n", path);
	return 0;
}
