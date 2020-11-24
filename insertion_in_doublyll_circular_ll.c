#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head, * newnode, * tail, * temp;

void createDCll()
{
    int ch;
    head = NULL;
    tail = NULL;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = tail = newnode;
            head->next = newnode;
            tail->prev = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to enter the new node(1 for yes or else for no): ");
        scanf("%d",&ch);
        
    } while (ch == 1);
    
}

void printDCll()
{
    temp = head;
    
    if(head == NULL)
        printf("List is empty!!");
    else
    {
        do
        {
            printf("%d ",temp->data);
            temp = temp->next;
        } while (temp != head);    
    }
}

int Length()
{
    int count = 0;
    temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;   
}

void insertBegining()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node to be inserted at the begining: ");
    scanf("%d",&newnode->data);

    if(head == NULL)
    {
        head = tail = newnode;
        head->next = newnode;
        tail->prev - newnode;
    }
    else
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        head = newnode;
    }
}

void insertEnd()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node to be inserted at the end: ");
    scanf("%d", &newnode->data);

    if (head == NULL)
    {
        head = tail = newnode;
        head->next = newnode;
        tail->prev - newnode;
    }
    else
    {
        newnode->prev = tail;
        newnode->next = head;
        tail->next = newnode;
        head->prev = newnode;
        tail = newnode;
    }
}

void insertAt_N()
{
    int pos;
    int i = 1;

    printf("\nEnter the position where you want to enter th new node: ");
    scanf("%d",&pos);
    if(pos < 0 || pos > Length())
        printf("Invalid position!!");
    else if(pos == 1)
        insertBegining();
    else if(pos == Length())
        insertEnd();
    else
    {
        temp = head;
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node to be inserted at %d position: ",pos);
        scanf("%d",&newnode->data);
        while(i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        temp->next->prev =newnode;
    }
}

int main()
{
    createDCll();
    printf("Doubly crircular linked list before insertion: ");
    printDCll(); 
    insertBegining();
    printf("Doubly crircular linked list after insertion in the begining: ");
    printDCll();
    insertEnd();
    printf("Doubly crircular linked list after insertion in the end: ");
    printDCll();
    insertAt_N();
    printf("Doubly crircular linked list after insertion at Nth position: ");
    printDCll();
    return 0;
}