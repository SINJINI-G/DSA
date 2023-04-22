#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int len;
char str[MAX];

struct stack{
    int top;
    int stk[MAX];
};

typedef struct stack i;

void push(i *p, int a){
    p->stk[++p->top]=a;
}

void pop(i *p){
    strcat(str, (p->stk[p->top--]));
}

int isEmpty(i *p){
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
    printf("Enter the experession\n");
    scanf("%[^\n]s",&exp);
    len=strlen(exp);
    for(j=0;j<len;j++){
        if(exp[j]=='+'||exp[j]=='-'||exp[j]=='*'||exp[j]=='/'||exp[j]=='%'||exp[j]=='('||exp[j]==')')
            if(exp[j]=='(')
                push(p,exp[j]);
            else if(exp[j]==')'){
                while(p->stk[p->top--]!='('){
                    pop(p);
                }
                p->top--;
            }
            else if(p->stk[p->top]<=exp[j]&&p->stk[p->top]!='(')
                push(p,exp[j]);
            else{
                pop;
                j--;
            }
        else
            strcat(str,exp[j]);
    }
    printf("%s",str);
}