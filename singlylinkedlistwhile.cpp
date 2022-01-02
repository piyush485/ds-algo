#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next; 
}node;

int main()
{
    int ch = 1;
    node * head = NULL;
    node * temp = NULL;
    node * newnode = NULL;
    for(int i = 0; i < 5 ; i++)
    {
        newnode = (node*)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&(newnode->data));
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to enter new node(y/n): ");
        scanf("%d",&ch);
    }
    
    temp = head;
    while (temp != NULL)
    {
        {
        printf("%d ",temp->data);
        temp = temp->next;
        }
    }
    
    return 0;
}