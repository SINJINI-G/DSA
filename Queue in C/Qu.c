# include<stdio.h>
# include<stdlib.h>

# define MAX 4

struct Queue{
    int front, rear;
    int q[MAX];
}quu;

void ini(){
    quu.front=quu.rear=-1;
}

int isFull(){
    return quu.rear==MAX-1;
}

int isEmpty(){
    return quu.front==-1 && quu.rear==-1;
}

void insert(int value){
    if(isFull())
        printf("Queue is full!! Can't insert..\n");
    else{
        if(quu.front==-1)
            quu.front=0;
        quu.rear++;
        quu.q[quu.rear]=value;
    }
}

void delete(){
    if(isEmpty())
        printf("Nothing to delete\n");
    else{
        int i;
        for(i=quu.front;i<quu.rear;i++)
            quu.q[i]=quu.q[i+1];
            quu.rear--;
    }
}

void disp(){
    int i;
    printf("Displaying queue:\n");
    for(i=quu.front;i<=quu.rear;i++)
        printf("%d\n",quu.q[i]);
}

int main(void){
    int i=1,n,val;
    ini(); 
    while(i==1){
        printf("YOUR CHOICES ARE:\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\n");
        scanf("%d",&n);
        switch(n){
            case 1: printf("Enter the value you want to enter\n");
            scanf("%d",&val);
            insert(val);
            break;

            case 2: delete();
            break;

            case 3: disp();
            break;

            default: printf("Onno jaygay giye fajlami koro!!\n");
            exit(1);
        }
        printf("Wanna continue?? Enter 1. Else enter 0.\n");
        scanf("%d",&i);
    }
    return 0;
}