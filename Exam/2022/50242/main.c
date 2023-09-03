#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define STR_SIZE 2000
#define TOK_SIZE 500
#define TOK_LEN 6


bool parse_exp(char tokens[TOK_SIZE][TOK_LEN], int* pos, const int size);
bool cal_exp(char tokens[TOK_SIZE][TOK_LEN], int* pos, const int size);

bool check_invalid(char tokens[TOK_SIZE][TOK_LEN], int count) {
	char possible_string[7][TOK_LEN] = {"!", "&&", "||", "(", ")", "true", "false"};
	int left_paren = 0;
	int right_paren = 0;
	for (int i = 0; i < count; i++) {
		bool is_in_possible_string = false;
		for (int j = 0; j < 7; j++) {
			if (strcmp(tokens[i], possible_string[j]) == 0) {
				is_in_possible_string = true;
				break;
			}
		}
		if (!is_in_possible_string) {
			return true;
		}
		if (strcmp(tokens[i], "(") == 0) {
			left_paren++;
		}
		else if (strcmp(tokens[i], ")") == 0) {
			right_paren++;
		}
		if (right_paren > left_paren) { 
			return true;
		}
	}
	if (left_paren != right_paren) {
		return true;
	}
	if ((left_paren == right_paren) && (left_paren == 0)) {
		return true;
	}
	return false;
}

bool parse_exp(char tokens[TOK_SIZE][TOK_LEN], int* pos, const int size) {
	if (*pos >= size || tokens[*pos][0] == '\0') {
		return false;
	}
	if (strcmp(tokens[*pos], "true") == 0) {
		*pos = *pos + 1;
		return true;
	}
	else if (strcmp(tokens[*pos], "false") == 0) {
		*pos = *pos + 1;
		return false;
	}
	else if (strcmp(tokens[*pos], "!") == 0) {
		*pos = *pos + 1;
		return !(parse_exp(tokens, pos, size));
	}
	else if (strcmp(tokens[*pos], "(") == 0) {
		*pos = *pos + 1;
		bool left = cal_exp(tokens, pos, size);
		if (*pos >= size || strcmp(tokens[*pos], ")") != 0) {
			return false;
		}
		*pos = *pos + 1;
		return left;
	}
	else {
		return false;
	}
}

bool cal_exp(char tokens[TOK_SIZE][TOK_LEN], int* pos, const int size) {
	bool result = parse_exp(tokens, pos, size);

	while (*pos < size) {
		if (strcmp(tokens[*pos], "&&") == 0) {
			*pos = *pos + 1;
			bool right_result = parse_exp(tokens, pos, size);
			result &= right_result;
		}
		else if (strcmp(tokens[*pos], "||") == 0) {
			*pos = *pos + 1;
			bool right_result = parse_exp(tokens, pos, size);
			result |= right_result;
		}
		else {
			break;
		}
	}
	return result;
}

int main(void) {
	char s[STR_SIZE] = {'\0'};
	char *delimiter = " \n";
	char tokens[TOK_SIZE][TOK_LEN] = {{'\0'}};
	while (fgets(s, STR_SIZE, stdin) != NULL) {
		int count = 0;
		char *token = strtok(s, delimiter);
		while (token != NULL) {
			strncpy(tokens[count], token, TOK_LEN-1);
			token = strtok(NULL, delimiter);
			count++;
		}
		if (check_invalid(tokens, count)) {
			printf("invalid\n");
		}
		else {
			int pos = 0;
			bool result = cal_exp(tokens, &(pos), count);
			if (pos == count && result) {
				printf("true\n");
			}
			else {
				printf("false\n");
			}
		}
	}
	return 0;
}
