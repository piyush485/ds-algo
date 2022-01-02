#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

node * RemoveDuplicates(node * head)
{
    node * current_node = head;
    node * next_node = current_node->next;
    int i = 0;
    while(next_node)
    {
        if(current_node->data == next_node->data)
        {
            node *ptr = next_node;
            next_node = next_node->next;
            current_node->next = next_node;
            free(ptr);
            i = 1;
        }
        else
            current_node = current_node->next;
        if(i == 0)
            next_node = next_node->next;
        i = 0;
    }
    return head;
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
    printf("\nLinked list before deletion of duplicates nodes: ");
    Traversal(head);
    head = RemoveDuplicates(head);
    printf("\nLinked list after deletion of duplicates nodes: ");
    Traversal(head);
    return 0;
}