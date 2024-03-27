#include<iostream>
#include<cmath>
#include<algorithm>

#define maxcSize 50
#define initSize 100
#define elemType int

// 静态分配的定义
typedef struct SqList{
    elemType data[maxcSize];
    int length;
}SqList;
    
// 快速写法
// int A[macxSize];
// int n;

// 静态分配的初始化
void initSqList(SqList &L){
    L.length = 0;
}

// 动态分配的定义
typedef struct SeqList
{
    elemType *data;
    int maxSize;
    int length;
}SeqList;

// 动态分配的初始化
void initSeqList(SeqList &L){
    L.data = new elemType[initSize];
    // L.data = (elemType*)malloc(sizeof(elemType)*initSize);
    L.length = 0;
    L.maxSize = initSize;
}

// 动态分配的销毁
void destorySeqList(SeqList &L){
    // L.data = (elemType*)realloc(L.data, 0);
    free(L.data);
}

// 动态分配增加长度
void increaseSeqList(SeqList &L, int len){
    L.maxSize += len;
    elemType* temp = L.data;
    L.data = (elemType*)malloc(sizeof(elemType)*L.maxSize);
    for(int i = 0; i < L.length; i++){
        L.data[i] = temp[i];
    }
    free(temp);
}


// 获取表长
int getLenth(SeqList &L){
    return L.length;
}

// 判断空表
bool isEmpty(SeqList &L){
    if(L.length == 0)
        return 1;
    return 0;
}

// 打印表
int printList(SeqList &L){
    for(int i = 0; i < L.length; i++){
        std::cout << L.data[i];
        //printf("%d", L.data[i])
    }
}

// 元素插入操作
bool insertElem(SeqList &L, int p, elemType e){
    if(p < 1 || p > L.length + 1 || L.length >= L.maxSize)
        return false;
    int i;
    for(i = L.length; i > p; i--)
        L.data[i] = L.data[i-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 元素删除操作
bool deleteElem(SeqList &L, int p, elemType &e){
    if(p < 1 || p > L.length)
        return false;
    e = L.data[p-1];
    for(int i = p; i < L.length; i++)
        L.data[i-1] = L.data[i];
    L.length--;
    return true;
}

// 元素按位查找
elemType getElem(SeqList &L, int p){
    if(p < 0 || p >= L.length)
        return 0;
    return L.data[p-1];
}

// 元素按值查找
int findElem(SeqList &L, elemType e){
    for(int i = 0; i < L.length; i++){
        if(L.data[i] == e)
            return i + 1;
    }
    return -1;
}

// 逆置线性表
void reverse(SeqList &L, int start, int end){
    for(int i = start -1 ; i < end / 2; i++){
        elemType temp = L.data[i];
        L.data[i] = L.data[end - 1 - i];
        L.data[end - 1 - i] = temp;
    }
}