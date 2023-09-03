#include <stdio.h>

int value_to_seconds(int time);
int time_diff(int prev, int now);

int main(void) {
	int prev = 0, now = 0;
	scanf("%d%d", &(prev), &(now));
	int min_time_diff = time_diff(prev, now);
	prev = now;
	while (scanf("%d", &now) != EOF) {
		int diff = time_diff(prev, now);
		if (diff < min_time_diff) {
			min_time_diff = diff;
		}
		prev = now;
	}
	printf("%d", min_time_diff);
	return 0;
}

int value_to_seconds(int time) {
	int t = time;
	int seconds = 0;
	int multiplier = 1;
	for (int i = 0; i < 3; i++) {
		seconds += (t % 100) * multiplier;
		multiplier *= 60;
		t /= 100;
	}
	return seconds;
}

int time_diff(int prev, int now) {
	int prev_s = value_to_seconds(prev);
	int now_s = value_to_seconds(now);
	return (prev_s > now_s) ? prev_s - now_s: now_s - prev_s;
}
