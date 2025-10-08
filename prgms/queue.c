#include <stdio.h>
#define size 50

int q[size];
int front = -1, rear = -1;

int insertque(int item) 
{
    if((rear + 1) % size == front) 
    {
        printf("Queue is full\n");
        return 0;
    } else 
    {
        if(front == -1) 
        {
            front = 0;
            rear = 0;
        } else 
        {
            rear = (rear + 1) % size;
        }
        q[rear] = item;
    }
    return 1;
}

int deleteque() 
{
    if(front == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    } else 
    {
        int item = q[front];
        if(front == rear) 
        { 
            front = -1;
            rear = -1;
        } else 
        {
            front = (front + 1) % size;
        }
        return item;
    }
}

void peek() 
{
    if(front == -1)
        printf("Queue is empty\n");
    else
        printf("Front element is %d\n", q[front]);
}

int check_empty() 
{
    return front == -1;
}

int check_full() 
{
    return (rear + 1) % size == front;
}

void displayqueue() 
{
    if (check_empty()) 
    {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while (i != -1) 
    {
        printf("%d ", q[i]);
        if (i == rear) 
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() 
{
    int choice, item;
    do 
    {
        printf("\n1: Insert\n2: Delete\n3: Peek\n4: Status\n5: displayqueue\n6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insertque(item);
                break;
            case 2:
                item = deleteque();
                if(item != -1)
                    printf("Deleted item is %d\n", item);
                break;
            case 3:
                peek();
                break;
            case 4:
                if(check_empty())
                    printf("Queue is empty\n");
                else if(check_full())
                    printf("Queue is full\n");
                else
                    printf("Queue has space available\n");
                break;
           case 5:
            	displayqueue();
            	break;
           case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    return 0;
}
