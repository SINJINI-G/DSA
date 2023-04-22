# include <stdio.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void insertion_sort(int a[], int n){
    int i, j, x;
    for(i=1;i<n;i++){
        j=i-1;
        x=a[i];
        while(j>=0&&a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
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
    insertion_sort(arr,n);
    show(arr,n);
}