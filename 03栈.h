#include<iostream>
#include<cmath>
#include<algorithm>

#define maxcSize 50
#define initSize 100
#define elemType int

// 顺序栈的定义
typedef struct SqStack{
    elemType data[maxcSize];
    int top;  
};

// 快速写法
// int stack[maxcSize]; int top = -1;  
// stack[++top] = x;
// x = stack[top--];


// 顺序栈初始化
void initStack(SqStack &S){
    S.top = -1;
}


// 顺序栈的判空
bool isEmpty(SqStack &S){
    return S.top == -1;
}


// 顺序栈进栈
bool push(SqStack &S, elemType e){
    if(S.top == maxcSize)
        return false;
    S.data[S.top + 1] = e;
    S.top++;
    return true;
}


// 顺序栈出栈
elemType pop(SqStack &S){
    if(S.top == -1)
        return NULL;
    S.top--;
    return S.data[S.top + 1];
}


// 读栈顶元素
elemType getTop(SqStack &S){
    if(S.top == -1)
        return NULL;
    return S.data[S.top + 1];
}



// 链栈结点定义
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode , *LinkStack; 


// 链栈初始化
void initLinkStack(LinkStack &S){
    S = new LNode;
    //S = (LNode*)malloc(sizeof(LNode));
    S->next = NULL;
}


// 链栈的判空
bool isEmpty2(LinkStack &S){
    return S->next == NULL;
}


// 链栈进栈
bool push2(LinkStack &S, elemType e){
    LNode* t = new LNode;
    t->next = NULL;
    t->data = e;
    t->next = S->next;
    S->next = t;
}


// 链栈出栈
elemType pop2(LinkStack &S){
    if(S->next == NULL)
        return NULL;
    elemType ans = S->next->data;
    LNode* t = S->next;
    S->next = t->next;
    free(t);
    return ans;
}


// 读栈顶元素