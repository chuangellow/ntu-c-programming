#include <stdio.h>
#include <string.h>

#define ARR_SIZE 2000
#define STR_SIZE 50

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	char arr[ARR_SIZE] = {'\0'};
	for (int i = 0; i < M; i++) {
		char s[STR_SIZE];
		scanf("%s", s);
		int pos = 0;
		scanf("%d", &(pos));
		int s_len = strlen(s);
		for (int i = pos; i < pos + s_len; i++) {
			if (arr[i] == '\0') {
				arr[i] = s[i - pos];
			}
			else {
				char fused = (arr[i] + s[i - pos]) / 2;
				arr[i] = fused;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%c", arr[i]);
		if (arr[i] == '\0') {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
