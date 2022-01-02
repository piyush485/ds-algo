#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

bool Searching(node * head, int n)
{
    node * ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == n)
        {
            printf("Node found !");
            return true;
        }
        ptr = ptr->next;
    }
    printf("Node not found !");
    return false;
}

void Traversal(node * head)
{
    node * ptr = head;
    while(ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{  
    node * head = NULL;
    node * temp = NULL;
    int ch;

    do
    {
        node * newnode = (node *)malloc(sizeof(node));
        printf("Enter new node: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
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
    bool ans = Searching(head, n);
    return 0;   
}