#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;

node * insertbegining(node * head, int data)
{
    node * ptr = (node*)malloc(sizeof(node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

node *insertbetween(node * head, int data,int n)
{
    node * ptr = (node *)malloc(sizeof(node));
    node * index = head;
    int count = 0;
    while(count != n-1)
    {
        index = index->next;
        count++;
    }
    ptr->data = data;
    ptr->next = index->next;
    index->next = ptr;
    return head;
}

node *insertend(node * head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    node * index = head;
    ptr->data = data;
    while(index->next !=NULL)
    {
        index = index->next;
    }
    index->next = ptr;
    ptr->next = NULL;
    return head;
}

node *insertafternode(node * head, node * prevNode, int data)
{
    node * ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
}

int main()
{
    node * head = NULL;
    node * newnode = NULL;
    node * temp = NULL;
    int n;
    printf("How many node you want to enter: ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&(newnode->data));
        newnode->next = NULL;
        
        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    //taking newnode to insert at the begining
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the new node you want to insert at the begining of the node: ");
    scanf("%d",&newnode->data);
    head = insertbegining(head, newnode->data);


    //taking index and node to be entered at the middle of the list
    printf("Enter the index where you want to enter the node: ");
    scanf("%d",&n);
    printf("Enter the node you want to enter: ");
    scanf("%d",&newnode->data);
    head = insertbetween(head, newnode->data, n);

    //taking newnode to enter the node at the end
    printf("Enter the node you want to enter at the end: ");
    scanf("%d",&newnode->data);
    head = insertend(head,newnode->data);

    //taking node to enter the node afer a certain enter
    //head = insertafternode(head, prevNode, data)
    
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return 0;
}