#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cyc_check(char* tok) {
	const char keywords[5][6] = {"if", "case", "while", "for"}; 
	for (int i = 0; i < 5; i++) {
		if (strcmp(tok, keywords[i]) == 0) return 1;
	}
	if (strchr(tok, '?') != NULL) return 1;
	return 0;
}

int main(void) {
	char line[1000];
	const char delim[7] = " ()\n\t";
	int cyc_num = 0;
	while (fgets(line, sizeof(line), stdin) != NULL) {
		char* tok;
		tok = strtok(line, delim);
		while (tok != NULL) {
			cyc_num += cyc_check(tok);
			tok = strtok(NULL, delim);
		}
	}
	printf("%d", cyc_num);
	return 0;
}
