#include<stdio.h>

int linear(int a[], int n, int ele)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == ele)
        {
            printf("Element found at position %d\n", i+1);
            return i;
        }
    }
    return -1; 
}

int main()
{
    int a[100], n, ele;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &ele);

    int result = linear(a, n, ele);
    if(result != -1)
    {
        printf("Element %d found at index %d\n", ele, result);
    }
    else
    {
        printf("Element %d not found in the array\n", ele);
    }

    return 0;
}
