#include<stdio.h>
#define size 10
int top=0;
int item;
int s[size];
int isFull() {
    if(top >= size) {
        return 1; // Stack is full
    }
    return 0; // Stack is not full
}
int isEmpty() {
    if(top == 0) {
        return 1; // Stack is empty
    }
    return 0; // Stack is not empty
}
void reverse() {
    int i;
    for(i = 0; i < top; i++) {
        printf("%c", s[top - i - 1]);
    }
    printf("\n");
}
void push(char c) {
    if(isFull()) {
        printf("Stack is full, cannot push %c\n", c);
    } else {
        s[top++] = c;
    }
}
void pop() {
    if(isEmpty()) {
        printf("Stack is empty, cannot pop\n");
    } else {
        top--;
    }
}
int main() {
    char str[size];
    printf("Enter a string: ");
    fgets(str, size, stdin);
    
    // Push characters onto the stack
    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        push(str[i]);
    }
    
    // Reverse the string using the stack
    printf("Reversed string: ");
    reverse();
    
    return 0;
}