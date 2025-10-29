#include<stdio.h>
void swap(int*a, int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int left(i)
{
    return(2*i);
}
int right(i)
{
    return(2*i+1);
}
void heapify(int a[],int n,int i)
{
    int large=i;
    int lc=left(i);
    int rc=right(i);
    if(lc<=n && a[lc]>a[large])
        large=lc;
    if(rc<=n && a[rc]>a[large])
        large=rc;
    if(i!=large)
    {
        swap(&a[i],&a[large]);
        heapify(a,n,large);
    }
}
void buildheap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
        heapify(a,n,i);
}
void heapsort(int a[],int n)
{
    buildheap(a,n);
    for(int i=n;i>=2;i--)
    {
        swap(&a[1],&a[i]);
        n=n-1;
        heapify(a,n,1);
    }
}
int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter %d elements:\n",n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heapsort(a,n);
    printf("Sorted elements are:\n");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}