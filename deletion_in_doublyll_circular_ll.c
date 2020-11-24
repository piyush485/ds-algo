#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * newnode, * head, * tail, * temp;

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
        printf("list is empty!!");
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

void deleteBegining()
{
    temp = head;
    if (head == NULL)
        printf("List is empty!!");
    else if(head == head->next)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        head->next->prev = tail;
        tail->next = head->next;
        head = head->next;
        free(temp);
    }
}

void deleteEnd()
{
    temp = tail;
    if(head == NULL)
        printf("List is empty!!");
    else
    {
        tail->prev->next = head;
        head->prev = tail->prev;
        free(temp);
    }
}

void deleteAt_N()
{
    int pos;
    int i = 1;

    temp = head;

    printf("\nEnter the position from where you want to delete the node: ");
    scanf("%d",&pos);

    if(pos < 0 || pos > Length())
        printf("Invalid position!!");
    else if(pos == 1)
        deleteBegining();
    else if(pos == Length())
        deleteEnd();
    else
    {
        while(i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }   
}

int main()
{
    createDCll();
    printf("Doubly crircular linked list before deletion: ");
    printDCll();
    deleteBegining();
    printf("\nDoubly crircular linked list after deletion from begining: ");
    printDCll();
    deleteEnd();
    printf("\nDoubly crircular linked list after deletion from end: ");
    printDCll();
    deleteAt_N();
    printf("\nDoubly crircular linked list after deletion from the Nth position: ");
    printDCll();
    return 0;
}