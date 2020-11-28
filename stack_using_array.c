#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
        return 1;
    return 0;
}

void push(struct stack * ptr, int data)
{
    if(isFull(ptr))
        printf("Stack overflow !!");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct stack * ptr)
{
    int val;
    if(isEmpty(ptr)){
        printf("Stack underflow ....No ");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
    }  
    return val;
}

void peek(struct stack * ptr)
{
    for(int i = ptr->top ; i >= 0 ; i-- )
        printf("%d ", ptr->arr[i]);
}

int main()
{
    int ch = 1;
    int data;

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));

    printf("Enter the size of the stack: ");
    scanf("%d",&s->size);
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    while(ch >= 1 && ch <= 3)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(s, data);
                break;
            case 2:
                printf("Popped element  %d",pop(s));
                break;
            case 3:
                peek(s);
                break;
            default:
                printf("Invalid statement !!");
                break;
        }
    }
    return 0;
}