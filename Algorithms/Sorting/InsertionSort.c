# include<stdio.h>
# include<stdlib.h>

void insertionsort(int arr[], int n){
    int i,j,key;
    
    for(i=0;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void printarray(int arr[], int n){
    int i=0;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main(){
    int arr[]={12,11,13,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    printarray(arr,n);
    insertionsort(arr,n);
    printarray(arr,n);
    
    return 0;
}