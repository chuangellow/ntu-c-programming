#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 100
#define MAX_1D_SIZE ((MAX_SIZE*(MAX_SIZE+1)*(2*MAX_SIZE+1))/6)
#define DEBUG

typedef struct up_most_info {
	int layer;
	int i;
	int j;
} UM_INFO;

#ifdef DEBUG
void print_cube(int cube[MAX_1D_SIZE], int N);
void print_table(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N);
#endif

void read_input(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N);
void update_table(UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int idx, int layer, int i, int j);

int get_largest(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N, int i);
void heapify(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N, int i);
void make_heap(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N);
UM_INFO extract_max(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int* N);
void insert_heap(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int* N, UM_INFO key);

int cube[MAX_1D_SIZE];
UM_INFO up_most_table[MAX_SIZE*MAX_SIZE];

int main(void) {
	int N;
	scanf("%d", &N);
	int table_size = N*N;
	read_input(cube, up_most_table, N);
	make_heap(cube, up_most_table, table_size);
	#ifdef DEBUG
	//print_cube(cube, N);
	//print_table(cube, up_most_table, table_size);
	#endif
	for (int i = 0; i < (N*(N+1)*(2*N+1)/6); i++) {
		UM_INFO max_info = extract_max(cube, up_most_table, &(table_size));
		int max_index_1D = max_info.layer*(max_info.layer+1)*(2*max_info.layer+1)/6 + max_info.i*(max_info.layer+1) + max_info.j;
		int next_index_1D = (max_info.layer+1)*((max_info.layer+1)+1)*(2*(max_info.layer+1)+1)/6 + max_info.i*(max_info.layer+2) + max_info.j;
		printf((i == (N*(N+1)*(2*N+1)/6)-1)? "%d": "%d ", cube[max_index_1D]);
		if (max_info.layer + 1 < N && cube[next_index_1D] != 0) {
			UM_INFO new_element;
			new_element.layer = max_info.layer+1;
			new_element.i = max_info.i;
			new_element.j = max_info.j;
			insert_heap(cube, up_most_table, &(table_size), new_element);
		}
	}
	return 0;
}

#ifdef DEBUG
void print_cube(int cube[MAX_1D_SIZE], int N) {
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				int index_1D = layer*(layer+1)*(2*layer+1)/6 + i*(layer+1) + j;
				printf("%d ", cube[index_1D]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return;
}

void print_table(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int table_size) {
	printf("Value: \n");
	for (int i = 0; i < table_size; i++) {
		int index_1D = up_most_table[i].layer*(up_most_table[i].layer+1)*(2*up_most_table[i].layer+1)/6 + up_most_table[i].i*(up_most_table[i].layer+1) + up_most_table[i].j;
		printf("%d ", cube[index_1D]);
	}
	printf("\n");
	printf("Layer: \n");
	for (int i = 0; i < table_size; i++) {
		printf("%d ", up_most_table[i].layer);
	}
	printf("\n");
	return;
}
#endif

void update_table(UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int idx, int layer, int i, int j) {
	up_most_table[idx].layer = layer;
	up_most_table[idx].i = i;
	up_most_table[idx].j = j;
	return;
}

void read_input(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N) {
	int count = 0;
	for (int layer = 0; layer < N; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				int index_1D = layer*(layer+1)*(2*layer+1)/6 + i*(layer+1) + j;
				scanf("%d", &(cube[index_1D]));
				if (layer == 0) {
					update_table(up_most_table, count, layer, i, j);
					count+=1;
				}
				if (layer > 0) {
					if (i == layer || j == layer) {
						update_table(up_most_table, count, layer, i, j);
						count+=1;
					}
				}
			}
		}
	}
	return;
}

int get_largest(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	int l_index_1D = up_most_table[l].layer*(up_most_table[l].layer+1)*(2*up_most_table[l].layer+1)/6 + up_most_table[l].i*(up_most_table[l].layer+1) + up_most_table[l].j;
	int i_index_1D = up_most_table[i].layer*(up_most_table[i].layer+1)*(2*up_most_table[i].layer+1)/6 + up_most_table[i].i*(up_most_table[i].layer+1) + up_most_table[i].j;
	int largest_index_1D = i_index_1D;
	if (l < N && cube[l_index_1D] > cube[i_index_1D]) {
		largest = l;
		largest_index_1D = l_index_1D;
	}
	int r_index_1D = up_most_table[r].layer*(up_most_table[r].layer+1)*(2*up_most_table[r].layer+1)/6 + up_most_table[r].i*(up_most_table[r].layer+1) + up_most_table[r].j;
	if (r < N && cube[r_index_1D] > cube[largest_index_1D]) {
		largest = r;
	}
	return largest;
}

void heapify(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N, int i) {
	int largest = get_largest(cube, up_most_table, N, i);
	while (largest != i) {
		UM_INFO temp = up_most_table[i];
		up_most_table[i] = up_most_table[largest];
		up_most_table[largest] = temp;
		i = largest;
		largest = get_largest(cube, up_most_table, N, i);
	}
	return;
}

void make_heap(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int N) {
	for (int i = (N-1) / 2; i >= 0; i--) {
		heapify(cube, up_most_table, N, i);
	}
	return;
}

UM_INFO extract_max(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int* N) {
	if (*N < 1) printf("No element in the heap!\n");
	UM_INFO max = up_most_table[0];
	up_most_table[0] = up_most_table[*N-1];
	*N = *N - 1;
	heapify(cube, up_most_table, *N, 0);
	return max;
}

void insert_heap(int cube[MAX_1D_SIZE], UM_INFO up_most_table[MAX_SIZE*MAX_SIZE], int* N, UM_INFO key) {
	*N = *N + 1;
	int i = *N - 1;
	up_most_table[i] = key;
	int parent = (i-1) / 2;
	int i_index_1D = up_most_table[i].layer*(up_most_table[i].layer+1)*(2*up_most_table[i].layer+1)/6 + up_most_table[i].i*(up_most_table[i].layer+1) + up_most_table[i].j;
	int parent_index_1D = up_most_table[parent].layer*(up_most_table[parent].layer+1)*(2*up_most_table[parent].layer+1)/6 + up_most_table[parent].i*(up_most_table[parent].layer+1) + up_most_table[parent].j;
	while ((i > 0) && cube[parent_index_1D] < cube[i_index_1D]) {
		UM_INFO temp = up_most_table[(i-1)/2];
		up_most_table[(i-1)/2] = up_most_table[i];
		up_most_table[i] = temp;
		i = (i-1) / 2;
		parent = (i-1) / 2;
		i_index_1D = up_most_table[i].layer*(up_most_table[i].layer+1)*(2*up_most_table[i].layer+1)/6 + up_most_table[i].i*(up_most_table[i].layer+1) + up_most_table[i].j;
		parent_index_1D = up_most_table[parent].layer*(up_most_table[parent].layer+1)*(2*up_most_table[parent].layer+1)/6 + up_most_table[parent].i*(up_most_table[parent].layer+1) + up_most_table[parent].j;
	}
	return;
}
