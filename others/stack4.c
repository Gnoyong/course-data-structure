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

// 删除循环队列中从队头开始的第k个元素
void deleteKthElement(CircularQueue *queue, int k)
{
    if (k <= 0 || k > (queue->rear - queue->front + 1))
    {
        printf("Invalid value of k.\n");
        return;
    }

    // 将前k-1个元素出队并重新入队，相当于删除第k个元素
    for (int i = 1; i < k; i++)
    {
        int item = dequeue(queue);
        enqueue(queue, item);
    }

    // 出队第k个元素（相当于删除它）
    dequeue(queue);
}

int main()
{
    CircularQueue queue;
    initializeQueue(&queue);

    // 向循环队列中添加一些元素
    for (int i = 1; i <= 5; i++)
    {
        enqueue(&queue, i);
    }

    int k = 3;
    printf("Original Queue: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", dequeue(&queue));
        enqueue(&queue, i + 1);
    }
    printf("\n");

    // 删除第k个元素
    deleteKthElement(&queue, k);

    // 打印删除后的队列元素
    printf("Queue after deleting %dth element: ", k);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", dequeue(&queue));
        enqueue(&queue, i + 2);
    }
    printf("\n");

    return 0;
}
