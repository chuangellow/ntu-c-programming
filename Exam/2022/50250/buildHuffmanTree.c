#include "huffmanTree.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
Node* new_node(int frequency, char* symbol, Node* left, Node* right) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->left = left;
    new->right = right;
    new->frequency = frequency;
    strncpy(new->symbol, symbol, strlen(symbol));
    return new;
}
 
int cmpfunc(const void *a, const void *b) {
    const Node *nodeA = *(const Node **)a;
    const Node *nodeB = *(const Node **)b;
    if (nodeA->frequency != nodeB->frequency) {
        return nodeB->frequency - nodeA->frequency;
    }
    return strcmp(nodeB->symbol, nodeA->symbol);
}

int str_cmpfunc(const void *a, const void *b) {
	const char *str_A = *(const char **)a;
	const char *str_B = *(const char **)b;
	return strcmp(str_A, str_B);
}
 
Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n) {
	qsort(s, n, sizeof(char *), str_cmpfunc);
	Node** S = malloc(sizeof(Node *) * n);
    int count = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && (strcmp(s[i], s[i-1]) == 0)) {
			S[count-1]->frequency += 1;
		}
		else {
			S[count] = new_node(1, s[i], NULL, NULL);
			count++;
		}
	}
    qsort(S, count, sizeof(Node*), cmpfunc);
    while (count > 1) {
        Node* min_node = S[count-1];
        Node* second_min_node = S[count-2];
        Node* new = new_node(min_node->frequency+second_min_node->frequency, (strcmp(min_node->symbol, second_min_node->symbol) < 0)? min_node->symbol: second_min_node->symbol, second_min_node, min_node);
 
        S[count-2] = new;
        count--;
        qsort(&(S[0]), count, sizeof(Node*), cmpfunc);
    }
    return S[0];
}
