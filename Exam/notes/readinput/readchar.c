#include "readchar.h"

char readchar() {
	static int n = 1 << 20;
	static char buffer[1 << 20];
	static char *now = buffer, *end = buffer;
	if (now == end) {
		if ((end = buffer + fread(buffer, 1, n, stdin)) == buffer) {
			return EOF;
		}
		now = buffer;
	}
	return *now++;
}
