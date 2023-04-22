# include<stdio.h>
# define MAX 100

int stk[MAX], top,n;

int isEmpty(){
    if(top==-1)
        return 0;
    else    
        return 1;
}

void isFull(){
    if(top==n-1)
        printf("Stack is full\n");
}

void push(int val){
    if(top<n)
        stk[++top]=val;
    else
        printf("Stack is full");
}

void show(){
    int t=top;
    while(t>0){
        printf("%d\n",stk[t--]);
    }
}

void pop(){
    if(isEmpty()==0)
        printf("Stack is empty\n");
    else
        printf("%d\n",stk[top--]);
}

int main(void){
    printf("Enter the size:\n");
    scanf("%d",&n);
    push(20);
    push(30);
    show();
}