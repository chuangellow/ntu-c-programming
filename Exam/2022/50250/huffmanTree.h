#define SYM_MAX_LEN 8
#define SYM_MAX_NUM 100000
 
typedef struct Node {
    char symbol[SYM_MAX_LEN];
    int frequency;
    struct Node *left, *right;
} Node;
 
Node* buildHuffmanTree(char* s[SYM_MAX_NUM], int n);
