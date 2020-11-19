#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head, * newnode,* temp;

void createNewNode()
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
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to enter the new node: ");
        scanf("%d", &ch);

    } while (ch == 1);
}

void printdll()
{
    temp = head;
    printf("\nDoubly linked list is: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    createNewNode();
    printdll();
    return 0;
}

