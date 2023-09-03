#include <stdio.h>
#include <string.h>

#define STR_NUM 3
#define STR_LEN 20

int find_element(char token[STR_LEN], int start, int key) {
	for (int i = start; i < strlen(token); i++) {
		if (token[i] == key) return i;
	}
	return -1;
}


int lcs(char tokens[STR_NUM][STR_LEN], int i, int j, int k) {
	if (i >= strlen(tokens[0])) return 0;
	if (j >= strlen(tokens[1])) return 0;
	if (k >= strlen(tokens[2])) return 0;
	char c1 = tokens[0][i];
	char c2 = tokens[1][j];
	char c3 = tokens[2][k];
	if (c1 == c2 && c2 == c3) {
		return lcs(tokens, i+1, j+1, k+1) + 1;
	}
	else {
		int val[4] = {0};
		int next_j = find_element(tokens[1], j, c1);
		int next_k = find_element(tokens[2], k, c1);
		if (next_j != -1 && next_k != -1) {
			val[0] = lcs(tokens, i+1, next_j+1, next_k+1) + 1;
		}
		int next_i = find_element(tokens[0], i, c2);
		next_k = find_element(tokens[2], k, c2);
		if (next_i != -1 && next_k != -1) {
			val[1] = lcs(tokens, next_i+1, j+1, next_k+1) + 1;
		}
		next_i = find_element(tokens[0], i, c3);
		next_j = find_element(tokens[1], j, c3);
		if (next_i != -1 && next_j != -1) {
			val[2] = lcs(tokens, next_i+1, next_j+1, k+1) + 1;
		}
		val[3] = lcs(tokens, i+1, j+1, k+1);
		int max = -1000;
		for (int i = 0; i < 4; i++) {
			if (val[i] > max) {
				max = val[i];
			}
		}
		return max;
	}
}

int main(void) {
	char line[STR_NUM*STR_LEN];
	while (fgets(line, STR_NUM * STR_LEN, stdin) != NULL) {
		char tokens[STR_NUM][STR_LEN] = {{'\0'}};
		char* token;
		const char delim[3] = " \n";
		token = strtok(line, delim);
		for (int i = 0; i < STR_NUM; i++) {
			strncpy(tokens[i], token, STR_LEN);
			token = strtok(NULL, delim);
		}
		int length = lcs(tokens, 0, 0, 0);
		printf("%d\n", length);
	}
	return 0;
}
