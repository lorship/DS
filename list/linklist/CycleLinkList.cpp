//
// Created by lord on 2020/5/22.　循环单链表
//
#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

/**
 * 初始化循环单链表
 * @param list
 * @return
 */
bool InitList(LinkList &list){
    list = (LNode*)malloc(sizeof(LNode));
    if (list == NULL){
        return false;
    }
    list->next = list;  //头节点next指向头节点
    return true;
}

/**
 * 判断链表是否为空
 * @param list
 * @return
 */
bool Empty(LinkList list){
    if (list->next == list){
        return true;
    }
    return false;
}

/**
 * 判断node结点是否是list的表尾
 * @param list
 * @param node
 * @return
 */
bool IsTail(LinkList list, LNode *node){
    if (node->next == list){
        return true;
    }
    return false;
}


