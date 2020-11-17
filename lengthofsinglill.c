#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

void getLength(node * head)
{
    int count = 0;
    node * ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nNumber of nodes is: %d",count);
}

int main()
{
    node * head = NULL;
    node * newnode = NULL;
    node * temp = NULL;

    int n;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++ )
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
    temp = head;
    printf("Linked list is: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    getLength(head);
    return 0;
}