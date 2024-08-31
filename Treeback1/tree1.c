#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char E;
typedef struct tNode
{
    E element;
    struct tNode* left;
    struct tNode* right;
    int flag;
}* tNode;

typedef struct sNode
{
    tNode element;
    struct sNode* next;
}* sNode;

void InitStack(sNode head)
{
    head->next = NULL;
}

void PushStack(sNode head,tNode e1)
{
    sNode s1 = malloc(sizeof(struct sNode));
    if(s1 == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    s1->element = e1;
    s1->next = head->next;
    head ->next = s1;
}
tNode PopStack(sNode head)
{
    sNode next = head->next;
    tNode T = next->element;
    head->next = head->next->next;
    free(next);
    return T;
}
tNode PeakStack(sNode head)
{
    return head->next->element;
}
bool IsEmpty(sNode head)
{
    return head->next == NULL;
}
void Backorder(tNode root)
{
    sNode head = malloc(sizeof(struct sNode));
    InitStack(head);
    while(!IsEmpty(head)||root!=NULL)
    {
        while(root)
        {
            PushStack(head,root);
            root->flag = 0;
            root = root->left;
        }
        tNode T = PeakStack(head);
        if(T->flag == 0)
        {
            T->flag = 1;
            root = T->right;
        }
        else 
        {
            printf("%c",T->element);
            PopStack(head);
            root = NULL;
        }
    }
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
    d->right = d->left = NULL;
    e->right = e->left = NULL;
    f->right = f->left = NULL;
    
    Backorder(a);
    return 0;
}