# include <stdio.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}


int partition(int l, int h, int a[]){
    int pivot = a[l];
    int i=l, j=h,temp;

    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);

        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
            
    }while(i<j);
        temp=a[l];
        a[l]=a[j];
        a[j]=temp;
    return j;
}

void quick_sort(int a[], int l, int h){
    int i,j;
    if(l<h){
        j=partition(l,h,a);
        quick_sort(a,l,j);
        quick_sort(a,j+1,h);
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
    quick_sort(arr,0,n);
    show(arr,n);
}