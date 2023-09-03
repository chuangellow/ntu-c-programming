#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "buildTree.h"
 
void printTree(Node* node){
	printf("%s\n", node->val);
	if (node == NULL) return;
    if(node->left == NULL && node->right == NULL){
        return;
    }
    printTree(node->left);
    printTree(node->right);
}

int main(void) {
	/*
	int* values = (int*) malloc(sizeof(int) * 26);
	for (int i = 0; i < 26; i++) {
		scanf("%d", &values[i]);
	}
	*/
	char expr[500000] = "( ( A || B ) && ! C )";
	/*
	fgets(expr, 500000, stdin);
	*/
	Node *root = buildTree(expr);
	printTree(root);
	return 0;
}
