#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front; // 队头指针
    int rear;  // 队尾指针
} Queue;

typedef struct
{
    int data[MAX_SIZE];
    int top; // 栈顶指针
} Stack;

void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(Queue *queue)
{
    return queue->front == -1;
}

bool isQueueFull(Queue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue *queue, int item)
{
    if (isQueueFull(queue))
    {
        printf("Queue is full. Cannot enqueue item.\n");
    }
    else
    {
        if (isQueueEmpty(queue))
        {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = item;
    }
}

int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1; // 返回一个特殊值表示队列为空
    }
    else
    {
        int item = queue->data[queue->front];
        if (queue->front == queue->rear)
        {
            // 队列中只有一个元素，将队列重置为空
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

bool isStackEmpty(Stack *stack)
{
    return stack->top == -1;
}

bool isStackFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int item)
{
    if (isStackFull(stack))
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
    if (isStackEmpty(stack))
    {
        printf("Stack is empty. Cannot pop item.\n");
        return -1; // 返回一个特殊值表示栈为空
    }
    else
    {
        return stack->data[stack->top--];
    }
}

// 逆转队列中的所有元素
void reverseQueue(Queue *queue)
{
    Stack stack;
    initializeStack(&stack);

    // 将队列中的元素推入栈中
    while (!isQueueEmpty(queue))
    {
        push(&stack, dequeue(queue));
    }

    // 将栈中的元素弹回队列
    while (!isStackEmpty(&stack))
    {
        enqueue(queue, pop(&stack));
    }
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    // 向队列中添加一些元素
    for (int i = 1; i <= 5; i++)
    {
        enqueue(&queue, i);
    }

    // 逆转队列
    reverseQueue(&queue);

    // 打印逆转后的队列元素
    printf("Reversed Queue: ");
    while (!isQueueEmpty(&queue))
    {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
