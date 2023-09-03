#include <stdio.h>
#include <stdbool.h>

int least_common_multiple(int a, int b);
int gcd(int a, int b);

int main(void) {
	int gears[4] = {0};
	while (scanf("%d %d %d %d", &gears[0], &gears[1], &gears[2], &gears[3]) != EOF) {
		int lcm = least_common_multiple(gears[0], gears[1]);
		for (int i = 2; i < 4; i++) {
			lcm = least_common_multiple(gears[i], lcm);
		}
		printf("%d\n", lcm / gears[0]);
	}
	return 0;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int least_common_multiple(int a, int b) {
	int num = gcd(a, b);
	return a * b / num;
}
