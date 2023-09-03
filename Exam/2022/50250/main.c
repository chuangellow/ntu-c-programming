#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "huffmanTree.h"
 
void printTree(Node* node){
    if(node->left == NULL && node->right == NULL){
        printf("%d %s\n", node->frequency, node->symbol);
        return;
    }
    printf("%d\n", node->frequency);
    printTree(node->left);
    printTree(node->right);
}
 
int main(){
    int n;
    char* s[SYM_MAX_NUM];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        s[i] = (char*)malloc(sizeof(char) * SYM_MAX_LEN);
        scanf("%s", s[i]);
    }
    Node *root = buildHuffmanTree(s, n);
    printTree(root);
 
    for(int i = 0; i < n; i++){
        free(s[i]);
    }
}
