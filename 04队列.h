#include<iostream>
#include<cmath>
#include<algorithm>

#define maxcSize 50
#define initSize 100
#define elemType int


// 顺序队列定义(队尾指向最后一个元素下一个)
typedef struct SqQueue{
    elemType data[maxcSize];
    int front;
    int rear;
}SqQueue;


// 顺序队列的初始化
void initSqQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}


// 顺序队列判空
bool isEmpty(SqQueue &Q){
    return Q.front == Q.rear;
}


// 顺序队列入队
bool enQueue(SqQueue &Q, elemType e){
    if((Q.rear+1)/maxcSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)/maxcSize;
    return true;
}


// 顺序队列出队
elemType deQueue(SqQueue &Q){
    if(Q.front == Q.rear)
        return -1;
    Q.front = (Q.front+1)/maxcSize;
    return Q.data[Q.front-1];    
}



// 链队列定义
typedef struct QNode{
    elemType data;
    struct QNode* next;
}QNode;
typedef struct LinkQueue{
    QNode* front;
    QNode* rear;
}LinkQueue;


// 链队列初始化
void initLinkQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    //Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    Q.front->next = NULL;
}


// 链队列判空
bool isEmpty2(LinkQueue &Q){
    return Q.front == Q.rear;
}


// 链队列入队
void enLinkQueue(LinkQueue &Q, elemType e){
    QNode *t = new QNode;
    t->data = e;
    t->next = NULL;
    Q.rear->next = t;
    Q.rear = t;
}


// 链队列出队
elemType deLinkQueue(LinkQueue &Q){
    if(Q.front == Q.rear)
        return -1;
    QNode* t = Q.front->next;
    Q.front->next = t->next;
    if(Q.rear == t)
        Q.rear = Q.front;
    elemType x = t->data;
    free(t);
    return x;
}