#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>

#define ARR_SIZE 64

void print_arr(bool friend[ARR_SIZE][ARR_SIZE], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf((friend[i][j])? "1 ": "0 ");
		}
		printf("\n");
	}
	return;
}

void print_element(int idx, uint64_t set, int n) {
	if (idx == n) return;
	if (set & 0x1) {
		printf("%d\n", idx);
	}
	print_element(idx+1, set >> 1, n);
	return;
}

int count_one_bits(uint64_t set) {
	if (set == 0x0) return 0;
	return ((set & 0x1)? 1: 0) + count_one_bits(set >> 1);
}

uint64_t friend_cover(int idx, uint64_t set, bool friend[ARR_SIZE][ARR_SIZE], int n, uint64_t best_set_so_far) {
    if (count_one_bits(set) >= count_one_bits(best_set_so_far) && best_set_so_far != (uint64_t)(-1)) {
        return best_set_so_far;
    }

    if (idx == n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (friend[i][j]) {
                    if (!((set & ((uint64_t)1 << i)) || (set & ((uint64_t)1 << j)))) {
                        return best_set_so_far;
                    }
                }
            }
        }

        if (count_one_bits(set) < count_one_bits(best_set_so_far) ||
           (count_one_bits(set) == count_one_bits(best_set_so_far) && set < best_set_so_far)) {
            best_set_so_far = set;
        }
        return best_set_so_far;
    }

    set |= ((uint64_t)1 << idx);
    best_set_so_far = friend_cover(idx + 1, set, friend, n, best_set_so_far);

    set &= ~((uint64_t)1 << idx);
    best_set_so_far = friend_cover(idx + 1, set, friend, n, best_set_so_far);

    return best_set_so_far;
}


int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	bool friend[ARR_SIZE][ARR_SIZE] = {0};
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		friend[a][b] = true;
		friend[b][a] = true;
	}
	//print_arr(friend, n);
	uint64_t best_set = (uint64_t)(-1);
	best_set = friend_cover(0, 0, friend, n, best_set);
	print_element(0, best_set, n);
	return 0;
}
