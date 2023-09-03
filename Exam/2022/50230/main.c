#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
 
#define TABLE_SIZE 100000
#define CAPACITY 10
 
int hash_function(int k, int S) {
    return (77 * k + 2222) % S;
}
 
void print_array(int table[TABLE_SIZE][CAPACITY], int S, int C) {
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    return;
}
 
int query_table(int table[TABLE_SIZE][CAPACITY], int S, int C, int k) {
    int hash_value = hash_function(k, S);
    bool found = false;
    for (int i = 0; i < C; i++) {
        int table_value = table[hash_value][i];
        if (table_value == k) {
            table[hash_value][i] = 0;
            return hash_value;
        }
    }
    for (int i = 0; i < C; i++) {
        int table_value = table[hash_value][i];
        if (table_value == 0) {
            table[hash_value][i] = k;
            return -1;
        }
    }
    return -1;
}
 
int main(void) {
    int S, C;
    scanf("%d%d", &S, &C);
    int table[TABLE_SIZE][CAPACITY] = {0};
    int k;
    while (scanf("%d", &k) != EOF) {
        int idx = query_table(table, S, C, k);
        if (idx != -1) {
            printf("%d %d\n", k, idx);
        }
    }
    return 0;
}
