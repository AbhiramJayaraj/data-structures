#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
typedef struct node Node;

Node *top = NULL;


Node* newnode(int val) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (!p) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info = val;
    p->link = NULL;
    return p;
}


void push(int val) {
    Node *p = newnode(val);
    if (!p) return;
    p->link = top;
    top = p;
}


int isempty() {
    return (top == NULL);
}


int pop() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1; 
    }
    int item = top->info;
    Node *p = top;
    top = top->link;
    free(p);
    return item;
}


int peek() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->info;
}
void display() {
    if (isempty()) {
        printf("Stack is empty\n");
        return;
    }
    Node *p = top;
    printf("Stack elements: ");
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

int main() {
    int choice, val;
    do {
    
        printf("\n1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
    
    
    
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                val = pop();
                if (val != -1) {
                    printf("Popped element is %d\n", val);
                }
                break;

            case 3:
                val = peek();
                if (val != -1) {
                    printf("Top element is %d\n", val);
                }
                break;

            case 4:
                if (isempty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                display();
                break;

            case 6:
                break;

            default:
                printf("Invalid choice\n");
        }
    }while (choice != 6);

    
    return 0;
}
