# include<stdio.h>
#define MAX 4

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

void push(int val){
    if(is_full()==0){
        s.top++;
        s.stk[s.top]=val;
    }
    else
        printf("Stack is full\n");
}

void pop(){
    if(is_empty()==0){
        printf("The popped value is: %d\n",s.stk[s.top]);
        s.stk[s.top]=0;
        s.top--;
    }
    else
        printf("The stack is empty\n");
}

void peek(){
    if(is_empty()==0){
        printf("The topmost value is: %d\n",s.stk[s.top]);
    }
    else
        printf("the stack is empty\n");
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
    init();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    peek();
    display();
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}