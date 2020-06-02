//
// Created by lordship on 2020/6/2.链栈
//
#include <iostream>

using namespace std;

#define ElemType int
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} *LinkStack;


/**
 * 初始化栈
 * @param stack
 */
void InitStack(LinkStack &linkStack) {
    linkStack->next = NULL;
}

/**
 * 压栈
 * @param linkStack
 * @param elem
 * @return
 */
bool Push(LinkStack &linkStack, ElemType elem) {
    LinkNode *node = (LinkNode *) malloc(sizeof(LinkNode));
    node->data = elem;
    node->next = linkStack;
    linkStack = node;
    return true;
}

/**
 * 弹栈
 * @param linkStack
 * @param elem
 * @return
 */
bool Pop(LinkStack &linkStack, ElemType &elem){
    if (linkStack == NULL){
        return false;
    }
    elem = linkStack->data;
    linkStack = linkStack->next;
    return true;
}

/**
 * 获取栈顶元素
 * @param stack
 * @param elem
 * @return
 */
bool GetTop(LinkStack linkStack, ElemType &elem) {
    if (linkStack == NULL) {
        return false;
    }
    elem = linkStack->data;
    return true;
}

int main() {
    LinkStack linkStack = NULL;

    Push(linkStack, 1);
    Push(linkStack, 2);
    Push(linkStack, 3);

    ElemType elem;
    Pop(linkStack, elem);
    Push(linkStack, 10);
    GetTop(linkStack, elem);
    return 0;
}