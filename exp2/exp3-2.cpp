#include "listack.cpp"

int main()
{
    LinkNode *top = init();
    printf("it is %s that the stack is empty\n", isEmpty(top) ? "ture" : "false");
    push(top, 'a');
    push(top, 'b');
    push(top, 'c');
    push(top, 'd');
    push(top, 'e');
    print(top);
    printf("it is %s that the stack is empty\n", isEmpty(top) ? "ture" : "false");
    desotry(top);
    return 0;
}