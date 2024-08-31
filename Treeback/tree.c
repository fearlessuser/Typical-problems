#include<stdio.h>
#include<stdlib.h>

typedef char E;
typedef struct tNode
{
    E element;
    struct tNode* left;
    struct tNode* right;
}* tNode;

void BackOrder(tNode root)
{
    if(root == NULL) return;
    BackOrder(root->left);
    BackOrder(root->right);
    printf("%c",root->element);
}
int main()
{
    tNode a = malloc(sizeof(struct tNode));
    tNode b = malloc(sizeof(struct tNode));
    tNode c = malloc(sizeof(struct tNode));
    tNode d = malloc(sizeof(struct tNode));
    tNode e = malloc(sizeof(struct tNode));
    tNode f = malloc(sizeof(struct tNode));

    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    c->left = NULL;
    d->left = d->right = NULL;
    f->left = f->right = NULL;
    e->left = e->right = NULL;

    BackOrder(a);
    return 0;

}