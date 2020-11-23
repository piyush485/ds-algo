#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * newnode, * tail, * temp;

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
        printf("Do you want to enter the new node: ");
        scanf("%d",&ch);
        
    } while (ch == 1);   
}

void printcll()
{
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
    temp = tail->next;

    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;   
}

void deleteBegining()
{
    temp = tail->next;

    if(temp == NULL)
        printf("List is empty!!");
    else if(tail == tail->next)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

void deleteEnd()
{
    node * prev;
    temp = tail->next;
     
    if(temp == NULL)
        printf("List is empty!!");
    else if (tail == tail->next)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
           while(temp->next != tail->next)
           {
               prev = temp;
               temp = temp->next;
           }
           prev->next = tail->next;
           tail = prev;
           free(temp);
    }
}

void deleteAt_N()
{
    int pos;
    int i = 1;
    temp = tail->next;
    node * current = tail->next;

    printf("\nEnter the node from where you want to delete the node(between 1 and %d): ",Length());
    scanf("%d",&pos);

    if(pos < 1 || pos > Length())
        printf("Invalid position!!");
    else if(temp == NULL)
        printf("List is empty!!");
    else if(pos == 1)
        deleteBegining();
    else if(pos == Length())
        deleteEnd();
    else
    {
        while(i < pos - 1)
        {
            current = current->next;
            i++;
        }
        temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

int main()
{
    createcll();
    printf("Circular linked list before deletion: ");
    printcll();
    deleteBegining();
    printf("\nCircular linked list after deletion from the begining: ");
    printcll();
    deleteEnd();
    printf("\nCircular linked list after deletion from the end: ");
    printcll();
    deleteAt_N();
    printf("Circular linked list after deletion from the Nth position: ");
    printcll();
    return 0;
}