# include<stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

struct stack{
    int top;
    char stk[MAX];
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

int pre(char x){
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

int is_operand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
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

char *conv(char *infix){
    int i=0, j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=(char *)malloc((len+2)*sizeof(char));

    while(infix[i]!='\0'){
        if(is_operand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(s.stk[s.top]))
                push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(s.top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}

int main(){
    char *infix= "a+b*c";
    push('#');
    char *postfix=conv(infix);
    printf ("%s ",postfix);
    
    return 0;
}