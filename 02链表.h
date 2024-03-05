#include<iostream>
#include<cmath>
#include<algorithm>

#define elemType int
#define maxcSize 50

// 单链表的定义
typedef struct LNode{
    elemType data;
    struct LNode* next;
}LNode, *LinkList;


// 单链表的初始化(带头节点)
void initList(LinkList &L){
    L = new LNode;
    //L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
}
// // 单链表的初始化(不带头节点)
// void initList(LinkList &L){
//     L = NULL;
// }


// 尾插法建立单链表
void creatListT(LinkList &L, elemType a[], int n){
    L = new LNode;
    L->next = NULL;
    LNode* s;   //新节点
    LNode* r = L;   //尾指针
    for(int i = 0; i < n; i++){
        s = new LNode;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}


// 头插法建立单链表
void creatListH(LinkList &L, elemType a[], int n){
    L = new LNode;
    L->next = NULL;
    LNode* s;   //新节点
    for(int i = 0; i < n; i++){
        s = new LNode;
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}


// 链表求表长(单双通用)
template <class Node>
int getLenth(Node &L){
    int len = 0;
    Node temp = L;
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


// 链表按序号查找(单双通用)
template <class Node>
Node getElem(Node &L, int i){
    Node temp = L;
    while(temp->next != NULL && i-- > 0)
        temp = temp->next;
    return temp;
}


// 链表按值查找(单双通用)
template <class Node>
Node findElem(Node &L, elemType e){
    Node temp = L;
    temp->data  = NULL;
    while(temp->next != NULL && temp->data != e)
        temp = temp->next;
    return temp;
}


// 单链表插入节点
void insertElem1(LinkList &L, int i, elemType e){
    LNode* node = getElem(L, i);
    LNode* newnode = new LNode;
    newnode->data = node->data; //深拷贝
    newnode->next = node->next;
    node->next = newnode;
    node->data = e;
    return;
}


// 单链表删除节点
void deleteElem1(LinkList &L, int i){
    LNode* node = getElem(L, i);
    LNode* temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    free(temp);
    return;
}


// 打印链表(单双通用)
template <class Node>
void printList(Node &L){
    Node temp = L->next;
    while(temp->next != NULL){
        std::cout << temp->data;
        temp = temp->next;
    }
}


// 单链表原地逆置
void reverse(LinkList &L){
    LNode* begin = L->next;
    LNode* end = L->next->next;
    while(end->next != NULL){
        begin->next = end->next;
        end->next = L->next;
        L->next = end;
        end = begin->next;
    }
}


// 双链表的定义
typedef struct DNode{
    elemType data;
    struct DNode* prior;
    struct DNode* next;
}DNode, *DLinkList;


// 双链表的初始化(带头节点)
void initDList(DLinkList &L){
    L = new DNode;
    //L = (DNode*)malloc(sizeof(DNode));
    L->prior = NULL;
    L->next = NULL;
}


// 尾插法建立双链表
void creatDListT(DLinkList &L, elemType a[], int n){
    L = new DNode;
    L->prior = NULL;
    L->next = NULL;
    DNode* s;   //新节点
    DNode* r = L;   //尾指针
    for(int i = 0; i < n; i++){
        s = new DNode;
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}


// 头插法建立双链表
void creatDListH(DLinkList &L, elemType a[], int n){
    L = new DNode;
    L->prior = NULL;
    L->next = NULL;
    DNode* s;   //新节点
    for(int i = 0; i < n; i++){
        s = new DNode;
        s->data = a[i];
        if(L->next != NULL)
            L->next->prior = s;
        s->next = L->next;
        L->next = s;
        s->prior = L;
    }
}


// 双链表插入节点
void insertElem2(DLinkList &L, int i, elemType e){
    DNode* node = getElem(L, i);
    DNode* newnode = new DNode;
    newnode->data = e;
    newnode->next = node->next;
    if(node->next != NULL)
        node->next->prior = newnode;
    newnode->prior = node;
    node->next = newnode;
    return;
}


// 双链表删除节点
void deleteElem2(DLinkList &L, int i){
    DNode* node = getElem(L, i);
    DNode* temp = node;
    if(node->next != NULL)
        node->next->prior = node->prior;
    node->prior->next = node->next;
    free(temp);
    return;
}



// 静态链表的定义
typedef struct{
    elemType data;
    int next;
} SLinkList[maxcSize];
