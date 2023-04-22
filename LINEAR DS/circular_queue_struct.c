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
    if(q.front==-1)
        return 1;
    else
        return 0;
}

int is_full(){
    if((q.front==0&&q.rear==MAX-1)||(q.front==q.rear+1))
        return 1;
    else
        return 0;
}

void enqueue(int val){
    if(is_full()==0){
        if(q.front==-1)
            q.front++;
        q.rear=(q.rear+1)%MAX;
        q.que[q.rear]=val;
    }
    else
        printf("queue is full\n");
}

void dequeue(){
    if(is_empty()==0){
        printf("The dequeued value is: %d\n",q.que[q.front]);
        q.que[q.front]=0;
        if(q.front==q.rear)
            q.front=q.rear=-1;
        else
            q.front=(q.front+1)%MAX;
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
        if(q.front<=q.rear){
            while(temp<=q.rear){
                printf("%d\n",q.que[temp++]);
            }
        }
        else{
            while(temp<MAX){
                printf("%d\n",q.que[temp++]);
            }
            temp=0;
            while(temp<=q.rear){
                printf("%d\n",q.que[temp++]);
            }
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
    enqueue(5);
    peek();
    dequeue();
    enqueue(6);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}