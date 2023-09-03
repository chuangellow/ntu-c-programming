#include <stdio.h>

int count_one_bits(unsigned int input) {
	if (input == 0) return 0;
	return ((input & 0x1) == 0x1)? count_one_bits(input >> 1) + 1: count_one_bits(input >> 1);
}

unsigned int extract_n_bits(unsigned int num, int start_bit, int num_bits) {
    unsigned int mask = ((1U << num_bits) - 1U) << start_bit;
    return (num & mask) >> start_bit;
}

unsigned int bits_swap(unsigned int num, int start_bit, int num_bits) {
	if (num_bits == 1) return extract_n_bits(num, start_bit, 1);
	int mid = num_bits / 2;
	unsigned int A = extract_n_bits(num, start_bit + mid, mid);
	unsigned int B = extract_n_bits(num, start_bit, mid);

	if (count_one_bits(num) % 2 == 0) {
		return (bits_swap(A, 0, mid) << mid) | (bits_swap(B, 0, mid));
	}
	else {
		return (bits_swap(B, 0, mid) << mid) | (bits_swap(A, 0, mid));
	}
}

int main(void) {
	unsigned int input;
	scanf("%u", &input);
	int n = 32;
	printf("%u", bits_swap(input, 0, n));
	return 0;
}
