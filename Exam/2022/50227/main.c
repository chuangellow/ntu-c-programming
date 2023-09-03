#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    int in[4];
    for (int i = 0; i < 4; i++) {
        scanf("%d", &in[i]);
    }
    bool flag = false;
    for (int a = in[0]; a >= 1 && !flag; a--) {
        for (int b = a - 1; b >= 1 && !flag; b--) {
            for (int c = b - 1; c >= 1 && !flag; c--) {
                int d = in[0] - a - b - c;
                if (d < 1 || d >= c)
                    continue;
                int sums[4] = {a + b + c + d, a*a + b*b + c*c + d*d, a*a*a + b*b*b + c*c*c + d*d*d, a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d};
                int i;
                for (i = 0; i < 4; i++) {
                    if (sums[i] != in[i])
                        break;
                }
                if (i == 4) {
                    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
                    flag = true;
                }
            }
        }
    }
    if (!flag) {
        printf("-1\n");
    }
    return 0;
}

