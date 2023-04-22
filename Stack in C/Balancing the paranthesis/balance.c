#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX 100

int len;

struct stack{
    int top;
    char stk[MAX];
};

typedef struct stack i;

void push(i *p){
    p->stk[++p->top]='(';
}

void pop(i *p){
    p->top--;
}

int isEmpty(i *p)
{
    if(p->top==-1)
        return 1;
    else
        return 0;
}

int main(void){
    int j;
    char exp[100];
    i *p=(i *)malloc(sizeof(i));
    p->top=-1;
    printf("Enter the expression:\n");
    scanf("%[^\n]s", &exp);
    len=strlen(exp);
    for(j=0;j<len;j++){
        if(exp[j]=='(')
            push(p);
        else if(exp[j]==')')
            pop(p);
        else    
            continue;
    }
    if(isEmpty(p))
        printf("The Expression is balanced\n");
    else
        printf("The Expression is not balanced\n");
    return 0;
}