#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 20
#define MAX_M 60

typedef struct word_info {
	char token[MAX_M];
	int cost;
	unsigned int bit_vec;
} WORD_INFO;

int count_one_bits(unsigned int input) {
    if (input == 0) return 0;
    return ((input & 0x1) == 0x1)? count_one_bits(input >> 1) + 1: count_one_bits(input >> 1);
}

void update_info(WORD_INFO tokens[MAX_N], int idx) {
	tokens[idx].cost = 0;
	tokens[idx].bit_vec = 0x0;
	for (int j = 0; j < strlen(tokens[idx].token); j++) {
		int bit = tokens[idx].token[j] - 'a';
		tokens[idx].bit_vec |= (1 << bit);
		tokens[idx].cost += (bit + 1);
	}
	return;
}

void set_cover(int i, int cost, unsigned int set, int* min_cost, WORD_INFO tokens[MAX_N], int n) {
	if (cost >= *min_cost) return;
	if (set == ((1 << 26) - 1)) {
		*min_cost = (*min_cost < cost)? *min_cost: cost;
		return;
	}
	if (i >= n) return;
	// Ignore now
	set_cover(i+1, cost, set, min_cost, tokens, n);
	set_cover(i+1, cost + tokens[i].cost, set | tokens[i].bit_vec, min_cost, tokens, n);
}


int main(void) {
	char line[MAX_M * MAX_N];
	const char delim[3] = " \n";
	int count = 1;
	while (fgets(line, MAX_N*MAX_M, stdin) != NULL) {
		WORD_INFO tokens[MAX_N];
		char* token = strtok(line, delim);
		if (token != NULL) {
			int n = atoi(token);
			token = strtok(NULL, delim);
			for (int i = 0; i < n; i++) {
				strncpy(tokens[i].token, token, MAX_M);
				update_info(tokens, i);
				//printf("token:%s, cost:%d, bit_vec:%x\n", tokens[i].token, tokens[i].cost, tokens[i].bit_vec);
				token = strtok(NULL, delim);
			}
			int min = INT_MAX;
			set_cover(0, 0, 0, &min, tokens, n);
			printf("%d\n", min);
		}
		count++;
	}
	return 0;
}
