#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
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

void Traversal(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
}

node * Reverse(node * head)
{
    node *prevNode = NULL;
    node *currentNode = head;
    node *nextNode;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

bool isPalindrome(node * head)
{
    // first we wil find the middle element of the linked list
    node * ptr = head;
    if(Length(head) %  2 == 0)
        for(int i = 0 ; i < Length(head) / 2 - 1; i++ )
            ptr = ptr->next;
    else
        for(int i = 0 ; i < Length(head) / 2 ; i++ )
            ptr = ptr->next;
    node * middle = Reverse(ptr->next);
    ptr = head;
    int flag = 0;
    while (middle != NULL)
    {
        if(middle->data == ptr->data)
        {
            ptr = ptr->next;
            middle = middle->next;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        return false;
    else    
        return true;
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
    Traversal(head);
    if(isPalindrome(head))
        printf("Is Palindrome ");
    else
        printf("Not Palindrome");
    return 0;
}