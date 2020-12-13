#include<stdio.h>
#include<stdlib.h>

typedef struct dequeue
{
    int size;
    int front;
    int rear;
    int * arr;
}queue;

void enqueue_front(queue * q, int x)
{
    if((q->front == 0 && q->rear == q->size - 1) || q->front == q->rear + 1)
        printf("Queue is full!!\n");
    else if(q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0 ;
        q->arr[q->front] = x;
        printf("Enqueuing to front: %d\n", x);
    }
    else if(q->front == 0)
    {
        q->front = q->size - 1 ;
        q->arr[q->front] = x ;
        printf("Enqueuing to front: %d\n", x);
    }
    else
    {
        q->front--;
        q->arr[q->front] = x;
        printf("Enqueuing to front: %d\n", x);
    }
}

void enqueue_rear(queue * q, int x)
{
    if ((q->front == 0 && q->rear == q->size - 1) || q->front == q->rear + 1)
        printf("Queue is full!!\n");
    else if(q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0 ;
        q->arr[q->rear] = x;
        printf("Enqueuing to rear: %d\n", x);
    }
    else if(q->rear == q->size - 1)
    {
        q->rear = 0 ;
        q->arr[q->rear] = x;
        printf("Enqueuingto rear:: %d\n", x);
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = x;
        printf("Enqueuing to rear: %d\n", x);
    }
}

void dequeue_front(queue * q)
{
    if(q->front == -1 && q->rear == -1)
        printf("Queue is empty!!\n");
    else if(q->rear == q->front)
        q->rear = q->front = -1;
    else if(q->front == q->size - 1)
    {
        printf("Dequeuing from front: %d\n", q->arr[q->front]);
        q->front = 0;
    }
    else
    {
        printf("Dequeuing from front: %d\n", q->arr[q->front]);
        q->front++;
    }
}

void dequeue_rear(queue *q)
{
    if (q->front == -1 && q->rear == -1)
        printf("Queue is empty!!\n");
    else if (q->rear == q->front)
        q->rear = q->front = -1;
    else if (q->rear == 0)
    {
        printf("Dequeuing from rear: %d\n", q->arr[q->rear]);
        q->rear = q->size - 1;
    }
    else
    {
        printf("Dequeuing from rear: %d\n", q->arr[q->rear]);
        q->rear--;
    }
}

void display(queue *q)
{
    int i = q->front;
    do
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    } while (i != q->rear + 1);
    printf("\n");
}

int main()
{
    queue q;

    q.front = -1;
    q.rear = -1;

    printf("Enter the size of the Queue: ");
    scanf("%d",&q.size);
    q.arr = (int *)malloc(sizeof(int)*q.size);

    enqueue_front(&q, 1);
    enqueue_rear(&q, 2);
    enqueue_front(&q, 3);
    enqueue_rear(&q, 4);
    display(&q);
    dequeue_rear(&q);
    dequeue_front(&q);

    display(&q);

    return 0;
}