typedef struct listnode {
    int data;
    struct listnode *next;
    struct listnode *prev;
} ListNode;
 
typedef struct linkedlist{
    struct listnode *head;
    struct listnode *tail;
} LinkedList;
 
void insert(LinkedList *list, int data);
void delete_head(LinkedList *list);
void delete_tail(LinkedList *list);
