#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} stack;

int isEmpty(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}

int match(char a, char b)
{
    if(a == '{' && b == '}')
        return 1;
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    return 0;
}

stack *push(stack *p, char exp)
{
    if (isFull(p))
        printf("Stack is empty!!");
    else
    {
        p->top++;
        p->arr[p->top] = exp;
    }
}

char pop(stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack is full!!");
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(sp, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (isEmpty(sp))
                    return 0;
                char Match = pop(sp);
                if(!match(Match, exp[i]))
                    return 0;
            }
    }
    if(isEmpty(sp))
        return 1;
    else
        return 0;
}

int main()
{
    char *str = "[{()}])";

    if (parenthesisMatch(str))
        printf("IN SEQUEENCE !!");
    else
        printf("NOT IN SEQUEENCE !!");
    return 0;
}
