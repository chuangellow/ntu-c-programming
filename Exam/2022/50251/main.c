#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanDecoding.h"
#define MaxL 100
Node* newNode(char *symbol, int frequency, Node* l, Node* r){
    Node* new = (Node*)malloc(sizeof(Node));
    if(*symbol != '\0')
        strcpy(new->symbol,symbol);
    new->frequency = frequency;
    new->left = l, new->right = r;
    return new;
}
 
int main (){
    // sample Huffman tree  
    Node *root = newNode("\0",31,
                            newNode("\0",18,
                                    newNode("dad",10,NULL,NULL),
                                    newNode("\0",8,
                                            newNode("cat",5,NULL,NULL),
                                            newNode("\0",3,
                                                    newNode("bee",2,NULL,NULL),
                                                    newNode("ant",1,NULL,NULL)
                                                    )
                                            ) 
                                    ),
                            newNode("\0",13,
                                    newNode("fat",7,NULL,NULL),
                                    newNode("end",6,NULL,NULL)
                                    )
                        );
    // sample encoded data
    char data[MaxL];
    while(scanf("%s", data)!=EOF){
        HuffmanDecoding(root, data);
        printf("\n");
    }
    return 0;
}
