#include "sqqueue.cpp"

int main()
{
    SqQueue *queue = init();
    printf("it is %s that the queue is empty\n", isEmpty(queue) ? "ture" : "false");
    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    printf("%c\n", dequeue(queue));
    enqueue(queue, 'd');
    enqueue(queue, 'e');
    enqueue(queue, 'f');
    printf("it is %s that the queue is empty\n", isEmpty(queue) ? "ture" : "false");
    print(queue);
    desotry(queue);
    return 0;
}