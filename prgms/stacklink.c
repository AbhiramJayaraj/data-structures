#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};
typedef struct node Node;

Node *top = NULL;

// Create new node
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

// Push operation
void push(int val) {
    Node *p = newnode(val);
    if (!p) return; // malloc failed
    p->link = top;
    top = p;
}

// Check empty
int isempty() {
    return (top == NULL);
}

// Pop operation
int pop() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1; // sentinel
    }
    int item = top->info;
    Node *p = top;
    top = top->link;
    free(p);
    return item;
}

// Peek operation
int peek() {
    if (isempty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->info;
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Exit\n");
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
