#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full. Cannot push item.\n");
    }
    else
    {
        stack->data[++stack->top] = item;
    }
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop item.\n");
        return -1; // 返回一个特殊值表示栈为空
    }
    else
    {
        return stack->data[stack->top--];
    }
}

bool isProperSequence(int n, int sequence[], int str[], int strLen)
{
    Stack stack;
    initializeStack(&stack);

    int seqIndex = 0; // 用于遍历输入序列
    int strIndex = 0; // 用于遍历判断序列

    while (strIndex < strLen)
    {
        if (!isEmpty(&stack) && stack.data[stack.top] == str[strIndex])
        {
            // 如果栈顶元素与判断序列当前元素相等，执行出栈操作
            pop(&stack);
            strIndex++;
        }
        else if (seqIndex < n)
        {
            // 如果还有元素可以入栈，执行入栈操作
            push(&stack, sequence[seqIndex]);
            seqIndex++;
        }
        else
        {
            // 没有元素可以入栈，且栈顶元素与判断序列当前元素不相等
            return false;
        }
    }

    // 如果成功遍历判断序列，且栈为空，说明是一个合适的出栈序列
    return isEmpty(&stack);
}

int main()
{
    int n = 5;
    int sequence[] = {1, 2, 3, 4, 5};
    int str1[] = {4, 5, 3, 2, 1}; // 合适的出栈序列
    int str2[] = {4, 3, 5, 1, 2}; // 不合适的出栈序列

    int strLen = n;

    if (isProperSequence(n, sequence, str1, strLen))
    {
        printf("str1 is a proper out-of-sequence.\n");
    }
    else
    {
        printf("str1 is not a proper out-of-sequence.\n");
    }

    if (isProperSequence(n, sequence, str2, strLen))
    {
        printf("str2 is a proper out-of-sequence.\n");
    }
    else
    {
        printf("str2 is not a proper out-of-sequence.\n");
    }

    return 0;
}
