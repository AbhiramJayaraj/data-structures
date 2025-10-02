#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node Node;
Node *f=NULL;
Node *r=NULL;
Node* newnode(int val)
{
    Node *p=(Node*)malloc(sizeof(Node));
    if(!p)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    p->info=val;
    p->link=NULL;
    return p;
}
void insertrear(int val)
{
    Node *p=newnode(val);
    if(!p) return; 
    if(f==NULL)
    {
        f=r=p;
    }
    else
    {
        r->link=p;
        r=p;
    }
}
int isempty()
{
    return (f==NULL);
}
int deletefront()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;    
    }
    int item=f->info;
    Node *p=f;
    f=f->link;
    if(f==NULL) r=NULL; 
    free(p);
    return item;
}
int peek()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return f->info;
}
void display()
{
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    Node *p=f;
    printf("Queue elements:");
    while(p)
    {
        
        printf(" %d",p->info);
        p=p->link;
    }
    
    printf("\n");
}
int main()
{
    int choice,val;
    do
    {
  
    
    
        printf("1.Insert\n2.Delete\n3.Peek\n4.display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
    
        switch(choice)
        {
            case 1:printf("Enter value to be inserted:");
                   scanf("%d",&val);
                   insertrear(val);
                   break;
            case 2:val=deletefront();
                   if(val!=-1)
                   {
                       printf("Deleted element is %d\n",val);
                   }
                   break;
            case 3:val=peek();
                   if(val!=-1)
                   {
                       printf("Front element is %d\n",val);
                   }
                   break;
            case 4:display();
                   break;
            case 5:
                   break;
            default:printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}

