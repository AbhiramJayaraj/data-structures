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

// Insert at beginning
Node* newnode(int val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = val;
    p->prev = NULL;
    p->next = head;

    if(head == NULL)   // fixed comparison
    {
        head = tail = p;
    }
    else
    {
        head->prev = p;
        head = p;
    }
    return p;
}

// Insert at end
Node* insertend(int val)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = val;
    p->next = NULL;
    p->prev = tail;

    if(tail == NULL)
    {
        head = tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    return p;
}

// Display list
void displaylist()
{
    Node *p = head;
    if(p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

// Insert after a node
Node* insertafter(int val1, int val2)
{
    Node *p = head;
    while(p != NULL && p->info != val1)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }

    Node *q = (Node*)malloc(sizeof(Node));
    if(!q)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->info = val2;
    q->prev = p;
    q->next = p->next;

    if(p->next == NULL)   // fixed assignment
    {
        tail = q;
    }
    else
    {
        p->next->prev = q;
    }
    p->next = q;
    return q;
}

// Insert before a node
Node* insertbefore(int val1, int val2)
{
    Node *p = head;
    while(p != NULL && p->info != val1)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }

    Node *q = (Node*)malloc(sizeof(Node));
    if(!q)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->info = val2;
    q->next = p;
    q->prev = p->prev;

    if(p->prev == NULL)
    {
        head = q;
    }
    else
    {
        p->prev->next = q;
    }
    p->prev = q;
    return q;
}

// Delete entire list
void deletelist()
{
    Node *p = head;
    if(p == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(head != NULL)
    {
        head = head->next;
        free(p);
        p = head;
    }
    tail = NULL;
    printf("List deleted successfully\n");
}

int main()
{
    int choice, val1, val2;
    while(1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Insert before a node\n");
        printf("5. Display list\n");
        printf("6. Delete list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val1);
                newnode(val1);
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
                deletelist();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


