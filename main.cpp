#include <iostream>
using namespace std;

#define MaxSize 20

typedef struct
{
    /* data */
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &list){
    for (int i = 0; i < MaxSize; i++)
    {
        list.data[i] = 0;
    }
    list.length = 0;
}

int main(int count, char *argv[]){

    SqList list;
    InitList(list);

    cout << list.length << endl;
    return 0;
}
