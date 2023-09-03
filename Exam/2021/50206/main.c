#include <stdio.h>
#include <string.h>

#define STR_LEN 100001
#define TABLE_SIZE 26*26*26

int hash_function(char three_pattern[4]) {
	int idx = 0;
	int multiplier = 1;
	for (int i = 2; i >= 0; i--) {
		idx += (three_pattern[i] - 'a') * multiplier;
		multiplier *= 26;
	}
	return idx;
}

void print_max(int max[3], char max_s[3][4]) {
	printf("Value: \n");
	for (int i = 0; i < 3; i++) {
		printf("%d ", max[i]);
	}
	printf("\n");
	printf("String: \n");
	for (int i = 0; i < 3; i++) {
		printf("%s ", max_s[i]);
	}
	printf("\n");
	return;
}

int main(void) {
	char input[STR_LEN];
	fgets(input, STR_LEN, stdin);
	const char delim[3] = " \n";
	char *token;
	int hash_table[TABLE_SIZE] = {0};
	token = strtok(input, delim);
	int max[3] = {-1, -1, -1};
	char max_s[3][4] = {{'\0'}};
	while (token != NULL) {
		int tok_len = strlen(token);
		if (tok_len >= 3) {
			for (int i = 0; i < tok_len - 2; i++) {
				char three_pattern[4] = {'\0'};
				for (int j = i; j < i+3; j++) {
					three_pattern[j-i] = token[j];
				}
				int idx = hash_function(three_pattern);
				hash_table[idx]++;
				if (hash_table[idx] > max[0]) {
					if (strcmp(max_s[0], three_pattern) != 0) {
						if (strcmp(max_s[1], three_pattern) != 0) {
							max[2] = max[1];
							strncpy(max_s[2], max_s[1], 4);
						}
						max[1] = max[0];
						strncpy(max_s[1], max_s[0], 4);
					}
					max[0] = hash_table[idx];
					strncpy(max_s[0], three_pattern, 4);
				}
				else if (hash_table[idx] == max[0] && strcmp(max_s[0], three_pattern) > 0) {
					max[0] = hash_table[idx];
					strncpy(max_s[0], three_pattern, 4);
				}
				else if (hash_table[idx] > max[1]) {
					if (strcmp(max_s[1], three_pattern) != 0) {
						max[2] = max[1];
						strncpy(max_s[2], max_s[1], 4);
					}
					max[1] = hash_table[idx];
					strncpy(max_s[1], three_pattern, 4);
				}
				else if (hash_table[idx] == max[1] && strcmp(max_s[1], three_pattern) > 0) {
					max[1] = hash_table[idx];
					strncpy(max_s[1], three_pattern, 4);
				}
				else if (hash_table[idx] > max[2]) {
					max[2] = hash_table[idx];
					strncpy(max_s[2], three_pattern, 4);
				}
				else if (hash_table[idx] == max[2] && strcmp(max_s[2], three_pattern) > 0) {
					max[2] = hash_table[idx];
					strncpy(max_s[2], three_pattern, 4);
				}

			}
		}
		token = strtok(NULL, delim);
	}
	/*
	for (int i = 0; i < 3; i++) {
		printf("%s\n", max_s[i]);
	}
	*/
	return 0;
}
