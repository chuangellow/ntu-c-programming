#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

#define MAX_N 20
#define MAX_K 10

int compare(const void *a, const void *b) {
    return (*(uint64_t *)b - *(uint64_t *)a);
}

uint64_t calculate_cost(uint64_t subset_sums[MAX_K], int k) {
    uint64_t cost = 0;
    for (int i = 0; i < k; i++) {
        cost += subset_sums[i] * subset_sums[i];
    }
    return cost;
}

uint64_t recursive_solve(int idx, int n, int k, uint64_t num[MAX_N], uint64_t subset_sums[MAX_K], uint64_t *best_cost) {
    if (idx == n) {
        uint64_t current_cost = calculate_cost(subset_sums, k);
        if (current_cost < *best_cost) {
            *best_cost = current_cost;
        }
        return current_cost;
    }

    uint64_t result = UINT64_MAX;

    for (int i = 0; i < k; i++) {
        uint64_t old_sum = subset_sums[i];
        subset_sums[i] += num[idx];

        uint64_t current_cost = calculate_cost(subset_sums, k);

        if (current_cost < *best_cost) {
            uint64_t temp_cost = recursive_solve(idx + 1, n, k, num, subset_sums, best_cost);
            if (temp_cost < result) {
                result = temp_cost;
            }
        }

        subset_sums[i] = old_sum;
    }

    return result;
}

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    uint64_t num[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%llu", &(num[i]));
    }
    qsort(num, n, sizeof(uint64_t), compare);
    uint64_t subset_sums[MAX_K] = {0};
    uint64_t best_cost = UINT64_MAX;
    uint64_t min_sum = recursive_solve(0, n, k, num, subset_sums, &best_cost);
    printf("%llu\n", min_sum);
    return 0;
}

