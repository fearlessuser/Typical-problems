#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char E;
typedef struct tNode
{
    E element;
    struct tNode*left;
    struct tNode*right;
}*tNode;

typedef struct qNode
{
    tNode element;
    struct qNode* next;
}*qNode;

typedef struct queue
{
    qNode front,rear;
}*queue;

void Initqueue(queue q1)
{
    qNode node = malloc(sizeof(struct qNode));
    if(node == NULL)
    {
        printf("failed malloc\n");
        exit(-1);
    }
    q1->front = q1->rear = node;
}

void Pushqueue(queue q,tNode t1)
{
    qNode node = malloc(sizeof(struct qNode));
    if(node == NULL)
    {
        printf("failed malloc\n");
        exit(-1);
    }
    node->element = t1;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;    
}

tNode Popqueue(queue q)
{
    qNode next = q->front->next;
    tNode T = next->element;
    q->front->next = q->front->next->next;
    if(q->rear == next) q->rear = q->front;
    free(next);
    return T;
}

bool Isempty(queue q)
{
    return q->front == q->rear;
}

void LevelOrder(tNode root)
{
    queue q = malloc(sizeof(struct queue));
    Initqueue(q);
    while(root||!Isempty(q))
    {
        if(Isempty(q))
        {
            Pushqueue(q,root);
            root = NULL;
        }    
        else
        {
            tNode T = Popqueue(q);
            printf("%c",T->element);
            if(T->left)
            {
                Pushqueue(q,T->left);
            }
            if(T->right)
            {
                Pushqueue(q,T->right);
            }
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

    LevelOrder(a);
    return 0;
}