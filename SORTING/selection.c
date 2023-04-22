# include <stdio.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void selection_sort(int a[], int n){
    int i, j, k, temp;
    for(i=0;i<n-1;i++){
        k=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        temp = a[i];
        a[i]=a[k];
        a[k]=temp;
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
    selection_sort(arr,n);
    show(arr,n);
}