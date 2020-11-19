#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

void printsll(node * head)
{
    node * ptr = head;
    while(ptr != NULL)
    {
        printf("\nNode is : %d",ptr->data);
        ptr = ptr->next;
    }
}

node * reversesll(node * head)
{
    node * prevNode = NULL;
    node * currentNode = head;
    node * nextNode;
    while(currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    return head;
}

int main()
{
    node * head = NULL;
    node * temp = NULL;
    node * newnode = NULL;

    int ch;

    do
    {
        newnode = (node*)malloc(sizeof(node));
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
        printf("Do you want to enter the new node: ");
        scanf("%d",&ch);
    } while (ch == 1);

    printf("Linked list is: \n");
    printsll(head);
    
    head = reversesll(head);
    printf("\nReversed liked list is: ");
    printsll(head);

    return 0;
}
