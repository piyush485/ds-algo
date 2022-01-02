#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

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

void Traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
}

int CountOccurance(node * head, int n)
{
    node * ptr = head;
    int count = 0;
    for(int i = 0 ; i < Length(head) ; i++ )
    {
        if(ptr->data == n)
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
    printf("\nEnter the node you want to search: ");
    scanf("%d", &n);
    printf("Number of nodes present is: %d", CountOccurance(head, n));
    return 0;
}