#include <stdio.h>
#include <stdbool.h>

enum {
	ADD = 8, 
	MUL = 9,
	EQ = 0,
};

int main(void) {
	int temp;
	int result = 0;
	int l_value = 0, r_value = 1;
	while (scanf("%d", &temp) != EOF) {
		switch (temp) {
			case ADD:
				result += l_value * r_value;
				l_value = 0;
				r_value = 1;
				break;
			case MUL:
				r_value *= l_value;
				l_value = 0;
				break;
			case EQ:
				result += l_value * r_value;
				break;
			default:
				l_value *= 10;
				l_value += temp;
				break;
		}
	}
	printf("%d", result);
	return 0;
}
