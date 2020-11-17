#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

int main()
{
    node * head = NULL;
    node * newnode = NULL;
    node * temp = NULL;

    int n;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d",&n);

    for( int i=0;i<n;i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp->next = head;

    temp = head;
    printf("Circular linked is: ");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    while (temp != head);

        return 0;
}