#include <stdio.h>

#define size 10
int top = 0;
int s[size];


int check_empty()
{
	if(top == 0)
		return 1;
	else
		return 0;
}


int check_full()
{
	if(top >= size)
		return 1;
	else
		return 0;
}


void push(int item)
{
	if(check_full())
		printf("Stack is full");
	else
		s[top++] = item;
}


int pop()
{
	int item;
	if(check_empty())
		printf("Stack is empty !!");
	else
		item = s[--top];
	return(item);
}

void peek(){
	if(check_empty())
		printf("Stack is empty !!");
	else
		printf("Top element is %d\n", s[top-1]);
}

void main()
{
	int choice, n;
	do{
		printf("1: Push\n2: Pop\n3: Peek\n4: Status\n5: Exit\n");
		printf("Enter your choice: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if(!check_full())
				{
					printf("Enter the number to be inserted: \n");
					scanf("%d",&n);
					push(n);
					printf("Element inserted successfully.\n");
				}
				else
					printf("Stack is full.\n");
				break;
			case 2: if(!check_empty())
					printf("Popped element is %d\n",pop());
				else
					printf("Stack is empty\n");
				break;
			case 3: peek();
				break;
			case 4: if(check_full())
					printf("Stack is full\n");
				else
					if(check_empty())
						printf("Stack is empty\n");
					else
						printf("Memory available\n");
				break;
			case 5: printf("\nThank you!");
				break;
			default: printf("Invalid input please try again.\n");
		}
		printf("\n");
	} while(choice != 5);
}