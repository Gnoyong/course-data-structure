#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push item.\n");
    } else {
        stack->data[++stack->top] = item;
    }
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop item.\n");
        return -1; // 返回一个特殊值表示栈为空
    } else {
        return stack->data[stack->top--];
    }
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No item to peek.\n");
        return -1; // 返回一个特殊值表示栈为空
    } else {
        return stack->data[stack->top];
    }
}

// 删除栈中所有元素e并保持其他元素次序不变
void deleteElement(Stack* stack, int e) {
    Stack tempStack;
    initializeStack(&tempStack);

    while (!isEmpty(stack)) {
        int topElement = pop(stack);
        if (topElement != e) {
            push(&tempStack, topElement);
        }
    }

    // 将辅助栈的元素弹回原栈
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    // 压入一些元素到栈中
    for (int i = 1; i <= 5; i++) {
        push(&stack, i);
    }

    push(&stack, 3); // 添加一个重复的元素

    // 删除元素3
    deleteElement(&stack, 3);

    // 打印栈中的元素
    printf("Stack elements after deleting 3: ");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}
