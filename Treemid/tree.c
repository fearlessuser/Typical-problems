#include<stdio.h>
#include<stdlib.h>

typedef char element;
typedef struct TreeNode
{
    element e1;
    struct TreeNode* left;
    struct TreeNode* right;
}* Node;

void Preorder(Node root)
{
    if(root == NULL) return;
    Preorder(root->left);
    printf("%c",root->e1);
    Preorder(root->right);
}
int main()
{
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));

    a->e1 = 'A';
    b->e1 = 'B';
    c->e1 = 'C';
    d->e1 = 'D';
    e->e1 = 'E';
    f->e1 = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->right = d->left = NULL;
    e->right = e->left = NULL;
    f->right = f->left = NULL;
    
    Preorder(a);
    return 0;
}