//
// Created by lordship on 2020/6/1. 顺序栈
//
#include <iostream>

using namespace std;

#define MaxSize 10
#define ElemType int
typedef struct {
    ElemType data[MaxSize];
    int top;
} SeqStack;

/**
 * 初始化栈
 * @param stack
 */
void InitStack(SeqStack &stack) {
    stack.top = -1;
}

/**
 * 压栈
 * @param stack
 * @param elem
 * @return
 */
bool Push(SeqStack &stack, ElemType elem) {
    if (stack.top == MaxSize - 1) {
        return false;   //栈满
    }
    stack.top = stack.top + 1;
    stack.data[stack.top] = elem;
    return true;
}

/**
 * 出栈
 * @param stack
 * @return
 */
bool Pop(SeqStack &stack, ElemType &elem) {
    if (stack.top == -1) {
        return false;   //栈空
    }
    elem = stack.data[stack.top--];
    return true;
}

/**
 * 获取栈顶元素
 * @param stack
 * @param elem
 * @return
 */
bool GetTop(SeqStack stack, ElemType &elem) {
    if (stack.top == -1) {
        return false;
    }
    elem = stack.data[stack.top];
    return true;
}

int main(int count, char *argv[]) {

    SeqStack stack;
    InitStack(stack);
    return 0;
}

