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
 * 初始化带头节点
 * @param linkList
 * @return
 */
bool InitListWithHead(LinkList &linkList) {
    linkList = (Node *) malloc(sizeof(Node));
    if (linkList == NULL) {
        return false;
    }
    linkList->next = NULL;
    return true;
}


/**
 * 获取指定结点
 * @param list
 * @param index
 * @return
 */
Node* GetElem(LinkList list, int index){
    if (index < 0){
        return NULL;
    }
    Node *ret = list;
    int i = 0;
    while (list != NULL && i < index){
        ret = ret->next;
        i++;
    }

    return ret;
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
    /*Node *curNode = list;
    int index = 0;  //当前指向的是第几个结点

    while (curNode != NULL && index < i - 1) {  //循环找到第i-1个结点
        curNode = curNode->next;
        index++;
    }*/
    Node *curNode = GetElem(list, i-1);
    if (curNode == NULL) {
        return false;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = elem;
    temp->next = curNode->next;
    curNode->next = temp;
    return true;
}

/**
 * 在node结点后插入元素 头插法
 * @param node
 * @param elem
 * @return
 */
bool InsertNextNode(Node *node, ElemType elem) {
    Node *temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) {
        return false;
    }
    temp->data = elem;
    temp->next = node->next;
    node->next = temp;
    return true;
}

/**
 * 在node结点前插入元素
 * @param node
 * @param elem
 * @return
 */
bool InsertPriorNode(Node *node, ElemType elem) {
    if (node == NULL) {
        return false;
    }
    Node *temp = (Node *) malloc(sizeof(Node));
    if (temp == NULL) {
        return false;
    }
    temp->data = node->data;
    temp->next = node->next;

    node->data = elem;
    node->next = temp;
    return true;
}

/**
 * 删除结点
 * @param list
 * @param i 要删除的位置
 * @param elem
 * @return
 */
bool ListDelete(LinkList &list, int i, ElemType &elem) {
    if (i < 1) {
        return false;
    }
   /* Node *curNode = list;
    int index = 0;
    while (curNode != NULL && index < i - 1) {
        curNode = curNode->next;
        index++;
    }*/

   Node *curNode = GetElem(list, i-1);

    if (curNode == NULL || curNode->next == NULL) {
        return false;
    }
    elem = curNode->next->data;
    curNode->next = curNode->next->next;
    return true;
}

/**
 * 删除指定结点
 * @param node
 * @return
 */
bool DeleteNode(Node *node){
    if (node == NULL){
        return false;
    }
    node->data = node->next->data;
    if (node->next->next == NULL){
        return false;
    }
    node->next = node->next->next;
    return true;
}

Node* LocateElem(LinkList list, ElemType elem){
    Node *temp = list->next;
    while (temp != NULL && temp->data != elem){
        temp = temp->next;
    }
    return temp;
}

bool IsEmpty(LinkList linkList) {
    return linkList->next == NULL;
}

void ShowList(LinkList list) {
    if (list == NULL) {
        return;
    }
    while (list!=NULL){
        cout << list->data << "\t";
        list = list->next;
    }
    cout << endl;
}
/**
 * 头插法
 * @param list
 * @return
 */
LinkList  List_HeadInsert(LinkList &list){
    Node *tmp = (LinkList)malloc(sizeof(Node));
    tmp->next = NULL;
    ElemType elem;
    cout << "插入的元素 : ";
    cin >> elem;
    while (elem != 2333){
        tmp->data = elem;
        tmp->next = list->next;
        list->next = tmp;
        cout << "插入的元素 : ";
        cin >> elem;
    }
    return list;
}

/**
 * 尾插法插入数据 每插入一个结点，就将表尾指针　指向新结点
 * @param list
 * @return
 */
LinkList List_TailInsert(LinkList &list){
    ElemType elem;

    cout << "插入的元素 : ";
    cin >> elem;
    list = (LinkList)malloc(sizeof(Node));
    //tailNode 表尾指针，　temp 新插入的结点
    Node *tailNode = list, *temp;

    while (elem != 2333){
        temp = (Node*)malloc(sizeof(Node));
        temp->data = elem;
        tailNode->next = temp;
        tailNode = temp;

        cout << "插入的元素 : " ;
        cin >> elem;
    }
    tailNode->next = NULL;
    return list;
}


int main() {
    LinkList list;
    InitListWithHead(list);
    for (int i = 1; i < 12; ++i) {
        ListInsert(list, rand(), i);
    }

    ShowList(list);

    InsertPriorNode(list->next, 21);
    ShowList(list);

    InsertNextNode(list->next, 22);
    ShowList(list);

    ElemType elem;
    ListDelete(list, 5, elem);
    ShowList(list);

    DeleteNode(list->next);
    ShowList(list);

    Node *node = GetElem(list, 3);
    cout << "第" << 3 << "个结点：" << node->data << endl;

    node = LocateElem(list, 22);
    cout << "元素22的结点：" << node->data<< endl;

    List_TailInsert(list);
    ShowList(list);
    return 0;
}