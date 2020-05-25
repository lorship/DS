//
// Created by lord on 2020/4/13.
//

#include <iostream>

using namespace std;

#define ElemType int
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;
//Node强调用的是一个节点，LinkList强调用的是一个链表

/**
 * 初始化不带头节点的链表
 * @param linkList
 * @return
 */
bool InitListWithoutHead(LinkList linkList) {
    linkList = NULL;
    return true;
}

/**
 * 插入数据
 * @param list  要插入数据的链表
 * @param elem  要插入的元素
 * @param i     位置
 * @return
 */
bool ListInsert(LinkList &list, ElemType elem, int i) {
    if (i < 1) {
        return false;
    }
    if (i == 1) {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = elem;
        temp->next = list;
        list = temp;
        return true;
    }
    Node *curNode = list;
    int index = 0;  //当前指向的是第几个结点

    while (curNode != NULL && index < i - 1) {  //循环找到第i-1个结点
        curNode = curNode->next;
        index++;
    }
    if (curNode == NULL) {
        return false;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = elem;
    temp->next = curNode->next;
    curNode->next = temp;
    return true;
}

bool IsEmpty(LinkList linkList) {
    return (linkList == NULL);
}

int main() {
    LinkList list;
    InitListWithoutHead(list);
    ListInsert(list, 1, 1);
    return 0;
}

