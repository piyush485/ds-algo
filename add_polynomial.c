#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
    int exponent, coefficeint;
    struct poly * next;
}poly;

poly * create_poly()
{
    int ch;
    poly * head = NULL;
    poly * tail, * newnode;
    do
    {
        newnode = (poly *)malloc(sizeof(poly));
        printf("Enter the exponent and coefficient: ");
        scanf("%d%d",&newnode->exponent, &newnode->coefficeint);
        newnode->next = NULL;
        if(head == NULL)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do want to enter the new node(1 for yes or else for no): ");
        scanf("%d",&ch);
    } while (ch == 1);
    return head;
}   

poly * add_poly(poly * p1, poly * p2)
{
    poly * l = NULL;
    poly * r = NULL;
    poly * p = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        p = (poly *)malloc(sizeof(poly));
        if(p1->exponent == p2->exponent)
        {
            p->exponent = p1->exponent;
            p->coefficeint = p1->coefficeint + p2->coefficeint;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->exponent > p2->exponent)
        {
            p->exponent = p1->exponent;
            p->coefficeint = p1->coefficeint;
            p1 = p1->next;
        }
        else
        {
            p->exponent = p2->exponent;
            p->coefficeint = p2->coefficeint;
            p2 = p2->next;
        }
        if(l == NULL)
            l = r = p;
        else
        {
            r->next = p;
            r = p;
        }
    }
    if (r != NULL)
        r->next = p1;
    else
        r->next = p2;
    
    return l;
}

void display(poly * temp)
{
    while(temp != NULL)
    {
        printf("%dx^%d ",temp->coefficeint, temp->exponent);
        temp =  temp->next;
    }
}

int main()
{
    poly * p1 = NULL;
    poly * p2 = NULL;
    poly * p3 = NULL;

    printf("\nEnter the first polynomial: \n");
    p1 = create_poly();
    printf("\nEnter the second polynomial: \n");
    p2 = create_poly();
    
    printf("\nFirst polynomial: ");
    display(p1);
    printf("\nSecond polynomial: ");
    display(p2);

    p3 = add_poly(p1, p2);
    printf("Final polynomial: ");
    display(p3);
    return 0;
}