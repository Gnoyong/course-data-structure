#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 20

typedef char ElemType;
typedef struct
{
    ElemType data[MAX_SIZE];
    int top;
} SqStack;

// 初始化
SqStack *init()
{
    SqStack *p = (SqStack *)malloc(sizeof(SqStack));
    p->top = 0;
    return p;
}

// 进栈
bool push(SqStack *p, ElemType e)
{
    if (p->top > MAX_SIZE)
        return false;
    p->data[p->top] = e;
    p->top++;
    return true;
}

// 出栈
ElemType pop(SqStack *p)
{
    if (p->top == 0)
        return NULL;
    p->top--;
    return p->data[p->top];
}

// 判空
bool isEmpty(SqStack *p)
{
    return p->top == 0;
}

// 打印
void print(SqStack *p)
{
    while (!isEmpty(p))
    {
        printf("%c\t", pop(p));
    }
    printf("\n");
}

// 释放
void desotry(SqStack *p)
{
    free(p);
}