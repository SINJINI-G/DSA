# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node * right;
    struct node *father;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* setLeft(struct node* root, int data){
    root->left = createNode(data);
    return root->left;
}

struct node* setRight(struct node* root, int data){
    root->right = createNode(data);
    return root->right;
}

int info(struct node* root){
    return root->data;
}

struct node* left(struct node* root){
    return root->left;
}

struct node* right(struct node* root){
    return root->right;
}

void inTrav(struct node *tree){
    if(tree!=NULL){
        inTrav(tree->left);
        printf("%d ",tree->data);
        inTrav(tree->right);
    }
}

void preTrav(struct node *tree){
    if(tree!=NULL){
        printf("%d ",tree->data);
        preTrav(tree->left);
        preTrav(tree->right);
    }
}

void postTrav(struct node *tree){
    if(tree!=NULL){
        postTrav(tree->left);
        postTrav(tree->right);
        printf("%d ",tree->data);
    }
}

int main(void){
    int number, n;

    printf("State the number of terms:\n");
    scanf("%d",&n);

    struct node *p, *q, *tree;

    printf("Enter:");
    scanf("%d",&number);
    
    tree = createNode(number);

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
            setLeft(p, number);
        else
            setRight(p, number);
    }

    printf("Inorder:\n");
    inTrav(tree);

    printf("\nPreorder:\n");
    preTrav(tree);

    printf("\nPostorder:\n");
    postTrav(tree);
    
    return 0;
}