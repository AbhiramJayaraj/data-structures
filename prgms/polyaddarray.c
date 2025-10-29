#include <stdio.h> 
 
typedef struct 
{ 
    int coeff; 
    int expo; 
} Poly; 
 
int readPoly(Poly p[]) 
{ 
    int deg; 
    printf("Enter the highest degree of the polynomial: "); 
    scanf("%d", &deg); 
    for (int i = deg; i >= 0; i--) 
    { 
        printf("Enter the coefficient of x^%d: ", i); 
        scanf("%d", &p[i].coeff); 
        p[i].expo = i; 
    } 
    return deg; 
} 
 
void displayPoly(Poly p[], int deg) 
{ 
    for (int i = deg; i >= 0; i--) 
    { 
        printf("%dx^%d", p[i].coeff, p[i].expo); 
        if (i != 0) 
            printf(" + "); 
    } 
    printf("\n"); 
}
int addPoly(Poly p[], int deg1, Poly q[], int deg2, Poly result[]) 
{ 
    int degRes; 
    if (deg1 > deg2) 
        degRes = deg1; 
    else 
        degRes = deg2; 
    for (int i = degRes; i >= 0; i--) 
    { 
        int coeff1, coeff2; 
        if (i <= deg1) 
            coeff1 = p[i].coeff; 
        else 
            coeff1 = 0; 
        if (i <= deg2) 
            coeff2 = q[i].coeff; 
        else 
            coeff2 = 0; 
        result[i].coeff = coeff1 + coeff2; 
        result[i].expo = i; 
    } 
    return degRes; 
} 
 
void main() 
{ 
    Poly p[20], q[20], result[20]; 
    int deg1, deg2, degRes; 
    printf("For first polynomial:\n"); 
    deg1 = readPoly(p); 
    printf("First polynomial is: "); 
    displayPoly(p, deg1); 
    printf("\nFor second polynomial:\n"); 
    deg2 = readPoly(q); 
    printf("Second polynomial is: "); 
    displayPoly(q, deg2); 
    degRes = addPoly(p, deg1, q, deg2, result); 
    printf("\nResultant polynomial after addition is: "); 
    displayPoly(result, degRes); 
}


