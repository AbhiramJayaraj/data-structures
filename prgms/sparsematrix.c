#include<stdio.h>
typedef struct {
    int row;
    int col;
    int value;
} Sparse;
void main()
{
    int m,n,nz=0;
    printf("enter the dimension of the matrix:");
    scanf("%d%d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          {  scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
                nz++;
          }
          Sparse sm[nz+1];
    sm[0].row = m;
    sm[0].col = n;
    sm[0].value = nz;
    int k=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          if(a[i][j]!=0)
          {
              sm[k].row = i;
              sm[k].col = j;
              sm[k].value = a[i][j];
              k++;
          }
    printf("Sparse matrix representation:\n");
    printf("Row\tCol\tValue\n");
    for(int i=0;i<=nz;i++)
        printf("%d\t%d\t%d\n", sm[i].row, sm[i].col, sm[i].value);
    printf("Sparse matrix representation completed.\n");
    
}