#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define ARRAY_SIZE 20000

int main(void) {
    int k;
    scanf("%d", &k);
    assert(((k >= 2) && (k <= 20000)));
    int cups_cap[ARRAY_SIZE] = {0};
    for (int i = 0; i < k; i++) {
        scanf("%d", &(cups_cap[i]));
    }
    int water_volume[ARRAY_SIZE] = {0};
    for (int i = 0; i < k; i++) {
        scanf("%d", &(water_volume[i]));
    }
    int i, j;
    while (scanf("%d%d", &i, &j) != EOF) {
        if ((i != k) && (j != k)) {
            int amount = water_volume[i];
            amount = (cups_cap[j] < amount + water_volume[j]) ? cups_cap[j] - water_volume[j]: amount;
            water_volume[i] -= amount;
            water_volume[j] += amount;
        }
        else if (i == k) {
            water_volume[j] = cups_cap[j];
        }
        else if (j == k) {
            water_volume[i] = 0;
        }
    } 
    for (int i = 0; i < k; i++) {
        printf((i == k-1) ? "%d\n": "%d ", water_volume[i]);
    }
    return 0;
}
