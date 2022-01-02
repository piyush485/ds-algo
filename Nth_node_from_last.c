#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void Traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
}

void NthNodeFromLast(node *head, int n)
{
    node *ptr = head;
    node * index = head;
    for (int i = 0; i < n; i++)
        ptr = ptr->next;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        index = index->next;
    }
    printf("Node at index is: %d", index->data);
}

int Length(node *head)
{
    int count = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    node *head = NULL;
    node *temp = NULL;
    int ch;

    do
    {
        node *newnode = (node *)malloc(sizeof(node));
        printf("Enter new node: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Want to continue!!--> ");
        scanf("%d", &ch);
    } while (ch == 1);

    printf("List is: ");
    Traversal(head);
    int n;
    printf("\nEnter the index: ");
    scanf("%d", &n);
    NthNodeFromLast(head, n);
    return 0;
}