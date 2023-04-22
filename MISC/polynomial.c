#include <stdio.h>
# include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

void create()
{
    struct Node *t, *last;
    int num1, num2, i;

    t = poly1;
    printf("Enter number of terms\n");
    scanf("%d", &num1);
    printf("Enter each term with coeff and exp\n");

    for (i = 0; i < num1; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly1 == NULL)
        {
            poly1 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }

    t = poly2;
    printf("Enter number of terms\n");
    scanf("%d", &num2);
    printf("Enter each term with coeff and exp\n");

    for (i = 0; i < num2; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly2 == NULL)
        {
            poly2 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void add()
{
    struct Node *t1, *t2, *t3, *newNode;
    t1 = poly1;
    t2 = poly2;
    t3 = poly3;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp == t2->exp)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->exp = t1->exp;
            newNode->coeff = t1->coeff + t2->coeff;
            newNode->next = NULL;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->exp > t2->exp)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->exp = t1->exp;
            newNode->coeff = t1->coeff;
            newNode->next = NULL;
            t1 = t1->next;
        }
        else
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->exp = t2->exp;
            newNode->coeff = t2->coeff;
            newNode->next = NULL;
            t2 = t2->next;
        }
        if (t3 == NULL)
            poly3 = t3 = newNode;
        else{
            t3->next = newNode;
            t3 = t3->next;
        }
    }
    if (t1 != NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->exp = t1->exp;
        newNode->coeff = t1->coeff;
        newNode->next = NULL;
        t1 = t1->next;
        t3->next = newNode;
        t3 = t3->next;
    }
    if (t2 != NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->exp = t2->exp;
        newNode->coeff = t2->coeff;
        newNode->next = NULL;
        t2 = t2->next;
        t3->next = newNode;
        t3 = t3->next;
    }
}

void display(struct Node *t){
    while(t!=NULL){
        if(t->next!=NULL)
            printf("%dx^%d+",t->coeff,t->exp);
        else
            printf("%dx^%d\n",t->coeff,t->exp);
        t=t->next;
    }
}

int main(void)
{
    create();
    add();
    display(poly1);
    display(poly2);
    display(poly3);

    return 0;
}