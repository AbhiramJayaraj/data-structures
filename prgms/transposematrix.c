#include<stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Sparse;

void main()
{
    int m, n, nz = 0;
    printf("Enter the dimension of the matrix: ");
    scanf("%d%d", &m, &n);

    int a[m][n];

    // Input matrix and count non-zero elements
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                nz++;
        }

    // Sparse matrix representation
    Sparse sm[nz + 1];
    sm[0].row = m;
    sm[0].col = n;
    sm[0].value = nz;

    int k = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0) {
                sm[k].row = i;
                sm[k].col = j;
                sm[k].value = a[i][j];
                k++;
            }

    // Transpose sparse matrix
    Sparse trans[nz + 1];
    trans[0].row = sm[0].col;
    trans[0].col = sm[0].row;
    trans[0].value = sm[0].value;

    int q = 1;
    // For each column in original sparse, find matching elements
    for (int col = 0; col < sm[0].col; col++) {
        for (int i = 1; i <= nz; i++) {
            if (sm[i].col == col) {
                trans[q].row = sm[i].col;   // Swap
                trans[q].col = sm[i].row;
                trans[q].value = sm[i].value;
                q++;
            }
        }
    }

    // Printing original sparse matrix
    printf("\nOriginal Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= nz; i++)
        printf("%d\t%d\t%d\n", sm[i].row, sm[i].col, sm[i].value);

    // Printing transpose sparse matrix
    printf("\nTranspose Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= nz; i++)
        printf("%d\t%d\t%d\n", trans[i].row, trans[i].col, trans[i].value);
}
