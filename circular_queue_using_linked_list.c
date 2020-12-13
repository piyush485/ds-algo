#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    struct queue * next;
}queue;

queue * head = NULL;
queue * tail= NULL;

void enqueue(int data)
{
    queue * newnode = (queue *)malloc(sizeof(queue));
    newnode->data = data;

    if(head == NULL)
    {
        head = tail = newnode;
        tail->next = head;
        printf("Enqueing element! %d\n", data);
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
        printf("Enqueing element! %d\n", data);
    }
}

int dequeue()
{
    int data = -1;
    queue * ptr = head;
    if(head == NULL)
        printf("queue is empty!!\n");
    else if(head == tail)
    {
        head = tail = NULL;
        data = ptr->data;
        free(ptr);
    }
    else
    {
        head = head->next;
        tail->next = head;
        data = ptr->data;
        free(ptr);
    }
    return data;
}

void display()
{
    queue * ptr = head;
    if(head == NULL)
        printf("Queue is empty!!\n");
    else
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    printf("Dequeuing element: %d\n",dequeue());
    printf("Dequeuing element: %d\n",dequeue());
    printf("Dequeuing element: %d\n",dequeue());
    printf("Dequeuing element: %d\n",dequeue());
    printf("Dequeuing element: %d\n",dequeue());
    return 0;
}