#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "evaluateTree.h"

int get_idx(char alphabet) {
	return alphabet - 'A';
}

bool evaluate(Node *root, int *values) {
	if (root->left == NULL && root->right == NULL) return values[get_idx(root->val[0])];
	bool left_result = evaluate(root->left, values);
	if (strcmp(root->val, "!") == 0) {
		return !(left_result);
	}
	bool right_result = evaluate(root->right, values);
	if (strcmp(root->val, "&&") == 0) {
		return left_result && right_result;
	}
	if (strcmp(root->val, "||") == 0) {
		return left_result || right_result;
	}
	return false;
}

void evaluateTree(Node *root, int *values) {
	bool result = evaluate(root, values);
#ifdef LOWER
	printf((result)? "true\n": "false\n");
#endif

#ifdef UPPER
	printf((result)? "TRUE\n": "FALSE\n");
#endif
	return;
}
