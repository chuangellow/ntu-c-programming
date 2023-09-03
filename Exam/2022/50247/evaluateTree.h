#ifndef __EVALUATE_TREE_H__
#define __EVALUATE_TREE_H__
typedef struct Node {
    char *val;
    struct Node *left, *right;
} Node;
 
void evaluateTree(Node *root, int *values);
#endif
