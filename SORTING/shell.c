    # include <stdio.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void shell_sort(int a[], int n){
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=a[i];
            j=i-gap;
            while(j>=0 && a[j]>temp){
                a[j+gap]=a[j];
                j=j-gap;
            }
            a[j+gap]=temp;
        }
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
    shell_sort(arr,n);
    show(arr,n);
}