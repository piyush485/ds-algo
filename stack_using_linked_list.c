#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack * next;
}stack;

int isEmpty(stack * top)
{
    if(top == NULL)
        return 1;
    return 0;
}

int isFull(stack * top)
{
    stack * p = (stack *)malloc(sizeof(stack));
    if(p == NULL)
        return 1;
    return 0;
}

void display(stack * ptr)
{
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

stack * push(stack * top, int x)
{
    if(isFull(top))
        printf("\nStack overflow!!\n");
    else
    {
        stack * n = (stack *)malloc(sizeof(stack));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }   
}

int pop(stack ** top)
{
    if(isEmpty(*top))
        printf("\nStack underflow!!\n");
    else
    {
        stack *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}


int main()
{
    stack * top = NULL;

    int x;
    printf("Enter the element: ");
    scanf("%d",&x);
    top = push(top, x);
    printf("Enter the element: ");
    scanf("%d", &x);
    top = push(top, x);
    printf("Enter the element: ");
    scanf("%d", &x);
    top = push(top, x);
    printf("Enter the element: ");
    scanf("%d", &x);
    top = push(top, x);
    printf("Enter the element: ");
    scanf("%d", &x);
    top = push(top, x);
    pop(&top);
    display(top);
    return 0;
}

