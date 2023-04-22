# include<stdio.h>
# include<stdlib.h>

void merge(int a[], int l, int m, int r){
    int i=0, j=0, k=0;

    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i=0;i<n1;i++)
        L[i] = a[l+i];
    for(j=0;j<n2;j++)
        R[j] = a[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        // else if(L[i]==R[j]){
        //     a[k]=L[i];
        //     a[++k]=L[j];
        //     i++;
        //     j++;
        // }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
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
    mergesort(arr,0,6);
    print(arr);
    return 0;
}