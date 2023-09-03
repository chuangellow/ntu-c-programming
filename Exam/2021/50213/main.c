#include <stdio.h>

#define ARR_SIZE 100000

void print_arr(int arr[ARR_SIZE], int start, int end) {
	for (int i = start; i < end; i++) {
		printf((i == end - 1)? "%d\n": "%d ", arr[i]);
	}
	return;
}

void merge(int arr[ARR_SIZE], int start, int mid, int end) {
	int l_num = mid - start;
	int r_num = end - mid + 1;
	int L[l_num], R[r_num];
	for (int i = start; i < mid; i++) {
		L[i-start] = arr[i];
#ifdef DEBUG
		printf("L[%d]: %d ", i-start, L[i-start]);
		printf("\n");
#endif
	}
	for (int i = mid; i <= end; i++) {
		R[i-mid] = arr[i];
#ifdef DEBUG
		printf("R[%d]: %d\n", i-mid, R[i-mid]);
		printf("\n");
#endif
	}
	int i = 0, j = 0, count = 0;
	while (i < l_num || j < r_num) {
		if (i >= l_num) {
			arr[start+count] = R[j];
			j++;
			count++;
		}
		else if (j >= r_num) {
			arr[start+count] = L[i];
			i++;
			count++;
		}
		else {
			if (L[i] > R[j]) {
				arr[start+count] = R[j];
				j++;
				count++;
			}
			else if (L[i] <= R[j]) {
				arr[start+count] = L[i];
				i++;
				count++;
			}
		}
	}
	return;
}

void merge_sort(int arr[ARR_SIZE], int start, int end) {
	if (end == start) print_arr(arr, start, end+1);
	if (end > start) {
		print_arr(arr, start, end+1);
		int mid = (end + start + 1) / 2;
		merge_sort(arr, start, mid-1);
		merge_sort(arr, mid, end);
		merge(arr, start, mid, end);
		print_arr(arr, start, end+1);
	}
	return;
}

int main(void) {
	int arr[ARR_SIZE] = {0};
	int count = 0;
	while (scanf("%d", &(arr[count])) != EOF) count++;
	merge_sort(arr, 0, count-1);
	return 0;
}
