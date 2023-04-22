// https://drive.google.com/drive/folders/14nKGyDJgudQ-wzFBaOWoxwo5CHSo9fsd?usp=sharing

# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *HEAD =NULL;

void create(int n){
    int i;
    HEAD = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    scanf("%d",&HEAD->data);
    HEAD->next=NULL;

    struct node *newNode, *temp=HEAD;

    for(i=2;i<=n;i++){
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &newNode->data);
        newNode->next=NULL;
        temp->next = newNode;
        temp = temp->next;
    }
}

void show(){
    struct node *temp = HEAD;
    printf("Displaying the linked list:\n");
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void insert_first(){
    struct node *temp = HEAD, *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = temp;
    HEAD = newNode;
}

void insert_middle(int n){
    struct node *temp = HEAD, *newNode;

    while(n-1>1){
        temp=temp->next;
        n--;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = temp->next;
    temp->next = newNode;  
}

void insert_last(){
    struct node *temp = HEAD, *newNode;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    temp->next = newNode;
}

void delete_first(){
    struct node *temp = HEAD;

    printf("%d is deleted\n",temp->data);
    HEAD = temp->next;
    free(temp);
}

void delete_middle(int n){
    struct node *temp = HEAD, *prev;

    while(n>1){
        prev = temp;
        temp=temp->next;
        n--;
    }

    printf("%d is deleted\n",temp->data);
    prev->next = temp->next;
    free(temp);
}

void delete_last(){
    struct node *temp = HEAD, *prev;

    while(temp->next!=NULL){
        prev = temp;
        temp=temp->next;
    }

    printf("%d is deleted\n",temp->data);
    prev->next = NULL;
    free(temp);
}

void reverse(){
    struct node *current = HEAD, *prev=NULL, *next=NULL;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    HEAD = prev;
}

int main(void){
    int n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    create(n);
    show();
    reverse();
    // insert_first();
    // show();
    // insert_middle(3);
    // show();
    // insert_last();
    // show();
    // delete_first();
    // show();
    // delete_middle(5);
    // show();
    // delete_last();
    show();
    return 0;
}