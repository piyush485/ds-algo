#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node * next;
    int flag;
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

bool DetectLoop(node * head)
{
    node * slow_ptr = head;
    node * fast_ptr = head;
    while(fast_ptr && slow_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr)
            return true;
    }
    return false;
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
        newnode->flag = 0;

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
    head->next->next->next->next = head;
    if(DetectLoop(head))
        printf("Loop Found !");
    else
        printf("Loop Not Found !");
    return 0;
}