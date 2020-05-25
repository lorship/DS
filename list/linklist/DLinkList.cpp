//
// Created by lord on 2020/5/10. 双链表
//
#include <iostream>

using namespace std;

#define ElemType int

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;  //前驱和后继指针
} DNode, *DLinkList;

bool InitDLinkList(DLinkList &list) {
    list = (DNode *) malloc(sizeof(DNode));
    if (list == NULL) {
        return false;
    }
    list->next = NULL;
    list->prior = NULL;
    return true;
}

/**
 * 在p结点之后插入s结点
 * @param p
 * @param s
 * @return
 */
bool InsertNextNode(DNode *p, DNode *s) {

    if (p == NULL || s == NULL) {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;

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
    if (tmp->next == NULL) {
        return false;
    }
    node->next = tmp->next;
    if (tmp->next != NULL) {
        tmp->next->prior = node;
    }
    free(tmp);
    return true;
}

/**
 * 销毁链表
 * @param list
 */
void DestoryList(DLinkList &list) {
    while (list->next != NULL) {
        DeleteNextNode(list);
    }
    free(list); //释放头节点
    list = NULL;    //头指针指向null
}

int main() {

    DLinkList list;
    InitDLinkList(list);

    return 0;
}

