#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 80

void scan_cube(int cube[MAX_N][MAX_N][MAX_N], int n) {
	for (int layer = 0; layer < n; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				scanf("%d", &(cube[layer][i][j]));
			}
		}
	}
	return;
}

void print_cube(int cube[MAX_N][MAX_N][MAX_N], int n) {
	for (int layer = 0; layer < n; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				printf("%d ", cube[layer][i][j]);
			}
			printf("\n");
		}
	}
	return;
}

bool out_of_tower(int layer, int i, int j, int n) {
	return (layer >= n || layer < 0 || i >= n || i < 0 || j >= n || j < 0);
}

int get_connected_componenet_size(int layer, int i, int j, int cube[MAX_N][MAX_N][MAX_N], const int n, const int current_value) {
	if (out_of_tower(layer, i, j, n)) return 0;
	int ret = 0;
	if (cube[layer][i][j] == current_value) {
		cube[layer][i][j] = -1;
		ret = 1;
		ret += get_connected_componenet_size(layer+1, i, j, cube, n, current_value);
		ret += get_connected_componenet_size(layer-1, i, j, cube, n, current_value);
		ret += get_connected_componenet_size(layer, i+1, j, cube, n, current_value);
		ret += get_connected_componenet_size(layer, i-1, j, cube, n, current_value);
		ret += get_connected_componenet_size(layer, i, j+1, cube, n, current_value);
		ret += get_connected_componenet_size(layer, i, j-1, cube, n, current_value);
	}
	return ret;
}

void find_connected_component(int cube[MAX_N][MAX_N][MAX_N], int n) {
	int max_size = -1, max_value = -1;
	int current_size = 0, current_value = 0;
	for (int layer = 0; layer < n; layer++) {
		for (int i = 0; i <= layer; i++) {
			for (int j = 0; j <= layer; j++) {
				if (cube[layer][i][j] != -1) {
					current_value = cube[layer][i][j];
					current_size = get_connected_componenet_size(layer, i, j, cube, n, current_value);
				}
				if (current_size > max_size || ((current_size == max_size) && (current_value > max_value))) {
					max_size = current_size;
					max_value = current_value;
				}
			}
		}
	}
	printf("%d %d", max_value, max_size);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	int cube[MAX_N][MAX_N][MAX_N] = {{{-1}}};
	scan_cube(cube, n);
	//print_cube(cube, n);
	find_connected_component(cube, n);
	return 0;
}
