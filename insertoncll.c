#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node * head;

void printcll(node *head)
{
    node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

node * insertBegining(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;

    node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    head = ptr;
    return head;
}

int main()
{
    node * newnode = NULL;
    node * temp = NULL;

    int ch;

    do
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to enter the new node: ");
        scanf("%d", &ch);
    } while (ch == 1);

    newnode = (node *)malloc(sizeof(node));
    
    printf("Enter the new node to be inserted: ");
    scanf("%d",&newnode->data);
    printf("Circular linked list: ");
    printcll(head);
    head = insertBegining(head, newnode->data);
    printf("Circular linked list after insertion: ");
    printcll(head);

    return 0;
}
