#include <stdio.h>
#include <stdlib.h>
#include "findRowAndColumn.h"
#define MAXN 105
 
int main() {
    int *ansRow = malloc(MAXN * sizeof(int));
    int *ansCol = malloc(MAXN * sizeof(int));
 
    int *Row = malloc(MAXN * sizeof(int));
    int *Col = malloc(MAXN * sizeof(int));
    int **ptr = (int**)malloc(MAXN * sizeof(int*));;
    int **start = (int**)malloc(MAXN * sizeof(int*));;;
 
    int R, C, r, c, N = 0;
    while (scanf("%d %d %d %d", &R, &C, &r, &c) != EOF) {
        int (*mat)[C] = malloc(sizeof *mat * R);
 
        start[N] = &mat[0][0];
        ptr[N] = &mat[r][c];
        Row[N] = R;
        Col[N] = C;
        N++;
    }
 
    start[N] = NULL, ptr[N] = NULL;
 
    findRowAndColumn(ptr, Row, Col, start, ansRow, ansCol);
 
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", ansRow[i], ansCol[i]);
    }
 
    return 0;
}
