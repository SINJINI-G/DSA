#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

int is_empty(){
    if(top==NULL)
        return 1;
    else
        return 0;
}

void show()
{
    struct node *temp = top;
    printf("Displaying the linked list:\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void push(){
    struct node *temp = top, *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&newNode->data);
    newNode->next = temp;
    top = newNode;
}

void pop(){
    struct node *temp = top;

    if(is_empty()==0){
        printf("%d is deleted\n",temp->data);
        top = temp->next;
        free(temp);
    }
    else
        printf("Stack is empty\n");
}

int main(void)
{
    pop();
    push();
    push();
    push();
    show();
    pop();
    show();
    return 0;
}
