# include<stdio.h>

int r, c, arr[100][100];

void input(){
    int i=0,j=0;
    printf("Enter the number of rows\n");
    scanf("%d",&r);
    printf("Enter the number of columns\n");
    scanf("%d",&c);
    printf("Enter the array elements\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(){
    int i=0,j=0;
    printf("The array elements are:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int count_zero(){
    int k=0,i=0,j=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j]==0)
                k++;
        }
    }
    return k;
}

void three_tuple_form(int x){
    int tup[x][3], i=0, j=0, k=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(arr[i][j]!=0){
                tup[k][0]=i;
                tup[k][1]=j;
                tup[k][2]=arr[i][j];
                k++;
            }
        }
    }
    printf("The 3 tuple form is:\n");
    for(i=0;i<x;i++){
        for(j=0;j<3;j++){
            printf("%d\t",tup[i][j]);
        }
        printf("\n");
    }
}

void check_sparse(){
    int count=count_zero();
    if(count>=(2/3)*c*r){
        printf("It is a sparse matrix\n");
        three_tuple_form((c*r)-count);
    }
    else
        printf("It is not a sparse matrix\n");
}

int main(void){
    input();
    display();
    check_sparse();
    return 0;
}