#include<stdio.h>
#include<stdlib.h>

struct node {
    int info, expo;
    struct node *link;
};
typedef struct node Poly;

Poly *a = NULL, *b = NULL, *c = NULL;

Poly* newnode(int val1, int val2) 
{
    Poly *p = (Poly*)malloc(sizeof(Poly));
    if(!p) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->info = val1;   
    p->expo = val2;   
    p->link = NULL;
    return p;
}


Poly* insertend(Poly *head, int val1, int val2) 
{
    Poly *p = newnode(val1, val2);
    if(head == NULL) 
    {
        return p;
    }
    Poly *temp = head;
    while(temp->link != NULL)
        temp = temp->link;
    temp->link = p;
    return head;
}


Poly* createpoly() 
{
    int n, coeff, exp;
    Poly *head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d%d", &coeff, &exp);
        head = insertend(head, coeff, exp);
    }
    return head;
}


Poly* addpoly(Poly *p, Poly *q) 
{
    Poly *head = NULL, *r = NULL;

    while(p != NULL && q != NULL) 
    {
        int coeff, exp;
        if(p->expo == q->expo) 
        {
            coeff = p->info + q->info;
            exp = p->expo;
            p = p->link;
            q = q->link;
        } else if(p->expo > q->expo) 
        {
            coeff = p->info;
            exp = p->expo;
            p = p->link;
        } else 
        {
            coeff = q->info;
            exp = q->expo;
            q = q->link;
        }

        Poly *temp = newnode(coeff, exp);
        if(head == NULL) 
        {
            head = temp;
            r = head;
        } else 
        {
            r->link = temp;
            r = r->link;
        }
    }

    while(p != NULL) 
    {
        Poly *temp = newnode(p->info, p->expo);
        if(head == NULL) 
        { head = temp; r = head; 
        }
        else 
        { r->link = temp; r = r->link; 
        }
        p = p->link;
    }

    while(q != NULL) 
    {
        Poly *temp = newnode(q->info, q->expo);
        if(head == NULL) 
        { head = temp; r = head; 
        }
        else 
        { r->link = temp; r = r->link; 
        }
        q = q->link;
    }

    return head;
}

void displaypoly(Poly *p) 
{
    if(p == NULL) 
    {
        printf("Polynomial is empty\n");
        return;
    }
    while(p != NULL) 
    {
        printf("%dx^%d", p->info, p->expo);
        p = p->link;
        if(p != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    int choice;
    do
        {
        printf("\n1.Create first polynomial\n2.Create second polynomial\n3.Add polynomials\n4.Display result polynomial\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Creating first polynomial...\n");
                a = createpoly();
                printf("First polynomial: ");
                displaypoly(a);
                break;
            case 2:
                printf("Creating second polynomial...\n");
                b = createpoly();
                printf("Second polynomial: ");
                displaypoly(b);
                break;
            case 3:
                c = addpoly(a, b);
                printf("Polynomials added successfully\n");
                break;
            case 4:
                printf("Resultant polynomial: ");
                displaypoly(c);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}
