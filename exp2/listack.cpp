#include <stdio.h>
#include <malloc.h>

typedef char ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkNode;

// 初始化
LinkNode *init()
{
    LinkNode *top = NULL;
    return top;
}

// 进栈
void push(LinkNode *&top, ElemType e)
{
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = e;
    p->next = top;
    top = p;
}

// 判空
bool isEmpty(LinkNode *p)
{
    return p == NULL;
}

// 出栈
ElemType dequeue(LinkNode *&top)
{
    if (isEmpty(top))
        return NULL;
    LinkNode *p = top;
    ElemType data = p->data;
    top = p->next;
    free(p);
    return data;
}

// 打印
void print(LinkNode *&p)
{
    while (!isEmpty(p))
    {
        printf("%c\t", dequeue(p));
    }
    printf("\n");
}

// 释放
void desotry(LinkNode *p)
{
    while (dequeue(p) != NULL)
    {
    }
}