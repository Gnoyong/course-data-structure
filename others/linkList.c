/*
 可以引入的库和版本相关请参考 “环境说明”
*/
#include <stdio.h>

/*
  以下为示例代码，仅供参考。请根据题目要求定义好方法及参数。
  The following is sample code for reference only.
  Please define the methods and parameters according to the requirements of the question.
*/
typedef struct node
{
    int value;
    struct node *next;
} Node;

void append(Node *a, Node *b)
{
    Node *e = a;
    while (e->next != NULL)
    {
        e = e->next;
    }
    e->next = b;
}

int getLength(Node *pHead)
{
    Node *p = pHead;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void bubbleSort(Node *head)
{
    int swapped;
    Node *current;
    Node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != lptr)
        {
            if (current->value > current->next->value)
            {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);
}

Node *findPre(Node *pHead, Node *target)
{
    Node *p = pHead;
    while (p->next != NULL)
    {
        if (p->next == target)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void print(Node *L)
{
    Node *p = L;

    while (p != NULL)
    {
        printf("%d", p->value);
        p = p->next;
        if (p != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

Node *createList(int size)
{
    Node *h = (Node *)malloc(sizeof(Node));
    scanf("%d", &h->value);
    Node *p = h;
    for (int i = 0; i < size - 1; i++)
    {
        Node *n = (Node *)malloc(sizeof(Node));
        p->next = n;
        p = n;
        scanf("%d", &n->value);
    }
    p->next = NULL;
    return h;
}

int main()
{
    Node *a = createList(5);
    Node *b = createList(4);
    append(a, b);
    bubbleSort(a);
    print(a);
    return 0;
}
