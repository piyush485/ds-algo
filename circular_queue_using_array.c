#include <stdio.h>
#include <stdlib.h>

typedef struct Circular_Queue
{
    int size;
    int front;
    int rear;
    int *arr;
} queue;

int isFull(queue *i)
{
    if (((i->rear + 1) % i->size) == i->front)
        return 1;
    else
        return 0;
}

int isEmpty(queue *i)
{
    if (i->rear == i->front)
        return 1;
    else
        return 0;
}

void enqueue(queue *en, int x)
{
    if (isFull(en))
        printf("Circular_Queue is full!!\n");
    else
    {
        en->rear = (en->rear + 1) % en->size;
        en->arr[en->rear] = x;
        printf("Enqueing element! %d\n", x);
    }
}

int dequeue(queue *de)
{
    int a = -1;
    if (isEmpty(de))
        printf("Circular_Queue is empty!!\n");
    else
    {
        de->front = (de->front + 1) % de->size;
        a = de->arr[de->front];
    }
    return a;
}

void display(queue *d)
{
    for (int i = d->front + 1; i < d->rear + 1; i++)
        printf("%d ", d->arr[i]);
    printf("\n");
}

int main()
{
    queue q;

    q.front = q.rear = 0;

    printf("Enter the size of the Circular_Queue(with one size extra): ");
    scanf("%d", &q.size);

    q.arr = (int *)malloc(q.size * sizeof(int));

    int x, ch;
    
    enqueue(&q, 1);
    
    enqueue(&q, 2);

    enqueue(&q, 3);

    enqueue(&q, 4);

    enqueue(&q, 5);

    enqueue(&q, 6);
    display(&q);
    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));
    return 0;
}