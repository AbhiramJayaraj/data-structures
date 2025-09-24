#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    int expo;
} Poly;

Poly *p, *q, *r;
int i, n;

void readpoly(Poly **ptr)
{
    printf("Enter the highest degree of polynomial: ");
    scanf("%d", &n);
    *ptr = (Poly*)malloc((n + 1) * sizeof(Poly));
    Poly *a = *ptr;  // temporary pointer
    for(i = n; i >= 0; i--)
    {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &(a->info));
        a->expo = i;
        a++;
    }
}

void displaypoly(Poly *p)
{
    Poly *a = p;  // temporary pointer
    for(i = n; i >= 0; i--)
    {
        printf("%dx^%d", a->info, a->expo);
        a++;
        if(i != 0)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void addpoly(Poly *p, Poly *q, Poly *r)
{
    Poly *a = p;  // temporary pointer for first polynomial
    Poly *b = q;  // temporary pointer for second polynomial
    Poly *c = r;  // temporary pointer for result polynomial
    for(i = n; i >= 0; i--)
    {
        c->info = a->info + b->info;
        c->expo = a->expo;
        a++; b++; c++;
    }
}

int main()
{
    printf("For first polynomial:\n");
    readpoly(&p);
    printf("First polynomial is: ");
    displaypoly(p);

    printf("For second polynomial:\n");
    readpoly(&q);
    printf("Second polynomial is: ");
    displaypoly(q);

    r = (Poly*)malloc((n + 1) * sizeof(Poly));
    addpoly(p, q, r);
    printf("Resultant polynomial after addition is: ");
    displaypoly(r);

    free(p);
    free(q);
    free(r);
    return 0;
}

