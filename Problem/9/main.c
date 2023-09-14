#include <stdio.h>

int get_score(int x) {
	if (x <= 0) return -100;
	int score = 0;
	if (x % 3 == 0) {
		score += 3;
	}
	if (x % 5 == 0) {
		score += 5;
	}
	if (x >= 100 && x <= 200) {
		score += 50;
	}
	else {
		score -= 50;
	}
	return score;
}

int main(void) {
	int x;
	scanf("%d", &x);
	int score = get_score(x);
	printf("%d\n", score);
	return 0;
}
