# include <stdio.h>

void input(int a[], int n){
    int i;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void merge(int a[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int b[100];

    while(i<=mid&& j<=h){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=mid;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(i=l;i<=h;i++)
        a[i]=b[i];
}

void merge_sort(int a[],int n){
    int p, l, h, mid, i;

    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(a,l,mid,h);
        }
    }
    if(p/2<n)
        merge(a,0,p/2-1,n);
}

// void merge_sort(int a[], int l, int r)
// {
//     if (l < r) {
//         int m = l + (r - l) / 2;
 
//         merge_sort(a, l, m);
//         merge_sort(a, m + 1, r);
 
//         merge(a, l, m, r);
//     }
// }


void show(int a[], int n){
    int i;
    printf("Displaying the array\n");
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
    merge_sort(arr,n);
    show(arr,n);
}