# include <stdio.h> 

struct node{
    int data; 
    struct node *left; 
    struct node *right;
};

struct node* createNode(int data){
    struct node *newNode=(struct node*) malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(node* root, int data){
    if(root==NULL){
        root=createNode(data);
        return root; 
    }
    // if(data<){

    // }
}

int main(void){
    struct node *root = createNode(1); 
}