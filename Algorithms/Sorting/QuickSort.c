# include<stdio.h>
# include<stdlib.h>

int partition(int a[], int l, int h){
    int i=0, j=0;
    int pivot=a[h];
    i=l-1;

    for(j=l;j<h;j++){
        if(a[j]<pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[h];
    a[h]= temp;
    return (i+1);
}

void quicksort(int a[],int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,h);
    }
}

void print(int a[]){
    int i=0;
    for(i=0;i<7;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(void)
{
    int arr[]={5,2,3,2,1,0,-2};
    print(arr);
    quicksort(arr,0,6);
    print(arr);
    return 0;
}