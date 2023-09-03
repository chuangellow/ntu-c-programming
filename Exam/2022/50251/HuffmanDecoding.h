typedef struct Node {
    char symbol[5];
    int frequency;
    struct Node *left, *right;
}Node;
 
void HuffmanDecoding(Node *root, char *data);
