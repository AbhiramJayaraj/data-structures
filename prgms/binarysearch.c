#include<stdio.h>


void binary_search(int a[], int n, int ele)
{
    int t = 0, b = n - 1, m;
    while(t <= b)
    {
        m = (t + b) / 2;
        if(a[m] == ele)
        {
            printf("Element found at index %d\n", m);
            return;
        }
        else if(a[m] < ele)
        {
            t = m + 1;
        }
        else
        {
            b = m - 1;
        }
    }
    
    printf("Element not found in the array.\n");
}

int main()
{
    int a[100], n, ele;

   
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in sorted order:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    
    printf("Enter the element to search: ");
    scanf("%d", &ele);

    binary_search(a, n, ele);

    return 0;
}
