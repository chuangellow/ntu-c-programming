#include <stdio.h>
#include <stdint.h>

void print_alphabet(uint64_t num);

int main(void) {
	int n;
	scanf("%d", &(n));
	uint64_t temp;
	for (int i = 0; i < n; i++) {
		scanf("%llu", &(temp));
		print_alphabet(temp);
	}
	printf("\n");
	return 0;
}

void print_alphabet(uint64_t num) {
	int i = 12;
	for (int i = 12; i > 0; i--) {
		int last_five_num = (num & 0x1f);
		char encoding = 'a' + last_five_num;
		printf("%c", encoding);
		num = num >> 5;
	}
	return;
}
