# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front =NULL;
struct node *rear =NULL;

int is_empty(){
    if(front==NULL&&rear==NULL)
        return 1;
    else
        return 0;
}

void show(){
    struct node *temp = front;
    
    if(is_empty()==0){
        printf("Displaying the queue:\n");
        while(temp!=NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
    else
        printf("queue is empty\n");
}


void enqueue(){
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(is_empty()==1)
        front = rear = newNode;
    else{
        rear->next = newNode;
        rear= newNode;
    }
}

void dequeue(){
    struct node *temp = front;

    if(is_empty()==0){
        printf("%d is dequeued\n",temp->data);
        front = temp->next;
        free(temp);
    }
    else
        printf("queue is empty");
}

int main(void){

    show();
    enqueue();
    enqueue();
    enqueue();
    show();
    dequeue();
    show();
    return 0;
}