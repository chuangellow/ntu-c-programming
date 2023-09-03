#include <stdio.h>
#include <stdlib.h>
#include "readchar.h"

int main(void) {
	char input = '\0';
	while ((input = readchar()) != EOF) {
		printf("%c", input);
	}
	return 0;
}
