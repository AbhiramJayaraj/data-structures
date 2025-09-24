#include <stdio.h>

void selection_sort(int a[], int n)
{
    int p, small, ind;
    for(p = 0; p < n - 1; p++)
    {
        small = a[p];
        ind = p;
        for(int c = p + 1; c < n; c++)
        {
            if(a[c] < small)
            {
                small = a[c];
                ind = c;
            }
        }
        if(ind != p)
        {
            int temp = a[p];
            a[p] = a[ind];
            a[ind] = temp;
        }
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

    selection_sort(a, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
