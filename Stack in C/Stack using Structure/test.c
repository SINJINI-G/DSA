# include<stdio.h>
# include<stdlib.h>

#define MAX 45

struct stack{
    int top;
    int stk[MAX];
};

typedef struct stack i;

void ini(i *p){
    p->top=-1;
}

int isEmpty(i *p){
    if(p->top==-1)
        return 1;
    return 0;
}

void push(i *p, int val){
    if(p->top==MAX-1)
        printf("Stack is full");
    else
        p->stk[++p->top]=val;
}

void pop(i *p){
    if(isEmpty(p)==1){
        printf("Stack is Empty");
        printf("\n");
    }

    else{
        printf("%d",(p->stk[p->top]));
        p->top--;
    }
}

void disp(i *p){
    int ind=p->top;
    while(ind>=0){
        printf("%d ",p->stk[ind]);
        ind--;
    }
}


int main(void){
    i *ptr= (i *)malloc(sizeof(i));
    ini(ptr);
    push(ptr,20);
    push(ptr,30);
    push(ptr,40);
    push(ptr,50);
    push(ptr,60);
    disp(ptr);
    printf("\n");
    pop(ptr);
    printf("\n");
    disp(ptr);
    printf("\n");
}
    