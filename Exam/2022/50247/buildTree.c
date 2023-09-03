#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "buildTree.h"

#define TOK_MAX_NUM 500000
#define TOK_MAX_LEN 1000000

Node* newNode(char* val, Node* left, Node* right) {
	Node* new = (Node*) malloc(sizeof(Node));
	new->val = val;
	new->left = left;
	new->right = right;
	return new;
}

Node* get_boolean_tree_root(char** tokens, int count, int *pos) {
	if (strcmp(tokens[*pos], "(") == 0) {
		*pos = *pos + 1;
		Node* left_node = get_boolean_tree_root(tokens, count, pos);
		*pos = *pos + 1;
		char* current_tok = tokens[*pos];
		*pos = *pos + 1;
		Node* right_node = get_boolean_tree_root(tokens, count, pos);
		*pos = *pos + 1;
		return newNode(current_tok, left_node, right_node);
	}
	else if (strcmp(tokens[*pos], "!") == 0) {
		char* current_tok = tokens[*pos];
		*pos = *pos + 1;
		Node* left_node = get_boolean_tree_root(tokens, count, pos);
		return newNode(current_tok, left_node, NULL);
	}
	else {
		char* current_tok = tokens[*pos];
		return newNode(current_tok, NULL, NULL);
	}
}

Node* buildTree(char* expr) {
	char** tokens = (char**) malloc(sizeof(char*)*TOK_MAX_NUM);
	int count = 0;
	const char delimiter[2] = " \n";
	char* token = strtok(expr, delimiter);
	while (token != NULL) {
		tokens[count] = token;
		token = strtok(NULL, delimiter);
		count++;
	}
	int pos = 0;
	Node* root = get_boolean_tree_root(tokens, count, &pos);
	return root;
}
