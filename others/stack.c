#include <stdio.h>
#include <stdbool.h>

#define M 10
#define N 30

typedef struct
{
    int data[N];
    int top; // 栈顶指针
} Stack;

// 初始化栈
void initializeStack(Stack *stack)
{
    stack->top = N;
}

// 判断栈是否为空
bool isEmpty(Stack *stack)
{
    return stack->top == N;
}

// 判断栈是否已满
bool isFull(Stack *stack)
{
    return stack->top == M;
}

// 压栈操作
void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push item.\n");
    }
    else
    {
        stack->data[--stack->top] = item;
    }
}

// 出栈操作
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop item.\n");
        return -1; // 返回一个特殊值表示栈为空
    }
    else
    {
        return stack->data[stack->top++];
    }
}

// 查看栈顶元素
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. No item to peek.\n");
        return -1; // 返回一个特殊值表示栈为空
    }
    else
    {
        return stack->data[stack->top];
    }
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    // 将一些元素压入栈
    for (int i = 1; i <= 20; i++)
    {
        push(&stack, i);
    }

    // 弹出栈顶元素
    printf("Pop: %d\n", pop(&stack)); // 输出: Pop: 20

    // 查看栈顶元素
    printf("Peek: %d\n", peek(&stack)); // 输出: Peek: 19

    // 检查栈是否为空
    printf("Is Empty: %s\n", isEmpty(&stack) ? "true" : "false"); // 输出: Is Empty: false

    // 检查栈是否已满
    printf("Is Full: %s\n", isFull(&stack) ? "true" : "false"); // 输出: Is Full: false

    return 0;
}
