#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 9

void permutation(int depth, const int n, int nums[MAX_N], int path[MAX_N], bool used[MAX_N]) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            path[depth] = nums[i];
            used[i] = true;
            permutation(depth + 1, n, nums, path, used);
            used[i] = false;
        }
    }
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main(void) {
	int n;
	scanf("%d", &n);
    int nums[MAX_N], path[MAX_N];
    bool used[MAX_N] = {false};
	for (int i = 0; i < n; i++) {
		scanf("%d", &(nums[i]));
	}
	qsort(nums, n, sizeof(int), cmpfunc);
	permutation(0, n, nums, path, used);
	return 0;
}
