#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int data[MAX_SIZE];
    int front; // 队头指针
    int rear;  // 队尾指针
} CircularQueue;

void initializeQueue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isQueueEmpty(CircularQueue *queue)
{
    return queue->front == -1;
}

bool isQueueFull(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(CircularQueue *queue, int item)
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

int dequeue(CircularQueue *queue)
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

// 删除循环队列中的所有奇数元素
void deleteOddElements(CircularQueue *queue)
{
    CircularQueue tempQueue;
    initializeQueue(&tempQueue);

    while (!isQueueEmpty(queue))
    {
        int item = dequeue(queue);
        if (item % 2 == 0)
        {
            enqueue(&tempQueue, item);
        }
    }

    // 将tempQueue中的元素弹回原队列
    while (!isQueueEmpty(&tempQueue))
    {
        enqueue(queue, dequeue(&tempQueue));
    }
}

int main()
{
    CircularQueue queue;
    initializeQueue(&queue);

    // 向循环队列中添加一些元素
    for (int i = 1; i <= 10; i++)
    {
        enqueue(&queue, i);
    }

    // 删除所有奇数元素
    deleteOddElements(&queue);

    // 打印删除后的队列元素
    printf("Queue after deleting odd elements: ");
    while (!isQueueEmpty(&queue))
    {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
