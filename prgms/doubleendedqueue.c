#include <stdio.h>
#define size 50

int q[size];
int front = -1, rear = -1;

int isfull() {
    return (front == (rear + 1) % size);
}

int isempty() {
    return (front == -1);
}

int insertrear(int item) {
    if (isfull()) {
        printf("Queue is full\n");
        return 0;
    }
    if (isempty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    q[rear] = item;
    return 1;
}

int deletefront() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    return item;
}

int insertfront(int item) {
    if (isfull()) {
        printf("Queue is full\n");
        return 0;
    }
    if (isempty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + size) % size;
    }
    q[front] = item;
    return 1;
}

int deleterear() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q[rear];
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + size) % size;  
    }
    return item;
}
void displayqueue() {
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (i != -1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\n1: Insert at rear\n2: Delete from front\n3: Insert at front\n4: Delete from rear\n5: displayqueue\n6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertrear(item);
                break;
            case 2:
                item = deletefront();
                if (item != -1)
                    printf("Deleted item is %d\n", item);
                break;
            case 3:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertfront(item);
                break;
            case 4:
                item = deleterear();
                if (item != -1)
                    printf("Deleted item is %d\n", item);
                break;
            case 5:
                displayqueue();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
