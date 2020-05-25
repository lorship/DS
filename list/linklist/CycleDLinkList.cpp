//
// Created by lord on 2020/5/22. 循环双链表
//

#include <iostream>

using namespace std;

#define ElemType int

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

/**
 * 初始化循环双链表
 * @param list
 * @return
 */
bool InitDLinkList(DLinkList &list) {
    list = (DNode *) malloc(sizeof(DNode));
    if (list == NULL) {
        return false;
    }
    list->prior = list;
    list->next = list;
    return true;
}

/**
 * 判断链表是否为空
 * @param list
 * @return
 */
bool Empty(DLinkList list) {
    if (list->next == list) {
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
bool IsTail(DLinkList list, DNode *node) {
    if (node->next == list) {
        return true;
    }
    return false;
}

/**
 * 在p结点之后插入s结点
 * @param p
 * @param S
 * @return
 */
bool InsertNextDNode(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

/**
 * 删除node结点的后继结点
 * @param node
 * @return
 */
bool DeleteNextNode(DNode *node) {

    if (node == NULL) {
        return false;
    }
    DNode *tmp = node->next;
    node->next = tmp->next;
    tmp->next->prior = node;
    free(tmp);
    return true;
}