#include <stdio.h>
#include <ctype.h>

#define size 100
int top = -1;
char stack[size];

void push(char c)
{
    if (top < size - 1)
        stack[++top] = c;
    else
        printf("Stack is full\n");
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void reverse_string(char *str)
{
    int i, len;
    for (len = 0; str[len] != '\0'; len++)
    {
        push(str[len]);
    }
    for (i = 0; i < len; i++)
    {
        str[i] = pop();
    }
    str[len] = '\0';
}

void main()
{
    char str[size];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    reverse_string(str);
    printf("Reversed string: %s\n", str);
}
