#include <stdio.h>

int main(void) {
	int result = 0;
	int l_value = 0, r_value = 1;
	char temp;
	while (scanf("%c", &temp) != EOF) {
		switch (temp) {
			case '!':
				l_value *= 10;
				l_value += 1;
				break;
			case '@':
				l_value *= 10;
				l_value += 2;
				break;
			case '#':
				l_value *= 10;
				l_value += 3;
				break;
			case '$':
				l_value *= 10;
				l_value += 4;
				break;
			case '%':
				l_value *= 10;
				l_value += 5;
				break;
			case '^':
				l_value *= 10;
				l_value += 6;
				break;
			case '&':
				l_value *= 10;
				l_value += 7;
				break;
			case '(':
				l_value *= 10;
				l_value += 9;
				break;
			case ')':
				l_value *= 10;
				l_value += 0;
				break;
			case '*':
				r_value *= l_value;
				l_value = 0;
				break;
			case '+':
				result += r_value * l_value;
				l_value = 0;
				r_value = 1;
				break;
			default:
				break;
		}
	}
	result += r_value * l_value;
	printf("%d", result);
	return 0;
}
