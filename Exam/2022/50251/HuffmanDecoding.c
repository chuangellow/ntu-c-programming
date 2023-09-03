#include "HuffmanDecoding.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
 
bool check_valid(Node *root, char *data) {
    int data_len = strlen(data);
    Node *now = root;
    for (int i = 0; i < data_len; i++) {
        switch (data[i]) {
            case '0':
                now = now->left;
                if (now->left == NULL && now->right == NULL) {
                    now = root;
                }
                break;
            case '1':
                now = now->right;
                if (now->left == NULL && now->right == NULL) {
                    now = root;
                }
                break;
            default:
                break;
        }
    }
    if (now == root) return true;
    else return false;
}
 
void HuffmanDecoding(Node *root, char *data) {
    int data_len = strlen(data);
    if (!(check_valid(root, data))) {
        printf("-1");
#ifdef SPACE
		printf(" ");
#elif NEWLINE
		printf("\n");
#endif
        return;
    }
    Node *now = root;
    for (int i = 0; i < data_len; i++) {
        switch (data[i]) {
            case '0':
                now = now->left;
                if (now->left == NULL && now->right == NULL) {
                    printf("%s", now->symbol);
#ifdef SPACE
					printf(" ");
#elif NEWLINE
					printf("\n");
#endif
                    now = root;
                }
                break;
            case '1':
                now = now->right;
                if (now->left == NULL && now->right == NULL) {
                    printf("%s", now->symbol);
#ifdef SPACE
					printf(" ");
#elif NEWLINE
					printf("\n");
#endif
                    now = root;
                }
                break;
            default:
                break;
        }
    }
    return;
}
