#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head, * newnode, * temp, * tail;

void createnode()
{
    int ch;
    head = NULL;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL)
            head = temp = tail = newnode;
        else
        {
            temp->next = newnode;
            tail->next = newnode;
            newnode->prev = temp;
            newnode->prev = tail;
            tail = newnode;
            temp = newnode;
        }
        printf("Do want to enter the new node: ");
        scanf("%d",&ch);
        
    } while (ch == 1);
}

void printdll()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void reversedll()
{
    node * current = head;
    while(current != NULL)
    {
        node * nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
}

int main()
{
    createnode();
    printf("Doubly linked list before reversing: ");
    printdll();
    reversedll();
    printf("\nDoubly linked list after reversing:");
    printdll();
    return 0;
}