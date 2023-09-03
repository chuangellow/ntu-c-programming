#include <stdio.h>
#include <stdbool.h>

int main(void){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int i = 1, j = 1, count = 0;
    bool flag = 1;
    while (flag) {
        for (int temp = j; temp <= m; temp++) {
        count++;
        if (k == count) {
            flag = 0;
            printf("%d %d", i, temp);
        }
        }
        i++;
        for (int temp = i; temp <= n; temp++) {
        count++;
        if (k == count) {
            flag = 0;
            printf("%d %d", temp, j);
        }
        }
        j++;
    }
    return 0;
}
