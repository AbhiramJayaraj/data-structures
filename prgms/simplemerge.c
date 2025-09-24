#include <stdio.h>

void simplemerge(int a[], int f, int s, int t) {
    int temp[50];
    int i = f, j = s, k = 0;

    while(i < s && j <= t) {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

   
    while(i < s)
        temp[k++] = a[i++];

   
    while(j <= t)
        temp[k++] = a[j++];

    for(i = f, k = 0; i <= t; i++, k++)
        a[i] = temp[k];
}


void mergesort(int a[], int t, int b) {
    if(t < b) {
        int mid = (t + b) / 2;
    
        printf("Calling mergesort(t: %d, b: %d, mid: %d)\n", t, b, mid);

        mergesort(a, t, mid);
        mergesort(a, mid + 1, b);

       
        printf("Merging from %d to %d and %d to %d\n", t, mid, mid + 1, b);

      
        simplemerge(a, t, mid + 1, b);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Sorted elements:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
