#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    int x;
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter the node(-1 for no node) : ");
    scanf("%d", &x);

    if (x == -1)
        return NULL;
    newnode->data = x;

    printf("Left child node : \n");
    newnode->left = create();

    printf("Right child node : \n");
    newnode->right = create();

    return newnode;
}

node *search(node *root, int key)
{
    while(root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int main()
{
    node *root;
    root = create();
    node *n = search(root, 7);
    if (n != NULL)
        printf("Found : %d", n->data);
    else
        printf("Not found !!");
    return 0;
}