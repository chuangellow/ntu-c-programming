#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define P_SIZE 200
#define STR_SIZE 200

typedef struct P_info {
	int idx;
	int value;
} P_INFO;

int find_value_in_L(char c, char L[26]);
int find_min(P_INFO P_info[P_SIZE], int P_len);

void mergeString(char** P, char L[26], char* A){
	int P_len = 0, i = 0;
	while (P[i] != NULL) {
		P_len++;
		i++;
	}
	P_INFO P_info[P_SIZE];
	// Initialization
	for (int i = 0; i < P_len; i++) {
		P_info[i].value = find_value_in_L(P[i][0], L);
		P_info[i].idx = 0;
	}

	bool flag = true;
	int count = 0;
	while (flag) {
		int min = find_min(P_info, P_len);
		if (min == -1) {
			flag = false;
		}
		else {
			int idx = P_info[min].idx;
			A[count] = P[min][idx];
			P_info[min].idx++;
			P_info[min].value = find_value_in_L(P[min][idx+1], L);
			count++;
		}
	}
	return;
}

int find_value_in_L(char c, char L[26]) {
	for (int i = 0; i < 26; i++) {
		if (c == L[i]) {
			return i;
		}
	}
	return 32;
}

int find_min(P_INFO P_info[P_SIZE], int P_len) {
	int min_idx = -1, min_value = 30;
	for (int i = 0; i < P_len; i++) {
		if (P_info[i].value < min_value) {
			min_idx = i;
			min_value = P_info[i].value;
		}
	}
	return min_idx;
}
