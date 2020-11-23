#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * tail, * newnode;

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
        printf("Do you want to enter new node(1 for yes or else for no: ");
        scanf("%d",&ch);
    } while (ch == 1);
}

void printcll()
{
    node * temp;
    if(tail == NULL)
        printf("List is empty!!");
    else
    {
        temp = tail->next;
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while (temp != tail->next);   
    }
}

int Length()
{
    int count = 0;
    node * temp = tail->next;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;   
}

void insertBegining()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node to be inserted at the begining: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }   
}

void insertEnd()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node to inserted at the end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

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
    
}

void insertAt_N()
{
    int pos;
    int i = 1;
    node * temp = tail->next;

    printf("Enter the position where you want to enter the new node: ");
    scanf("%d",&pos);
    if(pos < 0 || pos > Length())
        printf("Invalid positon!!");
    else if(pos == 1)
        insertBegining();
    else if(pos == Length())
        insertEnd();
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node to be inserted at the Nth position: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        while(i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
}

int main()
{
    createcll();
    printf("Circular linked list: ");
    printcll();
    insertBegining();
    printf("Circular linked list after the insertion at the begining: ");
    printcll();
    insertEnd();
    printf("Circular linked list after the insertion at the end: ");
    printcll();
    printf("\nLength of the list is: %d\n",Length());
    insertAt_N();
    printf("Circular linked list after the insertion at the Nth position: ");
    printcll();
    return 0;
}