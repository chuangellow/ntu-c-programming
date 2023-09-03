#include <stdio.h>

int main(void) {
    int size = 0;
    scanf("%d", &size);
    int prev;
    scanf("%d", &prev);
    if (size == 1) {
        printf("%d 1 %d\n", prev, prev);
        return 0;
    }
    int now;
    scanf("%d", &now);
    int diff = now - prev, sum = now + prev, num_int = 2, first_int = prev;
    int out_sum = sum, out_num_int = num_int, out_first_int = first_int;
    prev = now;
    while (--size > 1) {
        scanf("%d", &now);
        if ((now - prev) != diff) {
            if (sum > out_sum || (sum == out_sum && (num_int > out_num_int || (num_int == out_num_int && first_int > out_first_int)))) {
                out_sum = sum;
                out_num_int = num_int;
                out_first_int = first_int;
            }
            sum = now;
            num_int = 1;
            first_int = now;
            diff = now - prev;
        } else {
            sum += now;
            num_int++;
        }
        prev = now;
    }

    // Compare for the last series
    if (sum > out_sum || (sum == out_sum && (num_int > out_num_int || (num_int == out_num_int && first_int > out_first_int)))) {
        out_sum = sum;
        out_num_int = num_int;
        out_first_int = first_int;
    }
    printf("%d %d %d\n", out_sum, out_num_int, out_first_int);
    return 0;
}

