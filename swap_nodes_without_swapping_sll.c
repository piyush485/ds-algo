// not done

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

void swap(node * head, int x, int y)
{
    if(x == y)
        return;
    
    node * prevX = NULL;
    node * currX = head;
    node * prevY = NULL;
    node * currY = head;

    while(currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    while(currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if(currX == NULL || currY == NULL)
        return;

    if(prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if(prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    node * temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
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
    int x, y;
    printf("Enter the element of x and y: ");
    scanf("%d%d", &x, &y);
    swap(head, x, y);
    printf("Linked list after swapping: ");
    Traversal(head);
    return 0;
}