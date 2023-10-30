#include "liqueue.cpp"
#include <stdio.h>

SqQueue *queue = init();

void menu();

int main()
{
    char option;
    menu();
    while ((option = getchar()) != '5')
    {
        printf("你选择了 %c\n", option);
        getchar();
        switch (option)
        {
        case '1':
        {
            char id;
            printf("输入病号：", id);
            scanf("%c", &id);
            getchar();
            printf("病号 %c 入队\n", id);
            enqueue(queue, id);
            break;
        }
        case '2':
        {
            printf("病人 %c 就诊\n", dequeue(queue));
            break;
        }
        case '3':
        {
            print(queue);
            break;
        }
        case '4':
        {
            print(queue);
            return 0;
        }
        default:
            break;
        }
        menu();
    }
    return 0;
}

void menu()
{
    printf("1:排队——输入排队病人的病历号，加入病人排队队列中。\n");
    printf("2:就诊——病人排队队列中最前面的病人就诊，并将其从队列中删除。\n");
    printf("3:查看排队——从队首到队尾列出所有排队病人的病历号。\n");
    printf("4:不再排队，余下依次就诊——从队首到队尾列出所有排队病人的病历号，并退出运行。\n");
    printf("5:下班——退出运行\n");
}