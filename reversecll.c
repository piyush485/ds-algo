#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node *newnode, *temp, *tail;

void createcll()
{
    int ch;
    tail = NULL;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);

        if(tail == NULL)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to enter the new node( 1 for yes or else for no): ");
        scanf("%d",&ch);
    } while (ch == 1);
}

void printcll()
{
    temp = tail->next;
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    
}

void reversecll()
{
    node * nextnode, * previous, * current;
    
    current = tail->next;
    nextnode = current->next;

    if(tail == NULL)
        printf("List is empty!!");
    else
    {   
        while(current != tail)
        {
            previous = current;
            current = nextnode;
            nextnode = current->next;
            current->next = previous;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

int main()
{
    createcll();
    printf("Circular linked list before reversing: ");
    printcll();
    reversecll();
    printf("\nCircular linked list after reversing: ");
    printcll();
    return 0;
}

