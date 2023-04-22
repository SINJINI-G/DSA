# include<stdio.h>
#define MAX 4

struct queue{
    int front;
    int rear;
    int que[MAX];
}q;

void init(){
    q.front=q.rear=-1;
}

int is_empty(){
    if(q.front==-1||q.front==q.rear+1)
        return 1;
    else
        return 0;
}

int is_full(){
    if(q.rear==MAX-1)
        return 1;
    else
        return 0;
}

void enqueue(int val){
    if(is_full()==0){
        if(q.front==-1)
            q.front++;
        q.rear++;
        q.que[q.rear]=val;
    }
    else
        printf("queue is full\n");
}

void dequeue(){
    if(is_empty()==0){
        printf("The dequeued value is: %d\n",q.que[q.front]);
        q.que[q.front]=0;
        q.front++;
    }
    else
        printf("The queue is empty\n");
}

void peek(){
    if(is_empty()==0){
        printf("The topmost value is: %d\n",q.que[q.front]);
    }
    else
        printf("the queue is empty\n");
}

void display(){
    int temp=q.front;
    if(is_empty()==0){
        while(temp<=q.rear){
            printf("%d\n",q.que[temp++]);
        }
    }
    else
        printf("The queue is empty\n");
}

int main(){
    init();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    peek();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}