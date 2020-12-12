#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int size;
    int front;
    int rear;
    int * arr;
}queue;

int isFull(queue * i)
{
    if(i->rear == i->size - 1)
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

void enqueue(queue * en, int x)
{
    if(isFull(en))
        printf("Queue is full!!\n");
    else 
    {
        en->rear++;
        en->arr[en->rear] = x;
    }
}

int dequeue(queue * de)
{
    int a = -1;
    if(isEmpty(de))
        printf("Queue is empty!!\n");
    else
    {
        de->front++;
        a = de->arr[de->front];
    }
    return a;
}

void display(queue * d)
{
    for(int i = d->front + 1 ; i  < d->rear + 1 ; i++ )
        printf("%d ",d->arr[i]);
    printf("\n");
} 

int main()
{
    queue q;

    q.front = q.rear = -1;

    printf("Enter the size of the Queue: ");
    scanf("%d",&q.size);

    q.arr = (int *)malloc(q.size * sizeof(int));

    int x,ch;
    printf("Enqueing element! \n");
    enqueue(&q, 1);
    printf("Enqueing element! \n");
    enqueue(&q, 2);
    printf("Enqueing element! \n");
    enqueue(&q, 3);
    printf("Enqueing element! \n");
    enqueue(&q, 4);
    printf("Enqueing element! \n");
    enqueue(&q, 5);
    printf("Enqueing element! \n");
    enqueue(&q, 6);
    display(&q);
    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));

    printf("Dequeing element! %d\n", dequeue(&q));
    return 0;
}