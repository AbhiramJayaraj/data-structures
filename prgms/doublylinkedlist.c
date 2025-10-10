#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
typedef struct node Node;

Node *head = NULL;
Node *tail = NULL;

Node* newnode(int val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = val;
    p->prev = p->next = NULL;
    return p;
}

Node* insertfirst(int val)
{
    Node *p = newnode(val);
    if(head == NULL)
    {
        head = tail = p;
    }
    else
    {
        p->next = head;
        head->prev = p;
        head = p;
    }
    return p;
}

Node* insertend(int val)
{
    Node *p = newnode(val);
    if(tail == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
    return p;
}

void displaylist()
{
    Node *p = head;
    if(p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

Node* insertafter(int val1, int val2)
{
    Node *p = head;
    while(p != NULL && p->info != val1)
        p = p->next;

    if(p == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }

    Node *q = newnode(val2);
    q->prev = p;
    q->next = p->next;

    if(p->next == NULL)
        tail = q;
    else
        p->next->prev = q;

    p->next = q;
    return q;
}

Node* insertbefore(int val1, int val2)
{
    Node *p = head;
    while(p != NULL && p->info != val1)
        p = p->next;

    if(p == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }

    Node *q = newnode(val2);
    q->next = p;
    q->prev = p->prev;

    if(p->prev == NULL)
        head = q;
    else
        p->prev->next = q;

    p->prev = q;
    return q;
}

void deletefirst()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *p = head;
    if(head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    free(p);
    printf("First node deleted.\n");
}

void deletenode(int val)
{
    Node *p = head;
    while(p != NULL && p->info != val)
        p = p->next;

    if(p == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(p->prev == NULL)
        head = p->next;
    else
        p->prev->next = p->next;

    if(p->next == NULL)
        tail = p->prev;
    else
        p->next->prev = p->prev;

    free(p);
    printf("Node with value %d deleted.\n", val);
}

int main()
{
    int choice, val1, val2;
    while(1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Display list\n");
        printf("6. Delete first node\n");
        printf("7. Delete specific node\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val1);
                insertfirst(val1);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val1);
                insertend(val1);
                break;
            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &val1);
                printf("Enter value to insert: ");
                scanf("%d", &val2);
                insertafter(val1, val2);
                break;
            case 4:
                printf("Enter value before which to insert: ");
                scanf("%d", &val1);
                printf("Enter value to insert: ");
                scanf("%d", &val2);
                insertbefore(val1, val2);
                break;
            case 5:
                displaylist();
                break;
            case 6:
                deletefirst();
                break;
            case 7:
                printf("Enter the value to be deleted: ");
                scanf("%d", &val1);
                deletenode(val1);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
