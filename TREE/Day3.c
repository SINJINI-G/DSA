# include <stdio.h>
# include <stdlib.h>

#define MAX 100

struct node{
    int info;
    int used;
}tree[MAX];

void maketree(int data){
    int p;

    tree[0].info=data;
    tree[0].used=1;

    for(p=1;p<MAX;p++)
        tree[p].used=0;
}

void setleft(int p, int data){
    int q=2*p+1;
    if(q>=MAX){
        printf("Array Overflow!\n");
        return;
    }
    else if(tree[q].used){
        printf("Invalid!");
        return;
    }
    else{
        tree[q].info=data;
        tree[q].used=1;
    }
}

void setright(int p, int data){
    int q=2*p+2;
    if(q>=MAX){
        printf("Array Overflow!\n");
        return;
    }
    else if(tree[q].used){
        printf("Invalid!");
        return;
    }
    else{
        tree[q].info=data;
        tree[q].used=1;
    }
}

int main(void){
    int p, q, number;

    printf("Enter data");
    scanf("%d",&number);
    maketree(number);
    while(scanf("%d",&number)!=EOF){
        p = q = 0;
        while(q<MAX && tree[q].used && number!=tree[p].info){
            p = q;
            if(number<tree[p].info)
                q=1*p+1;
            else
                q=1*p+2;
        }
        if(number==tree[p].info)
            printf("Dup!\n");
        else if(number<tree[p].info)
            setleft(p,number);
        else
            setright(p,number);
    }
    return 0;
}