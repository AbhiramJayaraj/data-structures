#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
struct node 
{ 
    struct node *prev; 
    char url[100]; 
    struct node *next; 
}; 
 
typedef struct node Node; 
 
Node *current = NULL; 
 
Node *newnode(char url[]) 
{ 
    Node *p = (Node *)malloc(sizeof(Node)); 
    strcpy(p->url, url); 
    p->next = p->prev = NULL; 
    return p; 
} 
 
void new_page(char url[]) 
{ 
    Node *p = newnode(url); 
    if (current == NULL) 
        current = p; 
    else 
    { 
        current->next = p; 
        p->prev = current;
        current = p; 
    } 
    printf("Navigated to: %s\n", current->url);     
} 
 
void back() 
{ 
    if (current == NULL || current->prev == NULL) 
    { 
        printf("No previous page.\n"); 
        return; 
    } 
    current = current->prev; 
    printf("Navigated back to: %s\n", current->url); 
} 
 
void forward() 
{ 
    if (current == NULL || current->next == NULL) 
    { 
        printf("No next page.\n"); 
        return; 
    } 
    current = current->next; 
    printf("Navigated forward to: %s\n", current->url); 
} 
 
void display_history() 
{ 
    if (current == NULL) 
    { 
        printf("No browsing history.\n"); 
        return;
       } 
    Node *p = current; 
    while (p->prev != NULL) 
        p = p->prev; 
    printf("Browsing History:\n"); 
    while (p != NULL) 
    { 
        if (p == current) 
            printf("-> %s (current)\n", p->url); 
        else 
            printf("   %s\n", p->url); 
        p = p->next; 
    } 
} 
 
void free_history() 
{ 
    if (current == NULL) 
        return; 
    Node *p = current; 
    while (p->prev != NULL) 
        p = p->prev; 
    Node *temp; 
    while (p != NULL) 
    { 
        temp = p; 
        p = p->next; 
        free(temp); 
    } 
    current = NULL; 
} 
 
void main()
{ 
    int choice; 
    char url[100]; 
    do 
    { 
        printf("\nMenu:\n"); 
        printf("1. New Page\n"); 
        printf("2. Back\n"); 
        printf("3. Forward\n"); 
        printf("4. Display History\n"); 
        printf("5. Clear History\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) 
        { 
        case 1: 
            printf("Enter URL: "); 
            scanf("%s", url); 
            new_page(url); 
            break; 
        case 2: 
            back(); 
            break; 
        case 3: 
            forward(); 
            break; 
        case 4: 
            display_history(); 
            break; 
        case 5: 
            free_history(); 
            printf("History cleared.\n"); 
               break; 
        case 6: 
            printf("Exiting...\n"); 
            break; 
        default: 
            printf("Invalid choice!\n"); 
        } 
    } while (choice != 6); 
} 