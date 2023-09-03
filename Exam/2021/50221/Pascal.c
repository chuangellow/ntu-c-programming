#include "Pascal.h"
#include <stddef.h>

void build_Pascal(Node* node_array, int height) {
	int num = height * (height + 1) / 2;
	for (int i = 0; i < num; i++) {
		node_array[i].value = (i==0)? 1: 0;
	}
	int layer = 0;
	int max_num = height;
	int layer_num = 0;
	for (int i = 0; i < num; i++) {
		layer_num++;
		if (layer_num == max_num) {
			layer_num = 0;
			layer++;
			max_num--;
			node_array[i].left = NULL;
			node_array[i].right = NULL;
		}
		else {
			node_array[i].right = &(node_array[i+1]);
			node_array[i].left = &(node_array[i+max_num]);
			node_array[i].right->value += node_array[i].value;
			node_array[i].left->value += node_array[i].value;
		}
	}
	return;
}
