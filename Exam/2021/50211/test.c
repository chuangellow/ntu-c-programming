#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define MAXL 1000001
 
typedef struct rv{ //return value
    int value;
    bool is_valid;
} RV;
 
int read_number(char expression[MAXL], int *index){ //init is the index of first digit
    char c = expression[*index];
    int number = 0;
    int init = *index;
    while('0' <= c && c <= '9'){
        number=number*10+c-'0';
        c = expression[++*(index)];
    }
    return number;
}
 
 
RV calculate(char expression[MAXL], int *index){
    RV rv = {.value = 0, .is_valid = true};
    if(expression[*index] != '('){
        rv.is_valid = false;
        return rv;
    }
    (*index)++;
    int number1, number2;
    char operator;
    if(expression[*index] == '('){
        RV se = calculate(expression, index);
        if(!se.is_valid){
            rv.is_valid = false;
            return rv;
        }
        number1 = se.value;
 
        operator = expression[*index];
        (*index)++;
 
        if(expression[*index] != '('){
            rv.is_valid = false;
            return rv;
        }
        se = calculate(expression, index);
        if(!se.is_valid){
            rv.is_valid = false;
            return rv;
        }
        number2 = se.value;
    }else if('0' <= expression[*index] && expression[*index] <= '9'){
        number1 = read_number(expression, index);
        if(number1 == -1){
            rv.is_valid = false;
            return rv;
        }
 
        operator = expression[*index];
        (*index)++;
 
        if(!('0' <= expression[*index] && expression[*index] <= '9')){
            rv.is_valid = false;
            return rv;
        }
        number2 = read_number(expression, index);
        if(number2 == -1){
            rv.is_valid = false;
            return rv;
        }
    }else{
        rv.is_valid = false;
        return rv;
    }
 
    if(expression[*index] != ')'){
        rv.is_valid = false;
        return rv;
    }
    if(operator == '+'){
        rv.value = number1+number2;
    }else if(operator == '-'){
        rv.value = number1-number2;
    }else if(operator == '*'){
        rv.value = number1*number2;
    }else if(operator == '/'){
        rv.value = number1/number2;
    }else{
        rv.is_valid = false;
        return rv;
    }
    (*index)++;
    return rv;
}
 
int main(){
    char expression[MAXL];
    while(scanf("%s", expression) != EOF){
        int index = 0;
        RV rv = calculate(expression, &index);
		printf("%d", index);
        if(rv.is_valid&&expression[index]=='\0'){
            printf("%d\n", rv.value);
        }else{
            printf("invalid\n");
        }
    }
 
}
