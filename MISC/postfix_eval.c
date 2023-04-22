# include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX

struct stack{
    int top;
    int stk[MAX];
}s;

void init(){
    s.top=-1;
}

int is_empty(){
    if(s.top==-1)
        return 1;
    else
        return 0;
}

int is_full(){
    if(s.top==MAX-1)
        return 1;
    else
        return 0;
}

void push(char op){
        s.top++;
        s.stk[s.top]=op;
}

int pop(){
    if(is_empty()==0){
        return s.stk[s.top--];
    }
    else
        return '$';
}

int eval(char exp[]){
    int i;
    for(i=0;exp[i];++i){
        if(isdigit(exp[i]))
            push(exp[i]-'0');
        else{
            int val1 = pop();
            int val2 = pop();
            switch(exp[i]){
                case '+':push(val1+val2);
                break;
                case '-':push(val2-val1);
                break;
                case '*':push(val2*val1);
                break;
                case '/':push(val2/val1);
                break;
            }
        }
    }
    return pop();
}

void display(){
    int temp=s.top;
    if(is_empty()==0){
        while(temp>=0){
            printf("%d\n",s.stk[temp--]);
        }
    }
    else
        printf("The stack is empty\n");
}

int main(){
    char exp[100];
    printf("Enter the expression\n");
    gets(exp);
    init();
    printf ("postfix evaluation: %d",eval(exp));
    
    return 0;
}