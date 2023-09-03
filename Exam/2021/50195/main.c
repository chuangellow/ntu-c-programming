#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int occ[3] = {0};
	int max[3] = {-1, -1, -1}, second_max[3] = {-1, -1, -1};
	int pos[3][2] = {0};
	int max_pos[3][2] = {0};
	int second_max_pos[3][2] = {0};
	int temp;
	int count = 0;
	while (scanf("%d", &temp) != EOF) {
		int idx = temp-1;
		pos[idx][occ[idx]] = count;
		occ[idx]++;
		if (occ[idx] == 2) {
			int dis = pos[idx][1] - pos[idx][0];
#ifdef DEBUG
			printf("temp: %d, pos[0]: %d, pos[1]: %d, dis: %d\n", temp, pos[idx][0], pos[idx][1], dis);
#endif
			if (dis == second_max[idx]) {
				second_max_pos[idx][0] = pos[idx][0];
				second_max_pos[idx][1] = pos[idx][1];
			}
			else if (dis == max[idx]) {
				max[idx] = dis;
				max_pos[idx][0] = pos[idx][0];
				max_pos[idx][1] = pos[idx][1];
			}
			else if (dis > max[idx]) {
				second_max[idx] = max[idx];
				second_max_pos[idx][0] = max_pos[idx][0];
				second_max_pos[idx][1] = max_pos[idx][1];
				max[idx] = dis;
				max_pos[idx][0] = pos[idx][0];
				max_pos[idx][1] = pos[idx][1];
			}
			else if (dis < max[idx] && dis > second_max[idx]) {
				second_max[idx] = dis;
				second_max_pos[idx][0] = pos[idx][0];
				second_max_pos[idx][1] = pos[idx][1];
			}
			occ[idx] = 1;
			pos[idx][0] = pos[idx][1];
		}
		count++;
#ifdef DEBUG
		printf("temp: %d, max: %d, second_max: %d\n", temp, max[idx], second_max[idx]);
#endif
	}
	for (int i = 0; i < 3; i++) {
		printf("%d %d %d\n", second_max[i], second_max_pos[i][0], second_max_pos[i][1]);
	}
	return 0;
}
