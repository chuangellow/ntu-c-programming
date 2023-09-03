#include <stdio.h>
#include <stdbool.h>

bool exceed_k(int num, int k) {
	bool flag = false;
	int prev = num % 10;
	num /= 10;
	int now;
	while (num > 0) {
		now = num % 10;
		int diff = now - prev;
		diff = (diff > 0)? diff: -diff;
		flag = flag || (diff > k);
		num /= 10;
		prev = now;
	}
	return flag;
}

int main(void) {
	int k;
	scanf("%d", &k);
	for (int num = 1000; num < 10000; num++) {
		if (!exceed_k(num, k)) {
			printf("%d\n", num);
		}
	}
	return 0;
}
