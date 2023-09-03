#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_K MAX_N*MAX_N
#define MAX_C 10
#define STR_LEN 6

void init_hash_table(int hash_table[MAX_K][MAX_C], int K);
void init_cube(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int N);
void hash_table_insert(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int hash_table[MAX_K][MAX_C], int idx, int N, int K);
int hash_table_delete(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int hash_table[MAX_K][MAX_C], int idx, int table_idx);

int hash_function(char s[STR_LEN], int K) {
	int sum = 0;
	int s_len = strlen(s);
	for (int i = 0; i < s_len; i++) {
		sum *= 29;
		sum += (s[i] - 'a' + 1);
	}
	return sum % K;
}

void init_hash_table(int hash_table[MAX_K][MAX_C], int K) {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < MAX_C; j++) {
			hash_table[i][j] = -1;
		}
	}
	return;
}

void init_cube(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int N) {
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				int idx = layer * MAX_N * MAX_N + i * MAX_N + j; 
				scanf("%s", cube[idx]);
			}
		}
	}
	return;
}

void hash_table_insert(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int hash_table[MAX_K][MAX_C], int idx, int N, int K) {
	if (idx >= N * MAX_N * MAX_N) return;
	int table_idx = hash_function(cube[idx], K);
	int ret = hash_table_delete(cube, hash_table, idx, table_idx);
	if (ret != -1) {
		printf("%s\n", cube[idx]);
		hash_table_insert(cube, hash_table, idx + MAX_N*MAX_N, N, K);
		hash_table_insert(cube, hash_table, ret + MAX_N*MAX_N, N, K);
		return;
	}
	for (int i = 0; i < MAX_C; i++) {
		if (hash_table[table_idx][i] == -1) {
			hash_table[table_idx][i] = idx;
			break;
		}
	}
	return;
}

int hash_table_delete(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int hash_table[MAX_K][MAX_C], int idx, int table_idx) {
	for (int i = 0; i < MAX_C; i++) {
		// if (hash_table[table_idx][i] != -1) printf("%s %s\n", cube[hash_table[table_idx][i]], cube[idx]);
		if (hash_table[table_idx][i] != -1 && strcmp(cube[hash_table[table_idx][i]], cube[idx]) == 0) {
			int found_idx = hash_table[table_idx][i];
			hash_table[table_idx][i] = -1;
			return found_idx;
		}
	}
	return -1;
}

#ifdef DEBUG
void print_cube(char cube[MAX_N*MAX_N*MAX_N][STR_LEN], int N, int K) {
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				int idx = layer * MAX_N * MAX_N + i * MAX_N + j;
				//printf("%s ", cube[idx]);
				printf("%d ", hash_function(cube[idx], K));
			}
			printf("\n");
		}
	}
}
#endif

int main(void) {
	int N;
	scanf("%d", &N);
	int K = N * N;
	char cube[MAX_N*MAX_N*MAX_N][STR_LEN];
	int hash_table[MAX_K][MAX_C];
	init_hash_table(hash_table, K);
	init_cube(cube, N);
#ifdef DEBUG
	print_cube(cube, N, K);
#endif
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int idx = ((i > j)? i: j) * MAX_N * MAX_N + i * MAX_N + j;
			hash_table_insert(cube, hash_table, idx, N, K);
		}
	}
	return 0;
}
