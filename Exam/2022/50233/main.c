#include <stdio.h>
#include <assert.h>

#define ARR_SIZE 130000
#define OP_SIZE 230000

int get_largest(int A[ARR_SIZE], int i, int n);
void max_heapify(int A[ARR_SIZE], int i, int n);
void build_max_heap(int A[ARR_SIZE], int n); 
int heap_extract_max(int A[ARR_SIZE], int* n); 
void max_heap_insert(int A[ARR_SIZE], int key, int* n);
void print_arr(int A[ARR_SIZE], int n);

int main(void) {
	int n;
	scanf("%d", &n);
	int A[ARR_SIZE] = {0};
	for (int i = 1; i <= n; i++) {
		scanf("%d", &(A[i]));
	}
	int m;
	scanf("%d", &m);
	int OUT[OP_SIZE] = {0};
	build_max_heap(A, n);
	print_arr(A, n);

	int temp = 0, count = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &temp);
		if (temp == -1) {
			int max = heap_extract_max(A, &(n));
			OUT[count] = max;
			count = count + 1;
		}
		else {
			max_heap_insert(A, temp, &(n));
		}
	}
	for (int i = 0; i < count; i++) {
		printf((i == count-1)? "%d\n": "%d ", OUT[i]);
	}
	return 0;
}

void build_max_heap(int A[ARR_SIZE], int n) {
	for (int i = (n / 2); i >= 1; i--) {
		max_heapify(A, i, n);
	}
	return;
}

void max_heapify(int A[ARR_SIZE], int i, int n) {
	int large = get_largest(A, i, n);
	while (large != i) {
		int temp = A[i];
		A[i] = A[large];
		A[large] = temp;
		i = large;
		large = get_largest(A, i, n);
	}
	return;
}

int get_largest(int A[ARR_SIZE], int i, int n) {
	int left = 2 * i, right = 2 * i + 1;
	int large = i;
	if (left <= n && A[left] > A[i]) {
		large = left;
	}
	if (right <= n && A[right] > A[large]) {
		large = right;
	}
	return large;
}

int heap_extract_max(int A[ARR_SIZE], int* n) {
	assert(*n >= 1);
	int max = A[1];
	A[1] = A[*n];
	*n = *n - 1;
	max_heapify(A, 1, *n);
	return max;
}

void max_heap_insert(int A[ARR_SIZE], int key, int* n) {
	*n = *n + 1;
	int i = *n;
	A[i] = key;
	while (i > 1 && A[i / 2] < A[i]) {
		int temp = A[i];
		A[i] = A[i / 2];
		A[i / 2] = temp;
		i = i / 2;
	}
	return;
}

void print_arr(int A[ARR_SIZE], int n) {
	for (int i = 1; i <= n; i++) {
		printf((i == n)? "%d\n": "%d ", A[i]);
	}
	return;
}
