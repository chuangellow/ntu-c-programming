#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 101
#define MAX_M 101

void init_tower(char tower[MAX_M][MAX_N][MAX_N], int n, int m) {
	char escape;
	scanf("%c", &(escape));
	for (int layer = 0; layer < m; layer++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char temp = '\0';
				scanf("%c", &(temp));
				tower[layer][i][j] = temp;
			}
			scanf("%c", &(escape));
		}
	}
	return;
}

typedef struct up_most_info {
	char s[MAX_M];
    int layer;
    int i;
    int j;
} UM_INFO;

#ifdef DEBUG
void print_tower(char tower[MAX_M][MAX_N][MAX_N], int n, int m) {
	for (int layer = 0; layer < m; layer++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", tower[layer][i][j]);
			}
			printf("\n");
		}
	}
	return;
}
#endif

void update_exposed_heap(UM_INFO exposed_heap[MAX_N*MAX_N], char tower[MAX_M][MAX_N][MAX_N], int i, int j, const int n, const int m) {
	char temp[2*MAX_M] = {'\0'};
	int count = 0;
	int layer = exposed_heap[i*n+j].layer;
	for (; layer < m && tower[layer][i][j] != '0'; layer++, count++) {
		temp[count] = tower[layer][i][j];
	}
	count++;
	temp[count] = '\0';
	strncpy(exposed_heap[i*n+j].s, temp, count);
	exposed_heap[i*n+j].i = i;
	exposed_heap[i*n+j].j = j;
	exposed_heap[i*n+j].layer = layer + 1;
	return;
}

void init_exposed_heap(UM_INFO exposed_heap[MAX_N*MAX_N], char tower[MAX_M][MAX_N][MAX_N], const int n, const int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			exposed_heap[i*n+j].i = -1;
			exposed_heap[i*n+j].j = -1;
			exposed_heap[i*n+j].layer = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			update_exposed_heap(exposed_heap, tower, i, j, n, m);
		}
	}
	return;
}

void print_heap(UM_INFO exposed_heap[MAX_N*MAX_N], const int n) {
	printf("string:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("i: %d, j: %d:", i, j);
			printf("%s", exposed_heap[i*n+j].s);
			printf("\n");
		}
	}
	printf("layer:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("i: %d, j: %d:", i, j);
			printf("%d", exposed_heap[i*n+j].layer);
			printf("\n");
		}
	}
	printf("i and j:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("i: %d, j: %d:", i, j);
			printf("i:%d, j:%d", exposed_heap[i*n+j].i, exposed_heap[i*n+j].j);
			printf("\n");
		}
	}
	return;
}

int get_largest(UM_INFO exposed_heap[MAX_N*MAX_N], int i, int heap_size) {
	int left = 2*i+1, right = 2*i+2;
	int largest = i;
	if (left < heap_size && strcmp(exposed_heap[i].s, exposed_heap[left].s) < 0) {
		largest = left;
	}
	if (right < heap_size && strcmp(exposed_heap[largest].s, exposed_heap[right].s) < 0) {
		largest = right;
	}
	return largest;
}

void swap(UM_INFO exposed_heap[MAX_N*MAX_N], int i, int j) {
	UM_INFO temp = exposed_heap[i];
	exposed_heap[i] = exposed_heap[j];
	exposed_heap[j] = temp;
	return;
}

void heapify(UM_INFO exposed_heap[MAX_N*MAX_N], int i, int heap_size) {
	int largest = get_largest(exposed_heap, i, heap_size);
	while (largest != i) {
		swap(exposed_heap, i, largest);
		i = largest;
		largest = get_largest(exposed_heap, i, heap_size);
	}
	return;
}

void build_max_heap(UM_INFO exposed_heap[MAX_N*MAX_N], int heap_size) {
	for (int i = heap_size / 2 - 1; i >= 0; i--) {
		heapify(exposed_heap, i, heap_size);
	}
}

UM_INFO heap_extract_max(UM_INFO exposed_heap[MAX_N*MAX_N], int *heap_size) {
	if (*heap_size < 0) {
		printf("heap is empty\n");	
	}
	UM_INFO max = exposed_heap[0];
	exposed_heap[0] = exposed_heap[*heap_size-1];
	*heap_size = *heap_size - 1;
	heapify(exposed_heap, 0, *heap_size);
	return max;
}

UM_INFO find_next_um_info(UM_INFO max, char tower[MAX_M][MAX_N][MAX_N], int n, int m) {
	int count = 0;
	char temp[2*MAX_M] = {'\0'};
	int layer = max.layer;
	UM_INFO ret;
	for (; layer < m && tower[layer][max.i][max.j] != '0'; layer++, count++) {
		temp[count] = tower[layer][max.i][max.j];
	}
	count++;
	temp[count] = '\0';
	strncpy(ret.s, temp, count);
	ret.layer = layer+1;
	ret.i = max.i;
	ret.j = max.j;
	return ret;
}

void heap_insert(UM_INFO exposed_heap[MAX_N*MAX_N], UM_INFO next_max, int *heap_size) {
	*heap_size = *heap_size+1;
	int i = *heap_size - 1;
	exposed_heap[i] = next_max;
	while (i > 0 && strcmp(exposed_heap[(i-1)/2].s, exposed_heap[i].s) < 0) {
		swap(exposed_heap, i, (i-1)/2);
		i = (i-1)/2;
	}
	return;
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	char tower[MAX_M][MAX_N][MAX_N];
	init_tower(tower, n, m);
#ifdef DEBUG
	print_tower(tower, n, m);
#endif
	UM_INFO exposed_heap[MAX_N*MAX_N];
	init_exposed_heap(exposed_heap, tower, n, m);
	int heap_size = (n)*(n);
	build_max_heap(exposed_heap, heap_size);
	while (heap_size > 0) {
		UM_INFO max = heap_extract_max(exposed_heap, &(heap_size));
		UM_INFO next_max = find_next_um_info(max, tower, n, m);
		printf("%s\n", max.s);
		if (next_max.s[0] != '\0') {
			heap_insert(exposed_heap, next_max, &heap_size);
		}
	}
	return 0;
}
