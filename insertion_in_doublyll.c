#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head, * newnode,* temp,* tail;

void createNewlist()
{
    int ch;
    head = NULL;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the newnode: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
            head = temp = tail = newnode;
        else
        {
            temp->next = newnode;
            tail->next = newnode;
            newnode->prev = temp;
            newnode->prev = tail;
            temp = newnode;
            tail = newnode;
        }
        printf("Do you want to enter the new node(1 for yes and else for no): ");
        scanf("%d", &ch);

    } while (ch == 1);
}

void printDll()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int Length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertBegining()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node you want to insert at the begining: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertEnd()
{
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the new node you want to enter at the end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertAt_N(int count)
{
    int pos;
    int i = 1;

    temp = head;

    printf("\nEnter the position where you want to enter the node(enter the value between 0 and %d): ",count);
    scanf("%d",&pos);
    if(pos == 1)
        insertBegining();
    else if(pos > count || pos < 0)
    {
        printf("The position you entered is wrong!!!!!\nSo, inserting at the end of the list -->");
        insertEnd();
    }
    else if(pos == count)
        insertEnd();
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node to be inserted at %d: ",pos);
        scanf("%d",&newnode->data);

        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

int main()
{
    createNewlist();
    printf("\nDoubly linked list before insertion is: ");
    printDll();
    insertBegining();
    printf("\nDoubly linked list after insertion in the begining is: ");
    printDll();
    insertEnd();
    printf("\nDoubly linked list after insertion in the end is: ");
    printDll();
    int l = Length();
    printf("\nlength is: %d ",l);
    insertAt_N(l);
    printf("\nDoubly linked list after insertion at the N index is: ");
    printDll();
    return 0;
}