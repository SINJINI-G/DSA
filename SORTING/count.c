# include <stdio.h>
# include <stdlib.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

int findMax(int a[],int n){
    int i,max=a[i];
    for(i=0;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    return max;
}

void count_sort(int a[], int n){
    int i,j,max,*c;

    max=findMax(a,n);
    c=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        c[a[i]]++;
    }
    i=0;j=0;
    while(j<max+1){
        if(c[j]>0){
            a[i++]=j;
            c[j]--;
        }
        else
            j++;
    }
}

void show(int a[], int n){
    int i;
    printf("Displaying the sorted array\n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}

int main(void){
    int arr[100], n;
    printf("Enter the length of the array\n");
    scanf("%d",&n);
    input(arr,n);
    show(arr,n);
    count_sort(arr,n);
    show(arr,n);
}