typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;
 
void build_Pascal(Node* node_array, int height);
