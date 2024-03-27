#include"04队列.h"
#include"03栈.h"


// 带有tag的顺序队列定义
typedef struct tagQueue{
    elemType data[maxcSize];
    int front;
    int rear;
    bool tag;
}tagQueue;

void inittagQueue(tagQueue &Q){
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 1;
}

bool enTagQueue(tagQueue &Q, elemType e){
    if((Q.rear+1)/maxcSize == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)/maxcSize;
    Q.tag = 0;
    return true;
}

elemType deTagQueue(tagQueue &Q){
    if(Q.front == Q.rear)
        return -1;
    Q.front = (Q.front+1)/maxcSize;
    Q.tag = 1;
    return Q.data[Q.front-1];    
}


void fun2(SqQueue &Q, SqStack &S){
    elemType e;
    while(!isEmpty(Q)){
        e = deQueue(Q);
        push(S, e);
    }
    while(!isEmpty(S)){
        e = pop(S);
        enQueue(Q, e);
    }
}


void EnQueue(){
    
}