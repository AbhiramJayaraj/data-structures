#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
typedef struct node Node;

Node *head = NULL;


Node* newnode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->info = val;
    p->link = NULL;
    return p;
}


void insertfirst(int val) {
    Node *p = newnode(val);
    p->link = head;
    head = p;
}


void deletenode(int val) {
    Node *p = head, *prev = NULL;
    while (p != NULL && p->info != val) {
        prev = p;
        p = p->link;
    }
    if (p == NULL) {
        printf("Element not found\n");
        return;
    }
    if (prev == NULL) { 
        head = p->link;
    } else {
        prev->link = p->link;
    }
    free(p);
}


void deletefirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *p = head;
    head = head->link;
    free(p);
}


void displaylist() {
    Node *p = head;
    if (p == NULL) {
        printf("List is empty\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}


int countnode() {
    Node *p = head;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}


void insert(int val1, int val2) {
    Node *p = head;
    while (p != NULL && p->info != val1) {
        p = p->link;
    }
    if (p == NULL) {
        printf("Element not found\n");
        return;
    }
    Node *q = newnode(val2);
    q->link = p->link;
    p->link = q;
}

void insertbefore(int val1, int val2) {
    Node *p = head, *prev = NULL;
    while (p != NULL && p->info != val1) {
        prev = p;
        p = p->link;
    }

    if (p == NULL) {
        printf("Element not found\n");
        return;
    }

    Node *q = newnode(val2);
    q->link = p;

    if (p == head) { 
        head = q;
    } else {
        prev->link = q;
    }
}

int main() {
    int choice, val, val1, val2;
    while (1) {
        printf("\n1.Insert first\n2.Delete first\n3.Delete node\n4.Display list\n5.Count nodes\n6.Insert after node\n7.Insert before node\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &val);
            insertfirst(val);
            break;
        case 2:
            deletefirst();
            break;
        case 3:
            printf("Enter value to be deleted: ");
            scanf("%d", &val);
            deletenode(val);
            break;
        case 4:
            displaylist();
            break;
        case 5:
            printf("Number of nodes: %d\n", countnode());
            break;
        case 6:
            printf("Enter value after which to insert: ");
            scanf("%d", &val1);
            printf("Enter value to be inserted: ");
            scanf("%d", &val2);
            insert(val1, val2);
            break;
        case 7:
            printf("Enter value before which to insert: ");
            scanf("%d", &val1);
            printf("Enter value to be inserted: ");
            scanf("%d", &val2);
            insertbefore(val1, val2);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
