#include <stdio.h>

int num_digits(int num) {
	if (num < 10) {
		return 1;
	}
	return num_digits(num / 10) + 1;
}

int main(void) {
	int temp;
	int max = -1000000000;
	int max_digit = 1000000000;
	int result = 0;
	while (scanf("%d", &temp) != EOF) {
		int num = temp;
		int digit = num_digits(temp);
		int sum = 0;
		for (int i = 0; i < digit; i++) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum >= max) {
			if (digit < max_digit) {
				max = sum;
				max_digit = digit;
				result = num;
			}
			else if (digit == max_digit) {
				if (num > result) {
					max = sum;
					max_digit = digit;
					result = num;
				}
			}
		}
	}
	printf("%d\n", result);
	return 0;
}
