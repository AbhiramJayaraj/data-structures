#include <stdio.h>
void swap(int *a, int *b);
int partition(int a[],int left,int right)
{
    int key=a[left];
    int i=left+1;
    int j=right;
    do{
    while(i<right && a[i]<key)
    {
        i++;
    }
    while(j>left && a[j]>key)
    {
        j--;

    }
    if(i<j)
    {
        swap(&a[i], &a[j]);
    }
    }while(i<j);
    swap(&a[left], &a[j]);
    return j;
}
void quicksort(int a[],int left,int right)
{
    if(left<right)
    {
        int pos=partition(a,left,right);
        quicksort(a,left,pos-1);
        quicksort(a,pos+1,right);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Sorted elements:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

