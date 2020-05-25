//
// Created by lord on 2020/4/12.
//

#include <iostream>

using namespace std;
#define InitSize 16
#define ElemType int
typedef struct {
    ElemType *data;
    int maxSize;
    int length;
} SeqList;

/**
 * 初始化
 * @param list
 */
void InitList(SeqList &list) {
    list.data = (ElemType *) malloc(sizeof(ElemType) * InitSize);
    list.maxSize = InitSize;
    list.length = 0;
}

/**
 * 扩容
 * @param list 扩容表
 * @param len   扩容长度
 */
void IncreaseSize(SeqList &list, int len) {
    ElemType *pList = list.data;
    list.data = (ElemType *) malloc(sizeof(ElemType) * (len + list.length));
    list.maxSize = list.maxSize + len;
    for (int i = 0; i < list.length; ++i) {
        list.data[i] = pList[i];
    }
    free(pList);
}

/**
 * 在i处插入元素elem
 * @param list
 * @param i 从1开始
 * @param elem
 */
bool ListInsert(SeqList &list, int i, ElemType elem) {
    if (i < 1 || i > list.length + 1) {
        return false;
    }
    if (i >= list.maxSize) {
        return false;
    }
    for (int j = list.length; j >= i; j--) {
        list.data[j] = list.data[j - 1];
    }
    list.data[i - 1] = elem;
    list.length++;

    return true;
}

/**
 * 删除元素并返回
 * @param list
 * @param i 要删除的元素的位置
 * @param elem 删除的元素
 * @return
 */
bool ListDelete(SeqList &list, int i, ElemType &elem) {
    if (i < 1 || i > list.length) {
        return false;
    }
    elem = list.data[i - 1];
    for (int j = i; j < list.length; ++j) {
        list.data[j - 1] = list.data[j];
    }
    list.length--;
    return true;
}

ElemType GetElem(SeqList list, int i) {
    return list.data[i - 1];
}

/**
 * 定位元素
 * @param list
 * @param elem
 * @return 索引
 */
int LocateElem(SeqList list, ElemType elem) {
    for (int i = 0; i < list.length; ++i) {
        if (list.data[i] == elem) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    SeqList list;
    InitList(list);
    bool insertFlag = ListInsert(list, 1, 3);

    ElemType elem;
    bool deleteFlag = ListDelete(list, 1, elem);
    return 0;
}

