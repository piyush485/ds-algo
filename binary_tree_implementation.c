#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}node;

node * create()
{
    int x;
    node * newnode = (node *)malloc(sizeof(node));
    printf("Enter the node(-1 for no node): ");
    scanf("%d", &x);
    
    if(x == -1)
        return NULL;
    newnode->data = x;

    printf("Left child node : \n");
    newnode->left = create();

    printf("Right child node : \n");
    newnode->right = create();

    return newnode;
}

void Preorder(node * root)
{
    if( root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(node * root)
{
    if( root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void Inorder(node * root)
{
    if( root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

int main()
{
    node * root;
    root = create();
    printf("\nPreorder : \n");
    Preorder(root);
    printf("\nPostorder : \n");
    Postorder(root);
    printf("\nInorder : \n");
    Inorder(root);
    return 0;
}