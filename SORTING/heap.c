#include <stdio.h>

void delete(int a[], int n)
{
    int i = 1, j = i * 2, x, temp, val;

    val = a[1];
    x = a[n];
    a[1] = a[n];
    a[n] = val;

    while (j < n - 1)
    {
        if (a[j + 1] > a[j])
            j += 1;
        if (a[i] < a[j])
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j *= 2;
        }
        else
            break;
    }
}

void heap_sort(int a[], int n)
{
    int i = n, temp;
    temp = a[i];

    while (i > 1 && temp > a[i / 2])
    {
        a[i] = a[i / 2];
        i /= 2;
    }
    a[i] = temp;
}

void input(int a[], int n)
{
    int i;
    printf("Enter the array elements\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (i >= 2)
            heap_sort(a, i);
    }

    for (i = n; i > 0; i--)
    {
        delete (a, n);
    }
}

void show(int a[], int n)
{
    int i;
    printf("Displaying the sorted array\n");
    for (i = n; i <= 1; i++)
    {
        printf("%d\n", a[i]);
    }
}

int main(void)
{
    int arr[100], n;
    printf("Enter the length of the array\n");
    scanf("%d", &n);
    input(arr, n);
    show(arr, n);
}