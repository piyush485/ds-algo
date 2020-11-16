#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * deletefromBegining(node * head)
{
    node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

node * deleteAtindex(node * head, int index)
{
    node * p = head;
    node * q = head->next;
    for (int i = 0; i < index-2; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

node * deletefromEnd(node * head)
{
    node * p = head;
    node *q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

node *deletethevalue(node *head, int value)
{
    node *p = head;
    node *q = head->next;
    while(q->data != value && q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if((q->data) == value)
    {
        p->next = q->next;
        free(q);
    }
    else
        printf("Value not found: ");
    return head;
}

int main()
{
    node * head = NULL;
    node * newnode = NULL;
    node * temp = NULL;
    int count = 0;

    int n; 
    printf("\nEnter the number of nodes you want to enter: ");
    scanf("%d",&n);

    for( int i = 0 ; i < n ; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
            count++;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            count++;
        }
    }

    temp = head;
    printf("\nLinked list before deletion: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    //deleting node from begining
    head = deletefromBegining(head);
    temp = head;
    printf("\nAfter deleting node from begining: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    //delete from certain index
    printf("Enter the index from which you want to delete the index: ");
    scanf("%d",&n);
    printf("\nAter deleting the node from the given index: ");
    head = deleteAtindex(head,n);
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    //deleting node from end
    head = deletefromEnd(head);
    temp = head;
    printf("\nAfter deleting node from end: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    //deleting node for the certain data
    printf("\nEnter the data to delete it's node: ");
    scanf("%d",&n);
    printf("\nAter deleting the node for the given data: ");
    head = deletethevalue(head, n);
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}