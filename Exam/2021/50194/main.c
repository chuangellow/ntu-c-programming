#include <stdio.h>

int get_digit(int num);

int main(void) {
	int k, L;
	scanf("%d%d", &k, &L);
	int temp;
	int count = 0;
	while (scanf("%d", &temp) != EOF) {
		if (temp != 0) {
			int digit = get_digit(temp);
			int t = temp % k;
			count += digit * t;
			if (count <= L) {
				for (int i = 0; i < t; i++) {
					printf("%d", temp);
				}
			}
			else if (count > L && digit * t <= L) {
				printf("\n");
				for (int i = 0; i < t; i++) {
					printf("%d", temp);
				}
				count = digit * t;
			}
			else if (count > L && digit * t > L) {
				count -= digit * t;
			}
		}
	}
	return 0;
}

int get_digit(int num) {
	int temp = num;
	int count = 0;
	while (temp > 0) {
		temp /= 10;
		count++;
	}
	return count;
}
