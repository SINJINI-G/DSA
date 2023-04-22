# include <stdio.h>
# include <stdlib.h>
 
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}* root=NULL;



struct Node * insert(struct Node *p, int key){
   struct Node *newNode;

   if(p==NULL){
    newNode= (struct Node *)malloc(sizeof(struct Node ));
    newNode->data=key;
    newNode->lchild=newNode->rchild=NULL;
    return newNode;
   }
    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else
        p->rchild=insert(p->rchild,key);
    return p;
}

struct Node * search(struct Node *t, int key){
    while(t!=NULL){
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else    
            t=t->rchild;
    }
    return NULL;
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        printf("%d\n",p->data);
        inorder(p->rchild);
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d",p->data);
    }
}

int count(struct Node *p){
    int x=0,y=0;
    if(p!=NULL){
        x=count(p->lchild);
        y=count(p->rchild);
        // return x+y+1;
        if(p->lchild||p->rchild){
            return x+y;
        }
        else 
            return x+y+1;
    }
    return 0;
}

int height(struct Node *p){
    int x=0, y=0;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int min(struct Node *p){
    while(p->lchild!=NULL){
        p=p->lchild;
    }
    return p->data;
}

int max(struct Node *p){
    while(p->rchild!=NULL){
        p=p->rchild; 
    }
    return p->data;
}

int main(void){
    root = insert(root,10);
    insert(root,5);
    insert(root,20);
    insert(root,80);
    insert(root,30);
    // inorder(root);
    // if(search(root,20)==NULL)
    //     printf("Not found");
    // else    
    //     printf("Found");
    // printf("%d",height(root));
    printf("%d\n",min(root));
    printf("%d\n",max(root));
    // printf("%d",count(root));
    return 0;
}