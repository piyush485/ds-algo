#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}node;

node * head, * newnode, * temp, * tail;

void createNewlist()
{
    int ch;
    head = NULL;

    do
    {
        newnode = (node*)malloc(sizeof(node));
        printf("Enter the new node: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head == NULL)
            head = temp = tail = newnode;
        else
        {
            temp->next = newnode;
            tail->next = newnode;
            newnode->prev = temp;
            newnode->prev = tail;
            temp = newnode;
            tail = newnode;
        }
        printf("Do you want to enter the new node(1 for yes and else for no): ");
        scanf("%d",&ch);

    } while (ch == 1);
    
}

void printDll()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

}

int Length()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
    
}

void deleteBegining()
{
    if(head == NULL)
        printf("List is empty!!");
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteEnd()
{
    if(head == NULL)
        printf("List is empty!!");
    else
    {
        temp = tail;
        tail->prev->next = NULL;//tail = tail->prev;
        tail = tail->prev;//tail->next = NULL;
        free(temp);
    }
}

void deleteFrom_N(int count)
{
    int pos;
    int i = 1;

    temp = head;

    printf("Enter the position from where you want to delete the node:(enter the value from 1 to %d): ",count);
    scanf("%d",&pos);
    if(pos == 1)
        deleteBegining();
    else if(pos == count)
        deleteEnd();
    else if(pos > count || pos < 0)
    {
        printf("The position you entered is wrong!!!!!\nSo, inserting at the end of the list -->");
        deleteEnd();
    }
    else
    {
        while(i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

int main()
{
    createNewlist();
    printf("\nDoubly linked list before deletion is: ");
    printDll();
    deleteBegining();
    printf("\nDoubly linked list after deletion from the begining is: ");
    printDll();
    deleteEnd();
    printf("\nDoubly linked list after deletion from the end is: ");
    printDll();
    int l = Length();
    printf("\nlength is: %d \n", l);
    deleteFrom_N(l);
    printf("\nDoubly linked list after deletion from the Nth index is: ");
    printDll();
    return 0;
}