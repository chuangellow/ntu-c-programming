#include "readchar.h"

int readint(int *num){
    char c, negative;
    while((c = readchar()) < '-'){
        if(c == EOF){
            return 0;
        }
    }
    negative = c=='-'?-1:1;
    *num = negative==1?c-'0':0;
    while((c = readchar()) >= '0'){
        *num = (*num << 3) + (*num << 1) + c - '0';
    }
    *num *= negative;
    return 1;
}
