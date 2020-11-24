#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * newnode, * head, * tail, * temp;

void creatDCll()
{
    int ch;
    tail = NULL;
    head = NULL;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);

        if(head == NULL)
        {
            head = tail = newnode;
            head->next = head;
            tail->prev = tail;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to enter the new node(1 for yes or else for no: ");
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
        }
        while (temp != tail);
    }
}

int main()
{
    creatDCll();
    printf("Doubly crircular linked list: ");
    printDCll();
    return 0;
}