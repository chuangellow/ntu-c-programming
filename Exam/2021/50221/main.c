#include "stdio.h"
#include "stdlib.h"
#include "Pascal.h"
 
int main(){
    int height;
    scanf("%d", &height);
    int node_num = height * (height+1) / 2;
    Node* node_array = (Node*)calloc(node_num, sizeof(Node));
    build_Pascal(node_array, height);
 
    for (int i = 0; i < node_num; i++){
        int value = node_array[i].value;
        int left = (node_array[i].left == NULL)? -1 : (node_array[i].left - node_array);
        int right = (node_array[i].right == NULL)? -1 : (node_array[i].right - node_array);
        printf("%d %d %d\n", value, left, right);
    }
    free(node_array);
    node_array = NULL;
    return 0;
}
