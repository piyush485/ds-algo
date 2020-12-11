#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} queue;
queue * head, * tail;
void enqueue(int x)
{
    queue *newnode = (queue *)malloc(sizeof(queue));
    if (newnode == NULL)
        printf("Queue is full!\n");
    else
    {
        newnode->data = x;
        newnode->next = NULL;
        if (head == NULL)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

int dequeue()
{
    int x;
    queue *ptr = head;
    if (head == NULL)
        printf("Queue is empty!!");
    else
    {
        head = head->next;
        x = ptr->data;
        free(ptr);
    }
    return x;
}

void display(queue * head)
{
    queue * ptr = head;
    printf("Queue id : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    tail = NULL;

    int x;
    int ch;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("number to Enqueue: ");
            scanf("%d", &x);
            enqueue(x);
            break;

        case 2:
            printf("Dequing element: %d\n", dequeue());
            break;
        case 3:
            display(head);
            break;
        default:
            printf("Invalid");
            break;
        }
    } while (ch == 1 || ch == 2 || ch == 3);

    return 0;
}