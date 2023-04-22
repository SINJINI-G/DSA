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
        if(i!=n)
            temp = temp->next;
        else
            newNode->next=NULL;
    }
}

void show(){
    struct node *temp = HEAD;
    printf("Displaying the linked list:\n");
    while(temp->next!=HEAD){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
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

    while(temp->next!=HEAD){
        temp=temp->next;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = HEAD;
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

    while(temp->next!=HEAD){
        prev = temp;
        temp=temp->next;
    }

    printf("%d is deleted\n",temp->data);
    prev->next = HEAD;
    free(temp);
}

void reverse(){
    struct node *current = HEAD->next, *prev=HEAD, *next=current->next;

    while(current!=HEAD){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    HEAD->next = prev;
    HEAD = prev;
}

int main(void){
    int n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    show();
    insert_first();
    show();
    // create(n);
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
    // show();
    // reverse();
    // show();
    return 0;
}