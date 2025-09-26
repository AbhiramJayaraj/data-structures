#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info, expo;
    struct node *link;
};
typedef struct node Poly;

Poly *a, *b, *c;

Poly* newnode(int val1, int val2)
{
    Poly *p = (Poly*)malloc(sizeof(Poly));
    if(!p)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = val1;  
    p->expo = val2;  
    p->link = NULL;
    return p;
}

Poly* addpoly(Poly *p, Poly *q, Poly *r)
{
    r = (Poly*)malloc(sizeof(Poly));
    Poly *head = r;  

    while(p != NULL && q != NULL)
    {
        if(p->expo == q->expo)   
        {
            r->info = p->info + q->info;
            r->expo = p->expo;
            p = p->link;
            q = q->link;
        }
        else if(p->expo > q->expo)
        {
            r->info = p->info;
            r->expo = p->expo;
            p = p->link;
        }
        else
        {
            r->info = q->info;
            r->expo = q->expo;
            q = q->link;
        }

        if(p != NULL || q != NULL)
        {
            Poly *temp = (Poly*)malloc(sizeof(Poly));
            r->link = temp;
            r = temp;
        }
        else
        {
            r->link = NULL;
        }
    }

    while(p != NULL)
    {
        r->info = p->info;
        r->expo = p->expo;
        p = p->link;
        if(p != NULL)
        {
            Poly *temp = (Poly*)malloc(sizeof(Poly));
            r->link = temp;
            r = temp;
        }
        else
        {
            r->link = NULL;
        }
    }

    while(q != NULL)
    {
        r->info = q->info;
        r->expo = q->expo;
        q = q->link;
        if(q != NULL)
        {
            Poly *temp = (Poly*)malloc(sizeof(Poly));
            r->link = temp;
            r = temp;
        }
        else
        {
            r->link = NULL;
        }
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
        {
            printf(" + ");
        }
    }
    printf("\n");
}

int main()
{
    int choice, val1, val2;
    while(1)
    {
        printf("\n1.Create first polynomial\n2.Create second polynomial\n3.Add polynomials\n4.Display result polynomial\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter coefficient and exponent of first polynomial: ");
                scanf("%d%d",&val1,&val2);
                a = newnode(val1, val2);
                break;
            case 2:
                printf("Enter coefficient and exponent of second polynomial: ");
                scanf("%d%d",&val1,&val2);
                b = newnode(val1, val2);
                break;
            case 3:
                c = addpoly(a, b, c);
                printf("Polynomials added successfully\n");
                break;
            case 4:
                printf("Resultant polynomial: ");
                displaypoly(c);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
