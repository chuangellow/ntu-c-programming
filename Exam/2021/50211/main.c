#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STR_LEN 1000000

typedef struct info {
	bool valid;
	int result;
} INFO;

int parse_num(const char expression[STR_LEN], int *start) {
	int val = 0;
	while (isdigit(expression[*start])) {
		val = val * 10 + (expression[*start] - '0');
		*start = *start + 1;
	}
	return val;
}

INFO cal_exp(const char expression[STR_LEN], int *pos) {
	INFO ret = {.result = 0, .valid = true};
	if (expression[*pos] != '(') {
		ret.valid = false;
		return ret;
	}
	*pos = *pos + 1;
	int left_val = 0, right_val = 0;
	char op = '\0';
	if (expression[*pos] == '(') {
		INFO info_result = cal_exp(expression, pos);
		if (!info_result.valid) {
			ret.valid = false;
			return ret;
		}
		left_val = info_result.result;
		op = expression[*pos];
		*pos = *pos + 1;

		if (expression[*pos] != '(') {
			ret.valid = false;
			return ret;
		}
		info_result = cal_exp(expression, pos);
		if (!info_result.valid) {
			ret.valid = false;
			return ret;
		}
		right_val = info_result.result;
	}
	else if (isdigit(expression[*pos])) {
		left_val = parse_num(expression, pos);
		op = expression[*pos];
		*pos = *pos + 1;
		if (!(isdigit(expression[*pos]))) {
			ret.valid = false;
			return ret;
		}
		right_val = parse_num(expression, pos);
	}
	else {
		ret.valid = false;
		return ret;
	}

	if (expression[*pos] != ')') {
		ret.valid =false;
		return ret;
	}

	switch (op) {
		case '+':
			ret.result = left_val + right_val;
			break;
		case '-':
			ret.result = left_val - right_val;
			break;
		case '*':
			ret.result = left_val * right_val;
			break;
		case '/':
			ret.result = left_val / right_val;
			break;
		default:
			ret.valid = false;
			return ret;
	}
	*pos = *pos + 1;
	return ret;
}

int main(void) {
	char expression[STR_LEN] = {'\0'};
	while (scanf("%s", expression) != EOF) {
		int pos = 0;
		INFO ret = cal_exp(expression, &(pos));
        if (ret.valid && pos == strlen(expression)) {
            printf("%d\n", ret.result);
        } else {
            printf("invalid\n");
        }
	}
	return 0;
}
