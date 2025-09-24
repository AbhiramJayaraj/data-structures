
#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} sparse;

void read(sparse sm[], int *nz)
{
    int m, n;
    printf("Enter the dimensions of the sparse matrix: \n");
    scanf("%d%d", &m, &n);
    sm[0].row = m;
    sm[0].col = n;
    sm[0].value = *nz;
    for (int i = 1; i <= *nz; i++)
    {
        printf("Enter row, column and value for element %d: ", i);
        scanf("%d%d%d", &sm[i].row, &sm[i].col, &sm[i].value);
    }
}

void main()
{
    int nz1, nz2, i=1, j=1, k=1;
    printf("Enter the non-zero elements of the sparse matrix 1: \n");
    scanf("%d", &nz1);
    sparse sm1[nz1+1];
    read(sm1, &nz1);
    printf("Enter the non-zero elements of the sparse matrix 2: \n");
    scanf("%d", &nz2);
    sparse sm2[nz2+1];
    read(sm2, &nz2);
    int total_nz = nz1+nz2;
    sparse sm3[total_nz + 1];
    if(sm1[0].row != sm2[0].row || sm1[0].col != sm2[0].col)
        printf("Matrix addition not possible\n");
    else
    {
        sm3[0].row = sm1[0].row;
        sm3[0].col = sm1[0].col;
        sm3[0].value = total_nz;
        while(i<= nz1 && j<=nz2)
        {
            if(sm1[i].row == sm2[i].row && sm1[i].col == sm2[i].col)
            {
                sm3[k].row = sm1[i].row;
                sm3[k].col = sm1[i].col;
                sm3[k].value = sm1[i].value + sm2[j].value;
                i++, j++, k++;
            }
            else
            {
                if(sm1[i].row < sm2[j].row || (sm1[i].row == sm2[j].row && sm1[i].col < sm2[j].col))
                {
                    sm3[k++] = sm1[i++];
                }
                else
                {
                    sm3[k++] = sm2[j++];
                }
            }
        }
        while (i <= nz1)
            sm3[k++] = sm1[i++];
        while (j <= nz2)
            sm3[k++] = sm2[j++];
        printf("Resultant sparse matrix in 3-tuple form:\n");
        for (int i = 0; i < k; i++)
        {
            printf("%d %d %d\n", sm3[i].row, sm3[i].col, sm3[i].value);
        }
    }


}
