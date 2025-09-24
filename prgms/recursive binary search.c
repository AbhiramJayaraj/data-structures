#include<stdio.h>


int binary_search(int a[], int t, int b, int ele)
{
    if(t <= b)
    {
        int mid = (t + b) / 2;

        if(a[mid] == ele)
            return mid;  
        else if(a[mid] < ele)
            return binary_search(a, mid + 1, b, ele); 
        else
            return binary_search(a, t, mid - 1, ele);  
    }

    return -1; 
}

int main()
{
    int a[100], n, ele, result;

   
    printf("Enter the number of elements: ");
    scanf("%d", &n);

   
    printf("Enter the elements in sorted order:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    
    printf("Enter the element to search: ");
    scanf("%d", &ele);

    result = binary_search(a, 0, n - 1, ele);

    
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
