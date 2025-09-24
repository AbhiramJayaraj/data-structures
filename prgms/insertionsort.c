#include<stdio.h>

void insertion_sort(int a[], int n)
{
    int p, key, i;
    for(p = 1; p < n; p++)
    {
        key = a[p];
        i = p - 1;
        while(i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
}

int main()
{
    int a[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    insertion_sort(a, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
