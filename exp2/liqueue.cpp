#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 6

typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    struct LNode *previous;
};

typedef struct
{
    LNode *front;
    LNode *rear;
} SqQueue;

// 初始化
SqQueue *init()
{
    SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// 判空
bool isEmpty(SqQueue *p)
{
    return p->front == NULL || p->rear == NULL;
}

// 进队
void enqueue(SqQueue *&q, ElemType e)
{
    LNode *n = (LNode *)malloc(sizeof(LNode));
    n->previous = q->rear;
    if (q->rear != NULL)
        q->rear->next = n;
    n->next = NULL;
    n->data = e;
    q->rear = n;
    if (q->front == NULL)
        q->front = n;
}

// 出队
ElemType dequeue(SqQueue *&p)
{
    if (isEmpty(p))
        return NULL;
    LNode *departed = p->front;
    ElemType e = departed->data;
    p->front = departed->next;
    if (p->front != NULL)
        p->front->previous = NULL;
    free(departed);
    return e;
}

// 打印
void print(SqQueue *p)
{
    ElemType r;
    while ((r = dequeue(p)) != NULL)
    {
        printf("%c\t", r);
    }
    printf("\n");
}

// 释放
void desotry(SqQueue *p)
{
    while (dequeue(p) != NULL)
    {
    }
}