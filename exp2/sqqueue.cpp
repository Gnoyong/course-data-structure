#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 6

typedef char ElemType;
typedef struct
{
    ElemType data[MAX_SIZE];
    int front;
    int rear;
} SqQueue;

// 初始化
SqQueue *init()
{
    SqQueue *q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = 0;
    q->rear = 0;
    return q;
}

// 判空
bool isEmpty(SqQueue *p)
{
    return p->front == p->rear;
}

bool isFull(SqQueue *p)
{
    return (p->rear + 1) % MAX_SIZE == p->front;
}

// 进队
bool enqueue(SqQueue *p, ElemType e)
{
    if (isFull(p))
    {
        return false;
    }
    p->data[p->rear] = e;
    p->rear = (p->rear + 1) % MAX_SIZE;
    return true;
}

// 出队
ElemType dequeue(SqQueue *p)
{
    if (isEmpty(p))
        return NULL;
    ElemType e = p->data[p->front];
    p->front = (p->front + 1) % MAX_SIZE;
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
    free(p);
}