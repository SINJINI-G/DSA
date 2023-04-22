# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    int rthread;
    struct node *left, *right;
};

typedef struct node* nodeptr;

nodeptr left(nodeptr root){
    return root->left;
}

nodeptr right(nodeptr root){
    return root->right;
}

int info(nodeptr root){
    return root->data;
}

nodeptr getNode(){
    return (nodeptr)malloc (sizeof(struct node));
}

nodeptr maketree(int x){
    nodeptr p= getNode();

    p->data=x;
    p->left = p->right = NULL;
    p->rthread = 1;

    return p;
}

void setleft(nodeptr p, int x){

    if(p==NULL){
        printf("Void Insertion!\n");
        return;
    }
    else if(p->left != NULL){
        printf("Void Insertion!");
        return;
    }
    else{
        nodeptr q = getNode();
        q->data= x;
        p->left = q;
        q->left = NULL;
        q->right = p;
        q->rthread = 1;
    }
}

void setright(nodeptr p, int x){

    if(p==NULL){
        printf("Void Insertion!\n");
        return;
    }
    else if(!p->right){
        printf("Void Insertion!");
        return;
    }
    else{
        nodeptr q = getNode(), r;
        q->data= x;
        p->left = NULL;
        r = p->right;
        p->right = q;
        p->rthread = 1;
        q->right = r;
        q->rthread = 1;
    }
}

void intrav(nodeptr tree){
    nodeptr p, q;

    p =  tree;

    do{
        q= NULL;

        while(p!= NULL){
            q=p;
            p=p->left;
        }

        if(q!= NULL){
            printf("%d, ",q->data);
            p = q->right;
            while(q->rthread && p!= NULL){
                printf("%d, ",p->data);
                q=p;
                p=p->right;
            }
        }

       
    }while(q!=NULL);
}

int main(void){
    int number, n;

    printf("State the number of terms:\n");
    scanf("%d",&n);

    struct node *p, *q, *tree;

    printf("Enter:");
    scanf("%d",&number);
    
    tree = maketree(number);

    while(--n){
        printf("Enter:");
        scanf("%d",&number);
        p = q = tree;
        while(number!=info(p) && q!=NULL){
            p = q;
            if(number<info(p))
                q=left(p);
            else
                q=right(p);
        }
        if(number==info(p))
            printf("%d %s\n", number, "is a duplicate");
        else if(number<info(p))
            setleft(p, number);
        else
            setright(p, number);
    }

    intrav(tree);
    return 0;
}