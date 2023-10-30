#include "sqstack.cpp"

int main()
{
    SqStack *p = init();
    printf("it is %s that the stack is empty\n", isEmpty(p) ? "ture" : "false");
    push(p, 'a');
    push(p, 'b');
    push(p, 'c');
    push(p, 'd');
    push(p, 'e');
    print(p);
    printf("it is %s that the stack is empty\n", isEmpty(p) ? "ture" : "false");
    desotry(p);
    return 0;
}