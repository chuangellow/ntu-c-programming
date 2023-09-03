#include <stdio.h>
#include <stdlib.h>
#include "function.h"    
 
#define INSERT 0
#define DELETE_HEAD 1
#define DELETE_TAIL 2
 
void head_traverse(LinkedList *list){
    ListNode *node = list -> head;
    for(; node != NULL; node = node -> next)
        printf("%d%c", node -> data, (node -> next == NULL) ? '\n' : ' ');
}
 
void tail_traverse(LinkedList *list){
    ListNode *node = list -> tail;
    for(; node != NULL; node = node -> prev)
        printf("%d%c", node -> data, (node -> prev == NULL) ? '\n' : ' ');
}
 
int main(){
 
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = NULL;
    list -> tail = NULL;
    int func, val;
 
    while(scanf("%d%d", &func, &val) != EOF){
        switch (func){
            case INSERT:
                insert(list, val);
                break;
            case DELETE_HEAD:
                delete_head(list);
                break;
            case DELETE_TAIL:
                delete_tail(list);
                break;
        }
    }
 
    head_traverse(list);
    tail_traverse(list);
 
    return 0;
}
