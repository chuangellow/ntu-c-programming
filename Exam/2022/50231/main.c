#include <stdio.h>
#include <stdbool.h>

#define f(k, S) ((77 * k + 2222) % S)
#define MAX_N 105
#define MAX_S MAX_N*MAX_N
#define MAX_P MAX_N*MAX_N*3
#define MAX_C 10

typedef struct upper_most_table_info {
	int key;
	int occurance;
	int layer[2];
	int i[2];
	int j[2];
} UMT_INFO;

int read_input(int cube[MAX_N][MAX_N][MAX_N], UMT_INFO table[MAX_S][MAX_C], int paired_key[MAX_P], int N, int S, int C);
void print_cube(int cube[MAX_N][MAX_N][MAX_N], int N);

void init_table(UMT_INFO table[MAX_S][MAX_C], int S, int C);
void print_table(UMT_INFO table[MAX_S][MAX_C], int S, int C);
int insert_table(UMT_INFO table[MAX_S][MAX_C], int key, int S, int C, int layer, int i, int j);
int query_table(UMT_INFO table[MAX_S][MAX_C], int key, int S, int C);
void delete_and_update_table(int cube[MAX_N][MAX_N][MAX_N], UMT_INFO table[MAX_S][MAX_C], int paired_key[MAX_P], int key, int N, int S, int C, int *count);

int main(void) {
	int N, S, C;
	scanf("%d%d%d", &N, &S, &C);
	int cube[MAX_N][MAX_N][MAX_N] = {{{0}}};
	UMT_INFO table[MAX_S][MAX_C];
	init_table(table, S, C);
	int paired_key[MAX_P] = {0};
	int count = read_input(cube, table, paired_key, N, S, C);
	//print_cube(cube, N);
	for (int i = 0; i < MAX_P && paired_key[i] != 0; i++) {
		//print_table(table, S, C);
		delete_and_update_table(cube, table, paired_key, paired_key[i], N, S, C, &(count));
		printf((i+1 == MAX_P || paired_key[i+1] == 0)? "%d": "%d ", paired_key[i]);
	}
	return 0;
}

int read_input(int cube[MAX_N][MAX_N][MAX_N], UMT_INFO table[MAX_S][MAX_C], int paired_key[MAX_P], int N, int S, int C) {
	int count = 0;
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				int temp;
				scanf("%d", &(temp));
				cube[layer][i][j] = temp;
				if (layer == 0) {
					int ret = insert_table(table, temp, S, C, layer, i, j);
					if (ret == 2) {
						paired_key[count] = temp;
						count++;
					}
				}
				else if ((layer > 0) && (cube[layer-1][i][j] == 0)) {
					int ret = insert_table(table, temp, S, C, layer, i, j);
					if (ret == 2) {
						paired_key[count] = temp;
						count++;
					}
				}
			}
		}
	}
	return count;
}

void init_table(UMT_INFO table[MAX_S][MAX_C], int S, int C) {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < C; j++) {
			table[i][j].occurance = 0;
			table[i][j].key = 0;
			for (int k = 0; k < 2; k++) {
				table[i][j].layer[k] = -1;
				table[i][j].i[k] = -1;
				table[i][j].j[k] = -1;
			}
		}
	}
	return;
}

void print_cube(int cube[MAX_N][MAX_N][MAX_N], int N) {
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", cube[layer][i][j]);
			}
		printf("\n");
		}
	printf("\n");
	}
	return;
}

void print_table(UMT_INFO table[MAX_S][MAX_C], int S, int C) {
	printf("Key:\n");
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", table[i][j].key);
		}
		printf("\n");
	}
	printf("Occurance:\n");
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", table[i][j].occurance);
		}
		printf("\n");
	}
	return;
}

int query_table(UMT_INFO table[MAX_S][MAX_C], int key, int S, int C) {
	int idx = f(key, S);
	for (int i = 0; i < C; i++) {
		if (table[idx][i].key == key) return i;
	}
	return -1;
}

int insert_table(UMT_INFO table[MAX_S][MAX_C], int key, int S, int C, int layer, int i, int j) {
	int idx = f(key, S);
	int cap = query_table(table, key, S, C);
	if (cap != -1) {
		int occ = table[idx][cap].occurance;
		table[idx][cap].occurance += 1;
		table[idx][cap].layer[occ] = layer;
		table[idx][cap].i[occ] = i;
		table[idx][cap].j[occ] = j;
		return 2;
	}
	else {
		for (int k = 0; k < C; k++) {
			if (table[idx][k].key == 0) {
				table[idx][k].key = key;
				table[idx][k].occurance = 1;
				table[idx][k].layer[0] = layer;
				table[idx][k].i[0] = i;
				table[idx][k].j[0] = j;
				return 1;
			}
		}
	}
	return -1;
}

void delete_and_update_table(int cube[MAX_N][MAX_N][MAX_N], UMT_INFO table[MAX_S][MAX_C], int paired_key[MAX_P], int key, int N, int S, int C, int *count) {
	int idx = f(key, S);
	int cap = query_table(table, key, S, C);
	int paired_layer[2] = {0};
	int paired_i[2] = {-1, -1};
	int paired_j[2] = {-1, -1};
	if (cap != -1) {
		for (int o = 0; o < 2; o++) {
			paired_layer[o] = table[idx][cap].layer[o];
			paired_i[o] = table[idx][cap].i[o];
			paired_j[o] = table[idx][cap].j[o];
		}
		/*
		printf("Paired Key: %d\n", table[idx][cap].key);
		*/
		table[idx][cap].key = 0;
		table[idx][cap].occurance = 0;
		for (int o = 0; o < 2; o++) {
			table[idx][cap].layer[o] = -1;
			table[idx][cap].i[o] = -1;
			table[idx][cap].j[o] = -1;
		}
		/*
		for (int o = 0; o < 2; o++) {
			printf("Paired layer %d: %d\n", o, paired_layer[o]);
			printf("Paired i %d: %d\n", o, paired_i[o]);
			printf("Paired j %d: %d\n", o, paired_j[o]);
		}
		*/
		for (int o = 0; o < 2; o++) {
			if (paired_layer[o] < N-1 && cube[paired_layer[o] + 1][paired_i[o]][paired_j[o]] > 0) {
				int key = cube[paired_layer[o] + 1][paired_i[o]][paired_j[o]];
				int ret = insert_table(table, key, S, C, paired_layer[o]+1, paired_i[o], paired_j[o]);
				if (ret == 2) {
					paired_key[*count] = key;
					*count += 1;
				}
			}
		}
	}
	else {
		printf("The key %d doesn't exist!!!\n", key);
	}
	return;
}
